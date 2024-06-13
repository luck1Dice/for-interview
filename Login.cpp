// Member-function definitions for class Login.
#include <iostream>
#include <string>
using namespace::std;

#include "Login.h"
#include "Transaction.h"
#include "MakeReservation.h"
#include "ViewCancelReservation.h"

extern int inputAnInteger( int begin, int end );

Login::Login( MemberDatabase &theMemberDatabase, ReservationDatabase &theReservationDatabase,
              AvailBoxes &theAvailBoxes )
   : memberDatabase( theMemberDatabase ),
     reservationDatabase( theReservationDatabase ),
     availBoxes( theAvailBoxes ),
     currentIDNumber( "" ) // no current ID number to start
{
}

void Login::execute()
{
   cout << "\nEnter your ID number: ";
   string IDNumber;
   cin >> IDNumber;
   cin.ignore();

   if( !memberDatabase.exist( IDNumber ) )
   {
      cout << "\nYou are not a member!\n";
      return;
   }

   cout << "\nEnter your password: ";
   string password;
   cin >> password;
   cin.ignore();

   // check whether authentication succeeded
   if( !memberDatabase.authenticateUser( IDNumber, password ) )
   {
      cout << "\nInvalid password!\n";
      return;
   }

   currentIDNumber = IDNumber; // save user's ID #
   performTransactions(); // user is now authenticated 
   currentIDNumber = "";
}

// display the submenu and perform transactions
void Login::performTransactions()
{
   // local pointer to store transaction currently being processed
   Transaction *currentTransactionPtr;

   bool userExited = false; // user has not chosen to exit
   int choice;

   // loop while user has not chosen option to exit system
   while( !userExited )
   {
      // show submenu and get user selection
      cout << "\n1 - Make Reservation\n";
      cout << "2 - Reservation Enquiry/Canceling\n";
      cout << "3 - End\n\n";

      do cout << "Enter your choice (1~3): ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );

      // decide how to proceed based on user's menu selection
      switch( choice )
      {
         // user chose to perform one of three transaction types
         case 1:
            currentTransactionPtr = new MakeReservation( currentIDNumber, reservationDatabase, availBoxes );

            currentTransactionPtr->execute(); // execute transaction

            // free the space for the dynamically allocated Transaction
            delete currentTransactionPtr;
            
            break; 
         case 2:
            // initialize as new object of chosen type
            currentTransactionPtr = new ViewCancelReservation( currentIDNumber, reservationDatabase, availBoxes );

            currentTransactionPtr->execute(); // execute transaction

            // free the space for the dynamically allocated Transaction
            delete currentTransactionPtr;
            
            break; 
         case 3: // user chose to terminate session
            userExited = true; // this ATM session should end
            break;
         default: // user did not enter an integer from 1-4
            cout << "\nIncorrect choice!" << endl;
            break;
      }
   }
}