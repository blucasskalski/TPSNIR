#include <termios.h>
#include <stdlib.h>
#include <sys/ttydefaults.h>
//
/***********************************************/
/* FONCTION POUR liaison serie ss linux        */
/***********************************************/
/* MAJ parite   V2 20/2/13     */
/** \class rs232 rs232.h rs232.cpp
 *
 * \author maylaender patrick
 * \date 02/13
 * \brief classe d'exploitation d'une liaison serie
          Copyright P.Maylaender <a href = "mailto:patrick.maylaender@ac-creteil.fr"> contact: patrick Maylaender </a> <br>
 */
class rs232{


private :
 /** structure termios du pilote */
 struct termios termio_line;
 struct termios old_termio_line;



 protected :
 int h_RS232;/// handle liaison
 int status; /// code retour des methodes
 /*********************************************/
/* constructeur ouverture de port            */
/* description : reserve le port             */
/*    de facon exclusive juste pour le       */
/*   terminal ou process utilisateur         */
/* argument 1 : pilote   ss forme ascii      */
/*              /dev/ttySxx ou /dev/ttyUSBx  */
/* argum:ent 2 :  vitesse 9600;19200         */
/*           3    nb bit stop                */
/*           4    si parite (1) ou non (0)   */
/* 	     5   type 'i' impaire, par defaut*/
/*                     'e' paire             */
/*********************************************/
  /** \fn rs232( char *line, int b_rate, int nb_bit_data,int n_bit_stop, int parity_yes_no, int odd_even_ms);
      
      \brief constructeur permettant de creer des objets rs232 (desquels les objets JBUS dérivent au sens de la POO) avec les reglages serie adaptés
                
   */
    rs232( char *line, int b_rate, int nb_bit_data,int n_bit_stop, int parity_yes_no, int odd_even_ms);
 
 ~rs232();
    /************************************************************************************************/
    /** \fn void RS_EChnX(unsigned char *buffer, long MaxBuff)
      \brief ecriture de MaxBuff octets sur port handle h_RS
      \param[in]  unsigned char *buffer  :   adresse du buffer
      \param[in]  long MaxBuff                    :   Nombre d'octets à écrire
     \return      code d'erreur eventuel -1 NOK O OK
    ***************************************************************************************************/
 void RS_EChnX(unsigned char *buffer, long MaxBuff);

    /************************************************************************************************/
    /** \fn void RS_RChnX(unsigned char *buffer, long MaxBuff)
      \brief ecriture de MaxBuff octets sur port handle h_RS
      \param[in]  unsigned char *buffer  :   adresse du buffer
      \param[in]  long MaxBuff                    :   Nombre d'octets à lire
     \return      code d'erreur eventuel -1 NOK O OK
    ***************************************************************************************************/
 void RS_RChnX(unsigned char *buffer, long MaxBuff);

/***********************************************************************/
/** \fn void RS_close()
    \brief fermeture de port
   
    \return code de retour  -1 si erreur 0 sinon            */
 /**********************************************************************/

 void RS_close();

public :
   /************************************************************************************************/
    /** \fn int getRS()
      \brief recupère le port handle h_RS
      
     \return   code du handle
    ***************************************************************************************************/
 int getRS() { return h_RS232; }
 


};

