#ifndef AVAIL_BOXES_H
#define AVAIL_BOXES_H

#include "Date.h"

class AvailBoxes
{
public:
   AvailBoxes();

   ~AvailBoxes();

   bool available( int branchCode, int date, int startingHour, int numHours );

   void decrease( int branchCode, int date, int startingHour, int numHours );

   void increase( int branchCode, int date, int startingHour, int numHours );

private:
   Date startingDate; // the date for numAvailBoxes[][ 1 ][]
   int numAvailBoxes[ 19 ][ 8 ][ 24 ];
   // numAvailBoxes[][][ 0 ] : the number of available boxes at 00:00
   // numAvailBoxes[][][ 1 ] : the number of available boxes at 01:00
   // numAvailBoxes[][][ 23 ] : the number of available boxes at 23:00
   // numAvailBoxes[][ 1 ][] : the number of available boxes on today
   // numAvailBoxes[][ 2 ][] : the number of available boxes on tomorrow
   // numAvailBoxes[][ 3 ][] : the number of available boxes on the day after tomorrow

   const static int totalnumAvailBoxes = 100;

   void loadNumAvailBoxes(); // loads the number of available boxes from the file NumAvailBoxes.txt
   void saveNumAvailBoxes(); // stores the number of available boxes into the file NumAvailBoxes.txt
};

#endif
