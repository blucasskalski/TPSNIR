#include "tmonth.h"

char mm[12][10] =
{
  "janvier",
  "février",
  "mars",
  "avril",
  "mai",
  "juin",
  "juillet",
  "aout",
  "septembre",
  "octobre",
  "novembre",
  "décembre"
} ;

const char*strMonth(TMonth month )
{
  if(month >= 0 && month <= 12)
  {
    return mm[ month - 1 ] ;
  }
  return 0;
}
