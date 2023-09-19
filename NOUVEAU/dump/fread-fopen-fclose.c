 /* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          fread.c
 | 
 | Projet :       fread
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     03/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o fread fread.c
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
         return -1;
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
 }