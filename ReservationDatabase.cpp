// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace::std;
#include "ReservationDatabase.h"

extern int computeCurrentDate( Date &currentDate );
extern void computeCurrentHour( Date &currentDate, int &currentHour );

ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

ReservationDatabase::~ReservationDatabase()
{
   saveReservations();
}

bool ReservationDatabase::empty()
{
   return ( reservations.size() == 0 );
}

bool ReservationDatabase::exist( string IDNumber )
{
	Reservation buffer;;
	for (int i = 0; i < reservations.size(); i++) {
		buffer = reservations[i];
		if (buffer.getIDNumber() == IDNumber)
			return true;
	}
	return false;
}
// 
bool ReservationDatabase::allowed( string IDNumber, Date date, int hour )
{
	Reservation buffer,compare;
	Date compare_date = date;
	int num = 0;
	for (int i = 0; i < reservations.size(); i++) {
		buffer = reservations[i];
		compare = buffer;
		if (buffer.getIDNumber() == IDNumber ) {
			for (int j = 0; j < 6; j++) {
				if (hour + j >= 24) {
					compare.setDate(compare_date + 1);
					compare_date =buffer.getDate();
				}
				if ((hour + j) % 24 == buffer.getHour() && compare.getDate() == date) {
					compare.setDate(buffer.getDate());
					return false;
				}
				if (buffer.getHour() - j <= 0)
				{
					compare.setDate(compare_date - 1);
					compare_date =buffer.getDate();
				}
				if (abs(hour - j) % 24 == buffer.getHour() && compare.getDate() == date) {
					compare.setDate(buffer.getDate());
					return false;
				}
			}			
		}
	}
	return true;
}

int ReservationDatabase::displayReservationInfo( string IDNumber )
{
   cout << endl << setw( 25 ) << "Branch"
                << setw( 14 ) << "Date" << setw( 8 ) << "Hour"
                << setw( 19 ) << "No of Customers" << endl;

   int count = 0;
   vector< Reservation >::iterator it;
   for( it = reservations.begin(); it != reservations.end(); ++it )
      if( it->getIDNumber() == IDNumber )
      {
         cout << ++count << ". ";
         it->displayReservationInfo();
      }

   return count;
}

void ReservationDatabase::cancelReservation( string IDNumber, int n,
                                             int &branchCode, int &dateCode, int &startingHour, int &numHours )
{
   Date currentDate;
   computeCurrentDate( currentDate );
   Reservation buffer;
    
   int num = 0;
   for (int i = 0; i < reservations.size(); i++) {
	   buffer = reservations[i];
	   if (buffer.getIDNumber() == IDNumber)
		   num++;
	   if (buffer.getIDNumber() == IDNumber && num ==n)
	   {
		   branchCode = buffer.getBranch();
		   dateCode = buffer.getDate().getDay();
		   startingHour = buffer.getHour();
		   numHours = buffer.getNumHours();
		   reservations.erase(reservations.begin() + i);
	   }
   }

}

void ReservationDatabase::pushBack( Reservation newReservation )
{
   reservations.push_back( newReservation );
}

void ReservationDatabase::loadReservations()
{
	fstream myfile("ReservationInfo.dat", std::ios::in | std::ios::binary);
	myfile.seekp(0, ios::beg);
	if (!myfile) {
		std::cerr << "無法打開文件！" << std::endl;
		return;
	}
	Reservation buffer;
    while (true) {
        if (myfile.eof())
            break;
        //myfile >> branch >> year >> month >> day >> hour >> numHours >> numCustomers;
        myfile.read(reinterpret_cast<char*>(&buffer), sizeof(Reservation));
        reservations.emplace_back(buffer);
    }
	myfile.close();

}

void ReservationDatabase::saveReservations()
{
	Reservation buffer;
	fstream outfile;
	outfile.open("ReservationInfo.dat", ios::out | ios::binary);
	if (!outfile) {
		std::cerr << "無法打開文件！" << std::endl;
		return;
	}	
	for (int i = 0; i < reservations.size(); i++) {
		outfile.write(reinterpret_cast<char*> (&reservations[i]), sizeof(Reservation));
	}
	
	outfile.close();

}