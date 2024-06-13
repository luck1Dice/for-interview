// Date.cpp
// Date-function definitions for class Date.
#include <iostream>
#include <iomanip>
using namespace std;

#include "Date.h"

int days[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // array of days per month

Date::Date( int y, int m, int d )
{
   setDate( y, m, d );
}

// const return avoids: ( a1 = a2 ) = a3
const Date& Date::operator=( const Date &right )
{
   if( &right != this ) // avoid self-assignment
   {
      year = right.year;
      month = right.month;
      day = right.day;
   }

   return *this; // enables x = y = z, for example
}

void Date::setDate( int y, int m, int d )
{
   setYear( y );
   setMonth( m );
   setDay( d );
}

void Date::setYear( int y )
{
   year = ( y >= 2000 ) ? y : 2000;
}

void Date::setMonth( int m )
{
   month = ( m >= 1 && m <= 12 ) ? m : 1;
}

void Date::setDay( int d )
{
   if( month == 2 && leapYear( year ) )
      day = ( d >= 1 && d <= 29 ) ? d : 1;
   else
      day = ( d >= 1 && d <= days[ month ] ) ? d : 1;
}

int Date::getYear() const
{
   return year;
}

int Date::getMonth() const
{
   return month;
}

int Date::getDay() const
{
   return day;
}

bool Date::operator==( const Date &date2 )
{
   return ( year == date2.year && month == date2.month && day == date2.day );
}

bool Date::operator<( const Date &date2 )
{
    /* if (year < date2.getYear())
        return true;
    if (month < date2.getMonth()) // now year >= date2.year
        return true;
    if (day < date2.getDay())// now year >= dat2.year && month >= date2.month
        return true;*/

    // faster
    if (year < date2.getYear())
        return true;
    if (year > date2.getYear())
        return false;

    if (month < date2.getMonth())
        return true;
    if (month > date2.getMonth())
        return false;

    if (day < date2.getDay())
        return true;
    if (day > date2.getDay())
        return false;

    return false;
}

bool Date::operator<=( const Date &date2 )
{
   return ( *this < date2 || *this == date2 );
}

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear( int theYear ) const
{
   return ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) );
}

// return *this - date2 provided that *this >= date2
int Date::operator-( const Date &date2 )
{
    // confuse me
    if (month > date2.getMonth()) {
        if (leapYear(year) && date2.getMonth() == 2) {
            return 29 - date2.getDay() + day;
        }
        return days[date2.getMonth()] - date2.getDay() + day;
    }

    return day - date2.getDay();
} 

Date Date::operator+( int numDays )
{
    day += numDays;
    while (true) {
        // Adjust for leap year in February
        if (month == 2 && leapYear(year)) {
            if (day > 29) {
                day -= 29;
                month++;
            }
            else {
               continue;
            }
        }
        else if (day > days[month]) {
            day -= days[month];
            month++;
        }
        else {
            break;
        }

        // Adjust for end of year
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    Date buffer;
    buffer.setDate(year, month, day);
    return buffer;
}

ostream& operator<<( ostream &output, const Date &d )
{
   output << setfill( '0' ) << d.year << "/" << setw( 2 ) << d.month
                                      << '/' << setw( 2 ) << d.day;
   output << setfill( ' ' );
   return output; // enables cascading
}