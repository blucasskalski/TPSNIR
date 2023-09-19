/*******************************************/
/* Matériaux OpenGL TP2                    */
/* 09/11/21                                */
/* g++ -Wall -o main main.cpp crvba.cpp    */
/* auteur : Flavian LAXENAIRE		       */
/*******************************************/

#include "crvba.h"
#include "cmateriau.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    CRvba couleur1;
    CRvba couleur2(115, 157, 172);
    couleur1.setRvba(0, 255, 255);
    cout << couleur2.printRvba() << endl;
    cout << couleur1.printRvba() << endl;
    CMateriau mat1;
    CMateriau mat2("turquoise", couleur2, CRvba(0.396, 0.741, 0.691), CRvba(0.297, 0.308, 0.306));
    cout << mat2.printMateriau();
    mat1 = mat2;
    mat1.setAlpha(50);
    cout << mat1.printMateriau();
    return 0;
}
