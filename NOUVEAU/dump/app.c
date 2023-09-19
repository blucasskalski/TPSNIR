/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          app.c
 | 
 | Projet :       app
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o app app.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NCOD 16
#define ICOD 10
#define OFFS 6
#define IASC 62
#define LIGN 79

char *suite(int lg, char ch);
char *itohex(long val, int lg);

int main(int argc, char *argv[])
{
    FILE *flux;
    char car;
    long cpt = 0;
    char ligne[LIGN];
    strcpy(ligne, suite(LIGN - 1, 32));
    memmove(ligne, itohex(cpt, OFFS), OFFS);

    flux = fopen(*(argv + 1), "rb");
    if (flux == NULL)
    {
        printf("%s : ", argv[0]);
        puts("fichier non trouvé");
        return -1;
    }
    while (fread(&car, 1, 1, flux))
    {
        cpt++;
        if (isprint(&car))
        {
            strcpy(&ligne[cpt], &car);
        }
        if (!(cpt % NCOD))
        {
            puts(ligne);
            
        }
    }
    if (cpt % NCOD)
        puts(ligne);
    fclose(flux);
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

char *suite(int lg, char ch)
{
    char suite2[81];
    int i = 0;
    for (i = 0; lg > 0; lg--)
    {
        if (i < 80)
        {
            suite2[i] = ch;
            i++;
        }
    }
    suite2[i++] = '\0';
    return strdup(suite2);
    printf("%s\n", suite2);
}