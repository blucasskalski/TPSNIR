/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          convert-hexa.c
 | 
 | Projet :       convert-hexa
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o convert-hexa convert-hexa.c
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
}


/*
    for (int length = strlen(binary); length > 0; length -= 4)
    {result[i] = 
        long value = 0;
        value = val & 0x0F;
        printf("%ld\n", value);
        value = val >> 4;
    }*/

/* char test[9];
    sprintf(test, "%ld", val);
    int length = strlen(test);
    printf("%d\n", length);
      for(int length2 = length; length2 > 0 ; length2--)
     {
         binary[i]=val%2;
         printf("%ld,\n", val%2);
         val= val /2;
         i++;
         //printf("%d", binary[i]);
     }*/

// CONVERTION DECIMALE -> BINAIRE
/* int i;
    char binary[72];
    long reset = val;
    for (i = 0; val > 0; i++)
    {
        binary[i] = val % 2;
        val = val / 2;
    }
    binary[i++]='\0';
    printf("\nBinary of Given Number is=");
    char test[100];
    sprintf(test, "%s", binary);
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    putchar('\n');

    char test2[9];


    // CONVERTION BINAIRE -> HEXADECIMALE
    for (int length = strlen(binary); length > 0; length -= 4)
    {
        long value = 0;
        value = reset & 0x0F;
        printf("%ld\n", value);
        value = reset >> 4;
    }*/
