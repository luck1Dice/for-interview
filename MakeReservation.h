#ifndef MAKE_RESERVATION_H
#define MAKE_RESERVATION_H

#include "Transaction.h"

class MakeReservation : public Transaction
{
public:
   MakeReservation( string userIDNumber, ReservationDatabase &theReservationDatabase,
                    AvailBoxes &theAvailBoxes );
   virtual void execute(); // make reservation

private:
   int inputBranchCode( bool available[] );
};

#endif // MAKE_RESERVATION_H