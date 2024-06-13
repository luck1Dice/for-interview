// Member-function definitions for class MakeReservation.
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

#include "MakeReservation.h"

char branchNames[ 19 ][ 24 ] = { "", "Taipei Dunhua South",   "Taipei Linsen",
                                    "Taipei Zhongxiao", "Taipei Songjiang",
                                     "Taipei Nanjing",       "Taipei Zhonghua New",
                                     "Banqiao Guanqian",    "Yonghe Lehua",
                                     "Taoyuan Zhonghua",    "Taoyuan Nankan",
                                     "Zhongli Zhongyang",   "Hsinchu Beida",
                                     "Taichung Ziyou",      "Chiayi Ren'ai",
                                     "Tainan Ximen",        "Kaohsiung Zhonghua New",
                                     "Kaohsiung Jianxing",  "Pingtung Kending" };

extern int inputAnInteger( int begin, int end );
extern void computeCurrentHour( Date &currentDate, int &currentHour );

MakeReservation::MakeReservation( string userIDNumber,
                                  ReservationDatabase &theReservationDatabase,
                                  AvailBoxes &theAvailBoxes )
   : Transaction( userIDNumber, theReservationDatabase, theAvailBoxes )
{
}

// make reservation
void MakeReservation::execute()
{
   ReservationDatabase &reservationDatabase = getReservationDatabase();
   Date currentDate,sevendays;
   int currentHour,numHours,which_day,hour, branchCode, numCustomers;
   int branch[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   computeCurrentHour( currentDate, currentHour );
   
   AvailBoxes buffer = getAvailBoxes();
   cout << endl;
   cout << currentDate << " : " << currentHour << endl << endl;
   cout << "Available days:" << endl;
   for (int i = 0; i < 7; i++) {
       sevendays = currentDate;
       cout << i+1 <<". " << sevendays + i << endl;
   }
   cout << endl;
   cout << "Enter your choice (0 to end): ";
   cin >> which_day;
   while (which_day > 7 || which_day < 1) {
       cout << "Can't make reservation on that day";
       for (int i = 0; i < 7; i++) {
           sevendays = currentDate;
           cout << i + 1 << ". " << sevendays + i << endl;
       }
       cout << endl;
       cout << "Enter your choice (0 to end): ";
       cin >> which_day;

   }
   cout << endl;
   cout << "Enter hour (";
   if (which_day == 1)
   {
        cout << currentHour << "~" << 23 << "): ";
   }
   else {
       cout << "0~23): ";
   }
   cin >> hour;
   
   if (which_day == 1) {
       while ( hour < currentHour || 23 < hour)
       {
           cout << "Can't book at that time " << endl;
           cout << endl;
           cout << "Enter hour (";
           cout << currentHour << "~" << 23 << "): ";
           cin >> hour;
           cout << endl;
       }    
   }
   else {
       while (hour < 0 || hour > 23) {
           cout << "Can't book at that time " << endl;
           cout << endl;
           cout << "Enter hour (";
           cout << "0~23): ";
           cin >> hour;
           cout << endl;
       }   
   }
   sevendays = currentDate;
   if (!reservationDatabase.allowed(getIDNumber(),(sevendays + (which_day-1)),hour))
   {
       cout << "You already have a reservation within six hours!" << endl;
       cout << endl;
       execute();
       return;
   }
   cout << endl;
   cout << "How many hours (1~6): ";
   cin >> numHours;

   while (numHours > 6 || numHours < 1)
   {
       cout << "Your book time is too much or less"<<endl;
       cout << endl;
       cout << "How many hours (1~6): ";
       cin >> numHours;
       cout << endl;
   }

   cout << endl;
   for (int i = 1; i < 19; i++) {
       if (buffer.available(i, which_day, hour, numHours)) {
           cout << i << ". " << branchNames[i] << endl;
           branch[i] = 1;
       }           
   }

   cout << endl;
   cout << "Enter your choice (0 to end): ";
   cin >> branchCode;

   int yes = 0;
   while(true) {
       for (int i = 1; i < 19; i++) {
           if (buffer.available(i, which_day, hour, numHours)) {
               if (i == branchCode)
               {
                   yes++;
               }                
           }
       }

       if (yes == 1){
           break;
       }

       cout << "The room is not available" << endl;


       for (int i = 1; i < 19; i++) {
           if (buffer.available(i, which_day, hour, numHours)) {
               cout << i << ". " << branchNames[i] << endl;
               branch[i] = 1;
           }
       }
       cout << endl;
       cout << "Enter your choice (0 to end): ";
       cin >> branchCode;
   }
   cout << endl;

   Date date = currentDate + (which_day-1);

   cout << "Enter the number of customers (1~20, 0 to end): ";
   cin >> numCustomers;

   while (numCustomers > 20 || numCustomers < 1) {
       cout << "number customers aren't right" << endl;
       cout << endl;
       cout << "Enter the number of customers (1~20, 0 to end): ";
       cin >> numCustomers;
   }


   Reservation newReservation( getIDNumber(), branchCode, date, hour, numHours, numCustomers );

   cout << endl << setw( 22 ) << "Branch"
                << setw( 14 ) << "Date" << setw( 8 ) << "Hour"
                << setw( 19 ) << "No of Customers" << endl;

   newReservation.displayReservationInfo();
   cout << "\nReservation Completed!\n";

   reservationDatabase.pushBack( newReservation );
}

int MakeReservation::inputBranchCode( bool available[] )
{
   char string[ 80 ];
   cin.getline( string, 80, '\n' );

   for( unsigned int i = 0; i < strlen( string ); i++ )
      if( string[ i ] < '0' || string[ i ] > '9' )
         return -1;

   int number = atoi( string );

   if( number == 0 )
      return number;

   if( number >= 1 && number <= 18 && available[ number ] )
      return number;
   else
      return -1;
}