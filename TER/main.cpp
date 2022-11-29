
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
 

#include <assert.h>
#include <stdlib.h>
#include "jbus.h"

#include <csignal>
#include <iostream>

using namespace std;

//pointeur d'instance jbus
jbus *j1;
 
void arret(int signal)
{
  
  std::cout << "arret jbus par signal CTRL-C : nO " << signal << endl;
     
  j1->~jbus();//laisser cet appel...
  std::raise(SIGKILL);
}
 

int main(int argc, char **argv)
{

   int nb = 0; 
   unsigned char buf[10]; // trame de test lecture jbus
    

	// TO DO creation d'une instance de jbus avec les réglages 2 bit de STOP sans parite  
 //  j1 =  
       

// Install a signal handler : ne pas retirer
  std::signal(SIGINT, arret);
 
  

  while(1)  /* boucle IHM requetes MODBUS*/
  {
      //TO DO
  }
}
