#include <iostream>
#include <iomanip>
#include <fstream>
using namespace::std;

#include "Login.h"
#include "Registration.h"

 // input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

// compute current date
int computeCurrentDate( Date &currentDate );

// compute current date and hour
void computeCurrentHour( Date &currentDate, int &currentHour );

//Date computeCurrentHour(); // compute current date
bool leapYear( int year ); // if the year is a leap year, return true; otherwise, return false

int main()
{
   cout << "Welcome to the Cashbox Party World!\n";

   MemberDatabase memberDatabase; // member information database
   ReservationDatabase reservationDatabase; // reservation information database
   AvailBoxes availBoxes;
   Login login( memberDatabase, reservationDatabase, availBoxes );
   Registration registration( memberDatabase );

   bool userExited = false; // user has not chosen to exit
   int choice;

   // loop while user has not chosen option to exit system
   while( !userExited )
   {
      // show main menu and get user selection
      cout << "\n1 - Login";
      cout << "\n2 - Registration";
      cout << "\n3 - End\n\n";

      do cout << "Enter your choice (1~3): ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );

      // decide how to proceed based on user's menu selection
      switch( choice )
      {
         // user chose to perform one of three transaction types
         case 1:
            // create new Login transaction
            login.execute();
            break;
         case 2:
            // create new Registration transaction
            registration.execute();
            break;
         case 3: // user chose to terminate session
            cout << "\nThank you! Goodbye!\n\n";
            userExited = true; // this session should end
            break;
         default: // user did not enter an integer from 1-3
            cout << "\nIncorrect choice!" << endl;
            break;
      }
   }

   system( "pause" );
}

int inputAnInteger( int begin, int end )
{
   char string[ 80 ];
   cin.getline( string, 80, '\n' );

   for( unsigned int i = 0; i < strlen( string ); i++ )
      if( string[ i ] < '0' || string[ i ] > '9' )
         return -1;

   int number = atoi( string );

   if( number >= begin && number <= end )
      return number;
   else
      return -1;
}

int computeCurrentDate( Date &currentDate )
{
   int remainingSeconds = static_cast< int >( time( 0 ) ) + 8 * 60 * 60;

   int year = 1970;

   int secondsPerYear = 365 * 24 * 60 * 60;
   if( leapYear( year ) )
      secondsPerYear += 24 * 60 * 60;

   while( remainingSeconds >= secondsPerYear )
   {
      remainingSeconds -= secondsPerYear;
      year++;

      secondsPerYear = 365 * 24 * 60 * 60;
      if( leapYear( year ) )
         secondsPerYear += 24 * 60 * 60;
   }

   int days[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if( leapYear( year ) )
      days[ 2 ] = 29;

   int month = 1;
   while( remainingSeconds >= days[ month ] * 24 * 60 * 60 )
   {
      remainingSeconds -= days[ month ] * 24 * 60 * 60;
      month++;
   }

   int day = remainingSeconds / ( 24 * 60 * 60 ) + 1;
   remainingSeconds %= 24 * 60 * 60;

   currentDate.setDate( year, month, day );

   return remainingSeconds;
}

void computeCurrentHour( Date &currentDate, int &currentHour )
{
   int remainingSeconds = computeCurrentDate( currentDate );
   currentHour = remainingSeconds / ( 60 * 60 );
}

bool leapYear( int year )
{
   return ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) );
}