/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          test.c
 | 
 | Projet :       test
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o test test.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *itohex(long val, int lg);
int main(int argc, char *argv[])
{
    if (argc < 3)
        return -1;
    puts(itohex(atol(argv[1]), atoi(argv[2])));
    putchar('\n');
    return 0;
}

char *itohex(long val, int lg)
{
    char convert[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if (lg > 8)
        lg = 8;
    char result[lg + 1];
    int value;
    for (int i = lg - 1; i >= 0; i--)
    {
        value = val & 0x0F;
        val = val >> 4;
        result[i] = convert[value];
    }
    result[lg] = '\0';
    return strdup(result);
    /*
    for (int length = strlen(binary); length > 0; length -= 4)
    {result[i] = 
        long value = 0;
        value = val & 0x0F;
        printf("%ld\n", value);
        value = val >> 4;
    }*/
}