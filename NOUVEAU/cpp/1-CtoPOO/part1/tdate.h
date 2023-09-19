#ifndef TDATE_H
#define TDATE_H
#include "tmonth.h"
typedef struct {
  unsigned day ;
  TMonth month ;
  unsigned year ;
} TDate ;
void setMonth(TDate* date, TMonth month );
unsigned getDay() const;
unsigned getYear() const;
void setDay(TDate* date, int j);
void setYear(TDate* date,int a);
void setDate(TDate* date, unsigned day, TMonth month, unsigned year ) ;
int getDay(TDate* date);
int getYear(TDate* date);
#endif
