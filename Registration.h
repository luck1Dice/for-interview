#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "ReservationDatabase.h"
#include "MemberDatabase.h"

class Registration
{
public:
   Registration( MemberDatabase &theMemberDatabase );
   void execute(); // start the Registration
private:
   MemberDatabase &memberDatabase; // member information database
};

#endif