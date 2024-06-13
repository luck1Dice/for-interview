// Member-function definitions for class MemberInfo.
#include "MemberInfo.h"

MemberInfo::MemberInfo( string theIDNumber, string theName, string thePassword )
{
   setIDNumber( theIDNumber );
   setName( theName );
   setPassword( thePassword );
}

void MemberInfo::setIDNumber( string theIDNumber )
{
   unsigned int length = theIDNumber.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      IDNumber[ i ] = theIDNumber[ i ];
   IDNumber[ length ] = '\0';
}

string MemberInfo::getIDNumber() const
{
   return IDNumber;
}

void MemberInfo::setName( string theName )
{
   unsigned int length = theName.size();
   length = ( length < 8 ? length : 7 );
   for( unsigned int i = 0; i < length; i++ )
      name[ i ] = theName[ i ];
   name[ length ] = '\0';
}

string MemberInfo::getName() const
{
   return name;
}

void MemberInfo::setPassword( string thePassword )
{
   unsigned int length = thePassword.size();
   length = ( length < 24 ? length : 23 );
   for( unsigned int i = 0; i < length; i++ )
      password[ i ] = thePassword[ i ];
   password[ length ] = '\0';
}

string MemberInfo::getPassword() const
{
   return password;
}

// determines whether a user-specified Password matches Password in MemberInfo
bool MemberInfo::validatePassword( string userPassword ) const
{ 
   if ( userPassword == password )
      return true;
   else
      return false;
}