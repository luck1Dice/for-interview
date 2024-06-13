// Member-function definitions for class ViewCancelReservation.
#include <iostream>
#include <iomanip>
using namespace::std;

#include "ViewCancelReservation.h"

extern int inputAnInteger( int begin, int end );

ViewCancelReservation::ViewCancelReservation( string userIDNumber,
                                              ReservationDatabase &theReservationDatabase,
                                              AvailBoxes &theAvailBoxes )
   : Transaction( userIDNumber, theReservationDatabase, theAvailBoxes )
{
}

// reservation enquiry/canceling
void ViewCancelReservation::execute()
{
   ReservationDatabase &reservationDatabase = getReservationDatabase();

   if( reservationDatabase.empty() )
   {
      cout << "\nNo reservations!\n";
      return;
   }

   if( !reservationDatabase.exist( getIDNumber() ) )
   {
      cout << "\nYou have no reservations!\n";
      return;
   }

   int numReservations = reservationDatabase.displayReservationInfo( getIDNumber() );

   int choice;
   cout << endl;
   do cout << "Choose a reservation to cancel (0: keep all reservations): ";
   while( ( choice = inputAnInteger( 0, numReservations ) ) == -1 );

   if( choice > 0 )
   {
      int branchCode;
      int dateCode;
      int startingHour;
      int numHours;
      reservationDatabase.cancelReservation( getIDNumber(), choice, branchCode, dateCode, startingHour, numHours );
      getAvailBoxes().increase( branchCode, dateCode, startingHour, numHours );

      cout << "\nReservation Cancelled!\n";
   }
}