/*--------------------------------------------------------------------------
 *  Nom         :   cdate.h
 *  Type        :   INTERFACE
 *  Sujet       :   Définition de la classe CDATE
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :
 *--------------------------------------------------------------------------
 */
#ifndef CDATE_H
#define CDATE_H

#include "tmonth.h"
#include <string>
#include <ostream>

class CDate {
	private:
		unsigned	day;
		unsigned	month;
		unsigned	year;

	public:
		CDate(){set(1, JAN, 1900);}

		CDate(unsigned day, TMonth month, unsigned year){
			set(day, month, year);
		}

		TMonth	getMonth() const;
		void	setMonth(TMonth month);


		unsigned getDay() const;
		void setDay(unsigned day);

		unsigned getYear() const;
		void setYear(unsigned year);

		void set(unsigned day, TMonth month, unsigned year);
		std::string print() const;
		std::string printLong() const;
};
std::ostream& operator << (std::ostream& s, const CDate& date);
#endif

