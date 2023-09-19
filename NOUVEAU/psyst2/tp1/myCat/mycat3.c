/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          mycat3.c
 | 
 | Projet :       mycat3
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     07/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o mycat3 mycat3.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int lire_fichier(char *nom, char *buffer);

int main(int argc, char *argv[])
{
    char car;
    char car2;
    int octet = 0;
    //printf("%d\n", argc);
    int n = 1;
    int arguments = argc;
    char buffer[10];
    if (argc > 1)
    {
        while (arguments > 1)
        {
            if (strcmp(argv[n], "-") == 0)
            {
                while (read(0, &car2, 1) != 0)
                    lire_fichier(*(argv + n + 1), buffer);
            }
            else
            {
                lire_fichier(*(argv + n), buffer);
            }
            //   printf("argc%d_ \n", arguments);
            n++;
            arguments--;
        }
    }

    else if (argc == 1)
    {
        while (read(0, &car, 1))
        {
            write(1, &car, 1);
            octet++;
        }
        putchar('\n');
        return 0;
    }
}

int lire_fichier(char *nom, char *buffer)
{
    char car;
    // SI ./mycat nom_fichier
    int octet = 0;
    int flux;
    flux = open(nom, O_RDWR);
    if (flux == -1)
    {
        puts("Fichier non trouvé");
        return -1;
    }
    else
    {
        while (read(flux, &car, 1))
        {
            //write(1, &car, 1);
            buffer[0] = car;
            octet++;
            printf("%c", buffer[0]);
        }
        close(flux);
        // printf("%s", buffer);
        putchar('\n');
        //   printf("%d", octet);
        return octet;
    }
}

/*
    char buffer[10];
    char car;
    int octet = 0;
    if (argc == 2)
    {
        lire_fichier(*(argv + 1), buffer);
    }
    // SI ./mycat
    else if (argc == 1)
    {
        while (read(0, &car, 1))
        {
            write(1, &car, 1);
            octet++;
        }
        putchar('\n');
        return 0;
    }
}

int lire_fichier(char *nom, char *buffer)
{
    char car;
    // SI ./mycat nom_fichier
    int octet = 0;
    int flux;
    flux = open(nom, O_RDWR);
    if (flux == -1)
    {
        puts("Fichier non trouvé");
        return -1;
    }
    else
    {
        while (read(flux, &car, 1))
        {
            //write(1, &car, 1);
            buffer[0]=car;
            octet++;
            printf("%c", buffer[0]);
        }
        close(flux);
        printf("%s", buffer);
        putchar('\n');
        printf("%d", octet);
        return octet;
    }
    return 0;
}
*/