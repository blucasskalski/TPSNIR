//
//  modbus.h
//  
//
//  Created by maylaender patrick on 10/10/2018.
//

#ifndef MODBUS_H
#define MODBUS_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
extern int sock_CLIENT;  //socket client
/* fonction de conversion int to float en decimal */
float int2floatdec( unsigned int futureF);

/* fonction de conversion float en decimal to int x */
int float2int(float f);

/* envoi requete de lecture modbus sur serveur                                                 */
/* parametre : entree unsigned short adresse du registre modbus                                */
/* retour -1.0 : erreur : valeur lue (float codé en 4 octets unsigned int) : si OK             */

float lecture(unsigned short key);

/* envoi requete de ecriture modbus sur serveur                         */
/* parametre1 : entree unsigned short adresse du registre modbus        */
/* parametre2 : entree float valeur a ecrire dans registre              */
/* retour -1 : erreur : 0 : si OK            				*/

int ecriture(unsigned short key, float val);

#endif /* MODBUS_H */
