#include "cdate.h"
#include <sstream>
#include <iomanip>

TMonth CDate::getMonth() const
{
  return (TMonth)month;
}

unsigned CDate::getDay() const
{
  return day;
}

unsigned CDate::getYear() const
{
  return year;
}


void CDate::setMonth(TMonth month)
{
  if(month < JAN) month = JAN;
  if(month > DEC) month = DEC;
  this->month = (unsigned) month;
}

void CDate::setdate(unsigned day, TMonth month, unsigned year)
{

  if(day >= 31) day = 31;
  if(day <= 0) day = 1;
  this->day=day;

int m = month;
  if(m <= 0) m = 1;
  if(m >= 12) m = 12;
  this->month=m;

  if(year> 4000) year = 4000;
  if(year < 0) year = 0;
  this->year=year;
}

void CDate::setDay(int j)
{
  if(j >= 31) j = 31;
  if(j <= 0) j = 1;
  this->day=j;
  //  getDay(date);
}

void CDate::setYear(int a)
{
  if(a > 4000) a = 4000;
  if(a < 0) a = 0;
  this->year=a;
}

std::string CDate::printdate() const
{
  std::ostringstream oss;
  oss << std::setfill('0');
  oss << std::setw(2) << day << '/';
  oss << std::setw(2) << month << '/';
  oss << std::setw(4) << year;
  return oss.str();
}

std::string CDate::printlongdate() const
{
  std::ostringstream oss;
  oss << std::setfill('0');
  oss << std::setw(2) << day << ' ';
  oss << std::setw(2) << strMonth(TMonth(month)) << ' ';
  oss << std::setw(4) << year;
  return oss.str();
}

std::ostream& operator << (std::ostream& s, const CDate& date )
{
  s << date.printdate() ;
  return s ;
}
