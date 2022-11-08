/*--------------------------------------------------------------------------
 *  Nom         :   tmonth.cpp
 *  Type        :   APPLICATION
 *  Sujet       :   Définition du tableau des mois pour TMonth
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :
 *--------------------------------------------------------------------------
 */
#include "tmonth.h"

char mm[12][10] = {"janvier",   "février", "mars",     "avril",
                   "mai",       "juin",    "juillet",  "aout",
                   "septembre", "octobre", "novembre", "décembre"};

const char *strMonth(TMonth month) {
  if (month >= 0 && month <= 12) {
    return mm[month - 1];
  }
}
