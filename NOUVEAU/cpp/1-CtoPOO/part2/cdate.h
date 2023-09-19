#ifndef CDATE_H
#define CDATE_H
#include "tmonth.h"
#include <string>
#include <ostream>

class CDate {
private:
  unsigned day;
  unsigned month;
  unsigned year;
  public :
  CDate() { setdate(1, JAN, 1900) ; }
  CDate(unsigned day, TMonth month, unsigned year)
  {
    setdate(day, month, year) ;
  }
  TMonth getMonth() const;
  unsigned getDay() const;
  unsigned getYear() const;
  void setMonth(TMonth month);
  void setdate(unsigned day, TMonth month, unsigned year) ;
  void setDay(int j);
  void setYear(int a);
  std::string printdate() const ;
  std::string printlongdate() const;
} ;
std::ostream& operator << (std::ostream& s, const CDate& date);
#endif
