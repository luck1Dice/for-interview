// Member-function definitions for class Registration.
#include <iostream>
using namespace::std;

#include "Registration.h"

Registration::Registration( MemberDatabase &theMemberDatabase )
   : memberDatabase( theMemberDatabase )
{
}

void Registration::execute()
{
   cout << "\nInput your ID Number: ";
   string IDNumber;
   cin >> IDNumber;
   cin.ignore();

   if( memberDatabase.exist( IDNumber ) )
   {
      cout << "\nYou are already a member!\n";
      return;
   }

   cout << "\nInput your Name: ";
   string name;
   cin >> name;

   cout << "\nChoose a password: ";
   string password;
   cin >> password;
   cin.ignore();

   MemberInfo newMember( IDNumber, name, password );

   memberDatabase.pushBack( newMember );

   cout << "\nRegistration Completed!\n";
}