#ifndef MEMBERINFO_H
#define MEMBERINFO_H

#include <string>
using std::string;

class MemberInfo
{
public:
   MemberInfo( string theIDNumber = "", string theName = "", string thePassword = "" );

   void setIDNumber( string theIDNumber );
   string getIDNumber() const;

   void setName( string theName );
   string getName() const;

   void setPassword( string thePassword );
   string getPassword() const;

   // returns true if and only if userPassword correct
   bool validatePassword( string userPassword ) const;
private:
   char IDNumber[ 12 ]; // ID number
   char name[ 8 ];      // name
   char password[ 24 ]; // password
};

#endif