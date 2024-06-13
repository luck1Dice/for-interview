#include <iostream>
#include <iomanip>
#include <fstream>
#include<cmath>
using namespace std;

#include "AvailBoxes.h"

extern int computeCurrentDate( Date &currentDate );

AvailBoxes::AvailBoxes()
{
   loadNumAvailBoxes();

   Date currentDate;

   computeCurrentDate( currentDate );

   /**/cout << startingDate.getYear() << "/"
      << startingDate.getMonth() << "/"
      << startingDate.getDay() << endl;

   int days;
   if (startingDate < currentDate ) {
       days = 8 - (currentDate - startingDate);
   }

   for (int j = 1; j < 19; j++) {
       for (int i = days; i < 8; i++) {
           for (size_t k = 0; k < 24; k++)
           {
               numAvailBoxes[j][i][k] = totalnumAvailBoxes;
           }       
       }
   }
   
   for( int branch = 1; branch <= 18; branch++ )
      for( int k = 1; k < 8; k++ )
      {
         for( int i = 0; i <= 23; i++ )
            cout << setw( 4 ) << numAvailBoxes[ branch ][ k ][ i ];
         cout << endl;
      }
}

AvailBoxes::~AvailBoxes()
{
   saveNumAvailBoxes();
}

bool AvailBoxes::available( int branchCode, int date, int startingHour, int numHours )
{
    int hours;
    for (int i = 0; i < numHours; i++)
    {
        hours = numHours + i;
        if ( hours >= 24) {
            hours %= 24;
            date++;
        }
        if (numAvailBoxes[branchCode][date][startingHour + i] <= 0)
            return false;
    }
    return true;
}

void AvailBoxes::decrease( int branchCode, int date, int startingHour, int numHours )
{
    for (int i = 0; i < numHours; i++)
    {
        numAvailBoxes[branchCode][date][startingHour + i]--;
    }
}

void AvailBoxes::increase( int branchCode, int date, int startingHour, int numHours )
{
    for (int i = 0; i < numHours; i++)
    {
        numAvailBoxes[branchCode][date][startingHour + i]++;
    }
}

void AvailBoxes::loadNumAvailBoxes()
{
    
    Date today;
    computeCurrentDate(today);
    Date data_today;
    int numavailable[19][8][24];
    int noneed[19][8][24];
    int year,month,day;
    ifstream myfile("NumAvailBoxes.txt");
    if (!myfile) {
        std::cerr << "無法打開文件！" << std::endl;
        return;
    } 
    myfile >> year >> month >> day;
    startingDate.setDate(year, month, day);
    int days = 0;
    if (startingDate < today)
        days = (today - startingDate );
    while (true) {
        if (myfile.eof())
            break;
        //myfile >> branch >> year >> month >> day >> hour >> numHours >> numCustomers;
      
       for (int i = 1; i < 19; i++) {    
           int data_days = 1;
           for (int j = 1 ; j < 8;j++){  
               if (j <= days) {
                   for (int k = 0; k < 24; k++) {
                       myfile >>noneed[i][j][k];
                   }
               }
               else {
                   for (int k = 0; k < 24; k++) { // is there have better way
                       myfile >> numAvailBoxes[i][data_days][k];
                   }
                   data_days++;
               }
              
           }
       }
       break;
    }
    myfile.close();
}

void AvailBoxes::saveNumAvailBoxes()
{
    ofstream outfile;
    outfile.open("NumAvailBoxes.txt");
    if (!outfile) {
        std::cerr << "無法打開文件！" << std::endl;
        return;
    }
    outfile << startingDate.getYear() << " "<< startingDate.getMonth()<<" "<<startingDate.getDay()<<endl;
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 8; j++) {
            for (int k = 0; k < 24; k++) { // is there have better way ?
                outfile << "   " << numAvailBoxes[i][j][k];
            }
            outfile << endl;
        }
    }
    outfile.close();
}