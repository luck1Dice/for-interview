#ifndef VIEW_CANCEL_RESERVATION_H
#define VIEW_CANCEL_RESERVATION_H

#include "Transaction.h"

class ViewCancelReservation : public Transaction
{
public:
   ViewCancelReservation( string userIDNumber,
                          ReservationDatabase &theReservationDatabase,
                          AvailBoxes &theAvailBoxes );

   virtual void execute(); // reservation enquiry/canceling
};

#endif // VIEW_CANCEL_RESERVATION_H