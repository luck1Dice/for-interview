#ifndef LOGIN_H
#define LOGIN_H

#include "ReservationDatabase.h"
#include "MemberDatabase.h"
#include "AvailBoxes.h"

class Login
{
public:
   Login( MemberDatabase &theMemberDatabase, ReservationDatabase &theReservationDatabase,
          AvailBoxes &theAvailBoxes );
   void execute(); // start the Login
private:
   string currentIDNumber; // current user's ID number
   MemberDatabase &memberDatabase; // member information database
   ReservationDatabase &reservationDatabase; // reservation information database
   AvailBoxes &availBoxes;

   void performTransactions(); // display the submenu and perform transactions
};

#endif