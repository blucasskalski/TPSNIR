// TOUCHE PAS A CA
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <assert.h>
#include <stdlib.h>
#include "jbus.h"
#include <string.h>
#include <csignal>
#include <iostream>

using namespace std;

//pointeur d'instance jbus
jbus *j1;

void arret(int signal)
{

  std::cout << "arret jbus par signal CTRL-C : nO " << signal << endl;

  j1->~jbus(); //laisser cet appel...
  std::raise(SIGKILL);
}

int main(int argc, char **argv)
{

  int nb = 0;
  unsigned char buf[10]; // trame de test lecture jbus
  unsigned char buf2[10];
  // TO DO creation d'une instance de jbus avec les réglages 2 bit de STOP sans parite
  char *port = "/dev/ttyUSB0";
  int nbits = 8;
  j1 = new jbus(port, 9600, nbits, 2, 0, 0);

  // Install a signal handler : ne pas retirer
  std::signal(SIGINT, arret);

  while (1) /* boucle IHM requetes MODBUS*/
  {
    cout << endl;
    cout << "Faites un choix opération. 1 : Ecriture   2 : Lecture" << endl;
    int op;
    cin >> op;
    cout << "Faites un choix de module BBES. [2-4]" << endl;
    int mod;
    cin >> mod;

    int valeur;
    if (op == 1)
    {
      cout << "Valeur à écrire" << endl;

      cin >> valeur;
    }
    if (op == 1)
    {
      unsigned char *s;
      cout << "valeur trame reponse écriture : ";
      int t = j1->API_Module_Write_1word(mod, 0, valeur);
      j1->read_value_C(buf2, 10);
      cout << "buf : ";
      for (int i = 0; i < 10; i++)
      {
        printf("%d ", buf2[i]);
      }
      cout << endl;
    }
    else if (op == 2)
    {
      cout << "Faites un choix de mode de lecture. 1 : Nbits   2 : Nwords" << endl;
      int mode;
      cin >> mode;
      switch(mode)
      {
        case 1:  j1->API_Module_Read_Nbits(mod, 0, 10);
        case 2:  j1->API_Module_Read_Nwords(mod, 0, 1);
        break;
      }
      cout << "valeur trame reponse lecture : ";
      j1->read_value_R(buf, 10);
      cout << "buf : ";
      for (int i = 0; i < 10; i++)
      {
        printf("%d ", buf[i]);
      }
      cout << endl;
    }
  }
}