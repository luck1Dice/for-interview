// Date.h
// Date class definition.
#ifndef DATA_H
#define DATA_H

#include <ostream>
using std::ostream;

class Date
{
   friend ostream& operator<<( ostream &, const Date & );
public:
   Date( int y = 2000, int m = 0, int d = 0 );
   const Date& operator=( const Date &right ); // assignment operator
   void setDate( int y, int m, int d ); // set month, day, year
   void setYear( int y );
   void setMonth( int m );
   void setDay( int d );
   int getYear() const;
   int getMonth() const;
   int getDay() const;
   bool operator==( const Date &date2 );
   bool operator<( const Date &date2 );
   bool operator<=( const Date &date2 );
   bool leapYear( int theYear ) const;
   int operator-( const Date &date2 );
   Date operator+( int numDays );

private:
	int year;
	int month;
   int day;
};

#endif // DATA_H