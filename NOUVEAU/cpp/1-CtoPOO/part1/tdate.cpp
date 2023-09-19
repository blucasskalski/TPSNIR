#include "tdate.h"
#include <iostream>
using namespace std ;

TMonth getMonth(TDate* date )
{
  return date->month ;
}

void setMonth(TDate* date, TMonth month )
{
  if ( month < JAN )month = JAN ;
  if ( month > DEC )month = DEC ;
  date->month = month ;
  getMonth(date);
}

int getDay(TDate* date)
{
  return date->day;
}

void setDay(TDate* date, int j)
{
  if(j >= 31) j = 31;
  if(j <= 0) j = 1;
  date->day=j;
  //  getDay(date);
}

int getYear(TDate* date)
{
  return date->year;
}

void setYear(TDate* date, int a)
{
  if(a > 4000) a = 4000;
  if(a < 0) a = 0;
  date->year=a;
}

void setDate(TDate* date, unsigned j, TMonth month, unsigned a )
{
  setMonth(date, (TMonth)month);
  setDay(date, j);
  setYear(date, a);
}
