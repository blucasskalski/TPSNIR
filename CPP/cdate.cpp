/*--------------------------------------------------------------------------
 *  Nom         :   cdate.cpp
 *  Type        :   UTILITAIRE
 *  Sujet       :   Fonctions dédiées à la classe CDate
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :
 *--------------------------------------------------------------------------
 */
#include "cdate.h"
#include <sstream>
#include <iomanip>

TMonth CDate::getMonth() const{
	return (TMonth)month;
}

void CDate::setMonth(TMonth month){
	if(month<JAN) month = JAN;
	if(month>DEC) month = DEC;
	this->month = (unsigned)month;
}

unsigned CDate::getDay() const{
	return (unsigned)day;
}
void CDate::setDay(unsigned day){
	if(day<0) day = 0;
	if(day>31) day = 31;
	this->day = day;
}

unsigned CDate::getYear() const{
	return (unsigned)year;
}
void CDate::setYear(unsigned year){
	if(year<0) year = 0;
	if(year>2022) year = 2022;
	this->year = year;
}

void CDate::set(unsigned day, TMonth month, unsigned year){
	this->day = day;
	this->month = (unsigned)month;
	this->year = year;
}

std::string CDate::print() const{
	std::ostringstream	oss;

	oss << std::setfill('0');
	oss << std::setw(2) << day << '/';
	oss << std::setw(2) << month << '/';
	oss << std::setw(4) << year;
	return oss.str();
}

std::string CDate::printLong() const{
	std::ostringstream	oss;

	oss << std::setfill('0');
	oss << std::setw(2) << day << ' ';
	oss << std::setw(2) << strMonth(getMonth()) << ' ';
	oss << std::setw(4) << year;
	return oss.str();
}

std::ostream& operator << (std::ostream& s, const CDate& date){
	s << date.print();
	return s;
}
