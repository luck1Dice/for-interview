#ifndef RESERVATION_DATABASE_H
#define RESERVATION_DATABASE_H

#include <vector>
#include "Reservation.h"

class ReservationDatabase
{
public:
   ReservationDatabase();
   ~ReservationDatabase();

   bool empty(); // returns true if the ReservationDatabase is empty

   // returns true if the ReservationDatabase has a reservation containing specified IDNumber
   bool exist( string IDNumber );

   // returns true if IDNumber has no reservations
   // which are within six hours from the specified hour
   bool allowed( string IDNumber, Date date, int hour );

   // display all reservation informations containing specified IDNumber;
   // and returns the number of reservations containing specified IDNumber
   int displayReservationInfo( string IDNumber );

   // cancels the n-th Reservation object containing specified IDNumber
   void cancelReservation( string IDNumber, int n,
                           int &branchCode, int &date, int &startingHour, int &numHours );

   // add an element at the end of reservations
   void pushBack( Reservation newReservation );

private:
   vector< Reservation > reservations; // Vector of the Party World's reservations

   void loadReservations(); // loads reservations from the file ReservationInfo.dat
   void saveReservations(); // stores reservations into the file ReservationInfo.dat
};

#endif