/*--------------------------------------------------------------------------
 *  Nom         :   tdate.cpp
 *  Type        :   UTILITAIRE
 *  Sujet       :   Fonctions dédiées d'accès à TDate
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :
 *--------------------------------------------------------------------------
 */
#include "tdate.h"
#include "tmonth.h"
#include "tmonth.h"

TMonth getMonth(TDate* date){
	return date->month;
}

unsigned getYear(TDate* date){
	return date->year;
}

unsigned getDay(TDate* date){
	return date->day;
}

void setDay(TDate* date, unsigned day){
	if ( day < 1 )	day = 1 ;
	if ( day > 31)	day = 31;
	date->day = day;
}

void setMonth(TDate* date, TMonth month){
	if ( month < JAN)	month = JAN ;
	if ( month > DEC)	month = DEC;
	date->month = month;
}

void setYear(TDate* date, unsigned year){
	if ( year < 0 )	year = 0 ;
	if ( year > 2022) year = 2022;
	date->year = year;
}
void setDate(TDate* date, unsigned day, TMonth month, unsigned year){
	date->day = day;
	date->month = month;
	date->year = year;
}
