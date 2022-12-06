
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
  cout << "|[ " << "IHM MODBUS RS485" << AUTHOR << " ]|" << endl;
}

/*
int qAddrMod() {
    int inpt;
    cout << "ADDR BBES? [2] | [3] | [4]" << endl;
    cout << ">";
    cin >> inpt;
    if (inpt != 2 & inpt != 3 & inpt != 4) {
        cout << "WRONG INPUT" << endl;
        return -1;
    }
    else {
        return inpt;
    }
}

int qReg(int Addr) {
    int inpt;
    cout << "REG NUM? [0] -> E [1] -> S" << endl;
    cout << ">";
    cin >> inpt;
    if (inpt < 0) {
        cout << "WRONG INPUT" << endl;
        return -1;
    }
    else {
        return inpt;
    }
}

int qVal() {
    int inpt;
    cout << "VAL ? [0-255]" << endl;
    cout << ">";
    cin >> inpt;
    if (inpt < 0) {
        cout << "WRONG INPUT" << endl;
        return -1;
    }
    else {
        return inpt;
    }
}

int bbesRead(Addr, Reg, Val) {
    return 0;
}

int bbesWrute(Addr, Reg, Val) {
    return 0;
}

void L2R() {
    int rAddr = qAddrMod();
    while(rAddr == -1){
        rAddr = qAddrMod();
    }
    int rReg = qReg(rAddr);
    while (rReg == -1) {
        rReg = qReg(rAddr);
    }
    int rVal = qVal();
    while (rVal == -1) {
        rVal = qVal();
    }
    queryAns = bbesRead(rAddr, rReg, rVal);

}

void L2W() {
    int rAddr = qAddrMod();
    while (rAddr == -1) {
        rAddr = qAddrMod();
    }
    int rReg = qReg(rAddr);
    while (rReg == -1) {
        rReg = qReg(rAddr);
    }
    int rVal = qVal();
    while (rVal == -1) {
        rVal = qVal();
}

void L1() {
  char inpt;
  cout << "OP :: WRITE[1] | READ[0]" << endl;
  cout << "> ";
  cin >> inpt;
  // cout << "val: " << input << endl;
  // break;
  switch (inpt) {
  case '1':
    cout << "WRITE" << endl;
    L2R();
    //break;
  case '0':
    cout << "READ" << endl;
    L2W();
    //break;
  default:
    clrnl();
    cout << "BAD ARG" << endl;
    L1();
  }
}
*/

int main(int argc, char **argv) {

  int nb = 0;
  unsigned char buf[10]; // trame de test lecture jbus

  // DONE creation d'une instance de jbus avec les réglages 2 bit de STOP sans
  // parite
  j1 = new jbus("/dev/ttyUSB0", 9600, 8, 2, 'N', 0);

  // Install a signal handler : ne pas retirer
  std::signal(SIGINT, arret);

  while (1) /* boucle IHM requetes MODBUS*/
  {
    clrnl();
    clrnl();
    //L1();
    cout << "Lecture Module BBES n°3 Registre n°3" << endl;
    j1->API_Module_Read_Nbits(3, 3, 16);
    j1->read_value_R(buf, 8);

    // TODO
  }
}
