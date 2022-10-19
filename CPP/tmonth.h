/*--------------------------------------------------------------------------
 *  Nom         :   tmonth.h
 *  Type        :   INTERFACE
 *  Sujet       :   énumeration des mois pour TMonth
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :
 *--------------------------------------------------------------------------
 */
#ifndef TMONTH_H
#define TMONTH_H

typedef enum { JAN=1, FEV, MAR, AVR, MAI, JUI, JUL, AOU, SEP, OCT, NOV, DEC } TMonth ;

#endif

const char* strMonth(TMonth month);

