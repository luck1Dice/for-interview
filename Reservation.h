#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using std::string;

#include "Date.h"

class Reservation
{
public:
   Reservation( string theIDNumber = "", int theBranch = 0, Date theDate = Date(),
                int theHour = 0, int theNumHours = 0, int theNumCustomers = 0 );
   void setIDNumber( string theIDNumber );
   void setBranch( int theBranch );
   void setDate( Date theDate );
   void setHour( int theHour );
   void setNumHours( int theNumHours );
   void setNumCustomers( int theCustomerNumber );
   string getIDNumber();
   int getBranch();
   Date getDate();
   int getHour();
   int getNumHours();
   int getNumCustomers();

   // displays branch, date, hour, numCustomers
   void displayReservationInfo();
private:
   char IDNumber[ 12 ];	// account number
   int branch;   // branch code
   Date date = Date();  // reservation date
   int hour;            // reservation hour
   int numHours;
   int numCustomers;    // number of customers
};

#endif