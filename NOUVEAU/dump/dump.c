/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          dump.c
 | 
 | Projet :       dump
 | Sujet :        visionneuse hexadécimale
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o dump dump.c
 + ------------------------------------------------------------------------ */

 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>

 int main(int argc, char* argv[])
 {
     FILE* flux;
     char car;
     flux = fopen(*(argv+1), "rb");
     if(flux == NULL)
     {
         printf("%s : ", argv[0]);
         puts("Fichier non trouvé");
     }
     else
     {
        while(fread(&car, 1, 1, flux))
        {
         putchar(car);
         }
     
     fclose(flux);
     putchar('\n');
     }

    

     int i = 0;
     for(i = 0 ; i < argc ; i++)
     {
         printf("Elément d'ordre %d ", i);
         puts(argv[i]);
     }
     putchar('\n');
     return 0;


 }