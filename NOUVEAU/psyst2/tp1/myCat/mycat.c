/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          mycat.c
 | 
 | Projet :       mycat
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     07/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o mycat mycat.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char car;
    // SI ./mycat nom_fichier
    if (argc == 2)
    {
        int flux;
        flux = open(*(argv + 1), O_RDWR);
        if (flux == -1)
        {
            printf("%s : ", argv[0]);
            puts("Fichier non trouvé");
        }
        else
        {
            while (read(flux, &car, 1))
            {
                write(1, &car, 1);
            }
            close(flux);
            putchar('\n');
            return 0;
        }
    }
    
    // SI ./mycat
    else if (argc == 1)
    {
        while (read(0, &car, 1))
        {
            write(1, &car, 1);
        }
        putchar('\n');
        return 0;
    }
}