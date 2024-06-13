#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace::std;

#include "ReservationDatabase.h"
#include "AvailBoxes.h"

class Transaction
{
public:
   Transaction( string userIDNumber, ReservationDatabase &theReservationDatabase,
                AvailBoxes &theAvailBoxes )
      : IDNumber( userIDNumber ),
        reservationDatabase( theReservationDatabase ),
        availBoxes( theAvailBoxes )
   {
   }

   virtual ~Transaction() // virtual destructor with empty body
   {
   }

   // return IDNumber
   string getIDNumber() const
   {
      return IDNumber;
   }

   // return reference to ReservationDatabase
   ReservationDatabase& getReservationDatabase() const
   {
      return reservationDatabase;
   }

   // return reference to AvailBoxes
   AvailBoxes& getAvailBoxes() const
   {
      return availBoxes;
   }

   // pure virtual function to perform the transaction
   virtual void execute() = 0; // overridden in derived classes

private:
   string IDNumber; // ID number
   ReservationDatabase& reservationDatabase; // reference to the reservationDatabase
   AvailBoxes &availBoxes;
};

#endif // TRANSACTION_H