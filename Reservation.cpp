// Member-function definitions for class Reservation.
#include <iostream>
#include <iomanip>
using namespace::std;
#include "Reservation.h"

extern char branchNames[ 19 ][ 24 ];

Reservation::Reservation( string theIDNumber, int theBranch, Date theDate,
                          int theHour, int theNumHours, int theNumCustomers )
   : IDNumber(), 
     branch(),
     date(),
     hour(),
     numHours(),
     numCustomers()
{
   setIDNumber( theIDNumber );
   setBranch( theBranch );
   setDate( theDate );
   setHour( theHour );
   setNumHours( theNumHours );
   setNumCustomers( theNumCustomers );
}

void Reservation::setIDNumber( string theIDNumber )
{
   unsigned int length = theIDNumber.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      IDNumber[ i ] = theIDNumber[ i ];
   IDNumber[ length ] = '\0';
}

void Reservation::setBranch( int theBranch )
{
   branch = ( theBranch >= 1 && theBranch <= 18 ? theBranch : 0 );
}

void Reservation::setDate( Date theDate )
{
   date = theDate;
}

void Reservation::setHour( int theHour )
{
   hour = ( theHour >= 0 && theHour <= 23 ? theHour : 0 );
}

void Reservation::setNumHours( int theNumHours )
{
   numHours = ( theNumHours >= 1 && theNumHours <= 6 ? theNumHours : 0 );
}

void Reservation::setNumCustomers( int theCustomerNumber )
{
   numCustomers = ( theCustomerNumber >= 0 ? theCustomerNumber : 0 );
}

string Reservation::getIDNumber()
{
   return IDNumber;
}

int Reservation::getBranch()
{
   return branch;
}

Date Reservation::getDate()
{
   return date;
}

int Reservation::getHour()
{
   return hour;
}

int Reservation::getNumHours()
{
   return numHours;
}

int Reservation::getNumCustomers()
{
   return numCustomers;
}

void Reservation::displayReservationInfo()
{   
   char numbers[ 24 ][ 4 ] = { "00", "01", "02", "03", "04", "05", "06", "07",
                               "08", "09", "10", "11", "12", "13", "14", "15",
                               "16", "17", "18", "19", "20", "21", "22", "23" };
   cout << setw( 22 ) << branchNames[ branch ]
        << "    " << date
        << setw( 8 ) << numbers[ hour ]
        << setw( 19 ) << numCustomers << endl;
}