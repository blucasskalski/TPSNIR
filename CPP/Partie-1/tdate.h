/*--------------------------------------------------------------------------
 *  Nom         :   tdate.h
 *  Type        :   INTERFACE
 *  Sujet       :   Définition des fonctions pour TDate
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :
 *--------------------------------------------------------------------------
 */
#ifndef TDATE_H
#define TDATE_H

#include "tmonth.h"

typedef struct {
	unsigned	day;
	TMonth		month;
	unsigned	year;
} TDate;

unsigned getDay(TDate* date);
TMonth getMonth(TDate* date);
unsigned getYear(TDate* date);
void setDay(TDate* date, unsigned day);
void setMonth(TDate* date, TMonth month);
void setYear(TDate* date, unsigned year);
#endif

