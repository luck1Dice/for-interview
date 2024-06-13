#ifndef MEMBER_DATABASE_H
#define MEMBER_DATABASE_H

#include <vector>
#include "MemberInfo.h"

class MemberDatabase
{
public:
   MemberDatabase();
   ~MemberDatabase();

   // returns true if userPassword match that of an Account containing userIDNumber
   bool authenticateUser( string userIDNumber, string userPassword );

   // returns true if there is an Account containing userIDNumber
   bool exist( string &userIDNumber );

   void pushBack( MemberInfo &newMember ); // add newMember at the end of members

private:
   vector< MemberInfo > members; // Vector of the members

   void loadFromMemberFile(); // loads members from the file MemberInfo.dat
   void saveToMemberFile();   // stores members into the file MemberInfo.dat
};

#endif