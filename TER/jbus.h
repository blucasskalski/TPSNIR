#ifndef JBUS_H
#define JBUS_H
//PM V2
//20/2/13 Modif gestion parite

#include "rs232.h"
#include <fcntl.h>
#include <unistd.h>
/** \class jbus jbus.cpp jbus.h
 *
 * \author maylaender patrick
 * \date 02/13
 * \brief classe d'exploitation de requetes modbus (mode RTU) sur liaison serie
          Copyright P.Maylaender <a href = "mailto:patrick.maylaender@ac-creteil.fr"> contact: patrick Maylaender </a> <br>
 */

class jbus:public rs232
{
 private :
     /** pointe sur trame generale envoyee */
    unsigned char *trame_JBUS_Cde;
    /**trame de generale recue en reponse */
    unsigned char *trame_JBUS_Rpse;
    
        /** pointe sur valeurs trame envoyee */
        unsigned char valeur_C[256];
        /** pointe sur valeurs trame recue */
        unsigned char valeur_R[256];

	/// calcul du CRC 
        unsigned int crc_chk(unsigned char *data, unsigned char length);
	
       //affichage exception
       void API_Exception_affiche();
  
 public :

     /** \fn jbus(char *line, int b_rate, int nb_bit_data, int n_bit_stop ,int parity_yes_no, int odd_even_ms)
      
        \brief constructeur permettant de creer des objets avec les reglages serie adaptés
        \param [in] char *line : nom port serie "/dev/ttyS0" <=> COM1 , "/dev/ttyUSB0" <=> USB1 
        \param [in] int b_rate : baud rate 9600,19200 etc
        \param [in] int nb_bit_data : nombre de bit de donnees 5,6,7,ou 8
        \param [in] int n_bit_stop : nb bit stop 1, 1,5 , ou 2
        \param [in] int parity_yes_no : parite 'O',1 <=> oui ,  'N', 0 <=> non
        \param [in] int odd_even_ms : type parite : 'o','O','0', 0 <=> IMPAIRE; 'e','E','1',1 <=> PAIRE  */
	
     jbus( char *line , int b_rate , int nb_bit_data ,int n_bit_stop, int parity_yes_no, int odd_even_ms);

     /**************************************************************************************************/
     /** \fn int API_Module_Read_Nbits( unsigned char slave_adress, short adresse_variable_tor, short N)
       \brief methode de lecture de N bits interne sur module esclave
       \param[in]  unsigned char slave_adress  :   Numero du module
       \param[in]  short adresse_variable_tor  :   adresse variable ds API
       \param[in]  short N                     :   Nombre bits à lire
      \return      code d'erreur eventuel -1 NOK O OK
     ***************************************************************************************************/
     int API_Module_Read_Nbits(unsigned char slave_adress, short adresse_variable_tor, short N);

     /******************************************************************************************/
     /** \fn int API_Module_Read_Nwords( unsigned char slave_adress, short adresse_mot, short N )
      \brief methode de lecture de N mots internes sur module esclave
      \param [in]   unsigned char slave_adress    :   Numero du module
      \param [in]   short adresse_mot           :   adresse variable ds API
      \param [in]   short N           :   Nombre mots à lire
     \return        code d'erreur eventuel -1 NOK 0 OK
     *******************************************************************************************/
     int API_Module_Read_Nwords( unsigned char slave_adress, short adresse_mot, short N);

     /********************************************************************************************************/
     /** \fn int API_Module_Write_1word( unsigned char slave_adress, short adresse_variable_tor, short valeur)
     \brief methode d'ecriture de 1 mot  sur un module de l'API
     \param [in]  unsigned char slave_adress    :   Numero du module
     \param [in]  short adresse_variable_tor    :   adresse variable ds API
     \param [in]  short valeur                  :   valeur bits a ecrire
     \return         sortie : code d'erreur eventuel  -1 NOK 0 OK
     *******************************************************************************************************/
     int API_Module_Write_1word( unsigned char slave_adress, short adresse_variable_tor, short valeur);

     //accesseur pour lire  valeur trame commande
     /**********************************************************************/
     /** \fn void read_value_C(unsigned char* res,int n)
      \brief methode pour lire trame reponse en ecriture
      \param [in] unsigned char *res            :   adresse de stockage des valeurs lues
      \param [in] int n                         :   nb d'octets ds trame
     **********************************************************************/
     void read_value_C( unsigned char *res,int n);

     //accesseur pour lire  valeur trame reponse
     /**********************************************************************/
     /** \fn   void read_value_R(unsigned char*res, int n)
      	 \brief methode pour lire trame reponse en lecture
         \param [in]  unsigned char *res           :   adresse de stockage des valeurs lues
         \param [in] int n                         :   nb d'octets ds trame
     **********************************************************************/
     void read_value_R(unsigned char*res,int n);

      
	~jbus();   // code destructeur de liaison serie/usb  
};


#endif

