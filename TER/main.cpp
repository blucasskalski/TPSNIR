
#include <cstdlib>
#include <fcntl.h>
#include <string>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

#include "jbus.h"
#include <assert.h>
#include <stdlib.h>

#include <csignal>
#include <iostream>

#define AUTHOR "Bryan LUCAS SKALSKI"

using namespace std;

// pointeur d'instance jbus
jbus *j1;

void arret(int signal) {

  std::cout << "arret jbus par signal CTRL-C : nO " << signal << endl;

  j1->~jbus(); // laisser cet appel...
  std::raise(SIGKILL);
}

void clrnl() {
  system("clear");
  cout << "|[ "
       << "IHM MODBUS RS485" << AUTHOR << " ]|" << endl;
}

char L1() {
  char inpt;
  inpt = 'X';
  cout << "OP :: WRITE[1] | READ[0]" << endl;
  cout << "> ";
  cin >> inpt;
  // cout << "val: " << input << endl;
  // break;
  switch (inpt) {
  case 1:
    cout << "1111111111111111111" << endl;
  case 0:
    cout << "2222222222222222222" << endl;
  default:
    cout << "BAD ARG" << endl;
    L1();
  }
  return inpt;
}

int main(int argc, char **argv) {

  int nb = 0;
  unsigned char buf[10]; // trame de test lecture jbus

  // TO DO creation d'une instance de jbus avec les réglages 2 bit de STOP sans
  // parite
  j1 = new jbus("/dev/ttyUSB0", 9600, 8, 2, 'N', 0);

  // Install a signal handler : ne pas retirer
  std::signal(SIGINT, arret);

  while (1) /* boucle IHM requetes MODBUS*/
  {
    clrnl();
    char input = L1();

    // TODO
  }
}
