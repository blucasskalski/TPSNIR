/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          suite.c
 | 
 | Projet :       suite
 | Sujet :        visionneuse hexadécimale
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o suite suite.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *suite(int lg, char ch);

int main(int argc, char *argv[])
{
    if (argc < 3)
        return -1;
    //printf("%s", suite(atoi(argv[1]), *argv[2]));
    suite(atoi(argv[1]), *argv[2]);

    return 0;
}

char *suite(int lg, char ch)
{
    char suite2[lg];
    while (lg > 0)
    {
        strcat(suite2, &ch);
        lg--;
    }
    printf("%s\n", suite2);
}