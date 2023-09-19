/* ------------------------------------------------------------------------
 | BTS SNIR 2ND ANNEE              Lycée La Fayette
 + ------------------------------------------------------------------------
 |
 | Nom :          myls.c
 | 
 | Projet :       myls
 | Sujet :        
 | 
 | Auteur :       Flavian LAXENAIRE
 | Version : 
 | Création :     07/09/21
 | Mise à jour :
 | 
 | Facbrication : gcc -Wall -o myls myls.c
 + ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define TBUF 1024
#define HEADSIZE (sizeof(struct direct) - (MAXNAMLEN + 1))
/*****************************************************
* Role : analyse les types de fichiers et les droits *
*        E : 1 : nom du fichier courant              *
*        Sortie : int 0 = NOK ; 1 = OK               *
*****************************************************/
int mode(char *nom)
{
    struct stat bufstat2;

    char mod[11], *p; //pointe chaine des droits
    p = mod;

    strcpy(p, "----------"); //remet à 0  les droits pour nouveau fichier courant

    if (stat(nom, &bufstat2) == -1) //recupere info fichier courant
    {
        perror("stat in mode");
        return 0;
    }
    if ((bufstat2.st_mode & S_IFMT) == S_IFDIR)
    {
        *p = 'd';
    }
    else if ((bufstat2.st_mode & S_IFMT) == S_IFCHR) //fichier special mode caractere
    {
        *p = 'c';
    }
    else if ((bufstat2.st_mode & S_IFMT) == S_IFBLK) //fichier special mode bloc
    {
        *p = 'b';
    }
    else if ((bufstat2.st_mode & S_IFMT) == S_ISUID) //euid  (sticky bit positionne)
    {
        p += 3; //se place sur le champ x du owner
        *p = 's';
        p -= 3; //se replace sur champ initial
    }

    //extrait les champs ugo A FINIR

    if ((bufstat2.st_mode & S_IRWXU) == S_IRWXU)
    { //OWNER
        //printf("acces total user");
        p += 1;
        *p++ = 'r';
        *p++ = 'w';
        *p = 'x';
        p -= 3;
    }
    if ((bufstat2.st_mode & S_IRUSR) == S_IRUSR)
    {
        p += 1;
        *p = 'r';
        p--;
    }
    if ((bufstat2.st_mode & S_IWUSR) == S_IWUSR)
    {
        p += 2;
        *p = 'w';
        p -= 2;
    }
    if ((bufstat2.st_mode & S_IXUSR) == S_IXUSR)
    {
        p += 3;
        *p = 'x';
        p -= 3;
    }
    //GROUP
    if ((bufstat2.st_mode & S_IRWXG) == S_IRWXG)
    { //GROUPE
        p += 4;
        *p++ = 'r';
        *p++ = 'w';
        *p = 'x';
        p -= 6;
    }
    if ((bufstat2.st_mode & S_IRGRP) == S_IRGRP)
    {
        p += 4;
        *p = 'r';
        p -= 4;
    }
    if ((bufstat2.st_mode & S_IWGRP) == S_IWGRP)
    {
        p += 5;
        *p = 'w';
        p -= 5;
    }
    if ((bufstat2.st_mode & S_IXGRP) == S_IXGRP)
    {
        p += 6;
        *p = 'x';
        p -= 6;
    }
    //OTHER
    if ((bufstat2.st_mode & S_IRWXO) == S_IRWXO)
    { //AUTRE
        p += 7;
        *p++ = 'r';
        *p++ = 'w';
        *p = 'x';
        p -= 9;
    }
    if ((bufstat2.st_mode & S_IROTH) == S_IROTH)
    {
        p += 7;
        *p = 'r';
        p -= 7;
    }
    if ((bufstat2.st_mode & S_IWOTH) == S_IWOTH)
    {
        p += 8;
        *p = 'w';
        p -= 8;
    }
    if ((bufstat2.st_mode & S_IXOTH) == S_IXOTH)
    {
        p += 9;
        *p = 'x';
        p -= 9;
    }

    //printf("%ld",bufstat2.st_size);


    /* affiche les flags type de fichier, et droits */
    char * time = ctime(&bufstat2.st_atim.tv_sec);
    if(time[strlen(time)-1] == '\n') time[strlen(time)-1] = '\0';
    printf(" %s %d %ld %s ", mod, bufstat2.st_uid,  bufstat2.st_size, time);
    return 1;
}

int main(int argc, const char *argv[])
{
    struct stat bufstat;
    int fd;
    DIR *fdrep;

    /* par defaut listage repertoire courant */
    //TO DO ELEVE   Q3
    char nom[25];
    strcpy(nom, ".");

    if (argc == 1)
        strcpy(nom, ".");
    else if (argc == 2 && (strcmp(argv[1], "-l") != 0))
        strcpy(nom, argv[1]);
    else if (argc == 3)//option -l à priori ...
    {
        strcpy(nom, argv[2]);
    }
    /* fichier ne peut etre ouvert */
    if (stat(nom, &bufstat) == -1)
        printf("%s:cannot stats %s\n", argv[0], nom);
    /* n'est pas un repertoire */
    if ((bufstat.st_mode & S_IFMT) != S_IFDIR)
        printf("%s: %s is not a directory \n", argv[0], nom);
    /* n'est pas lisible  */
    if ((fd = open(nom, O_RDONLY)) == -1)
        printf("%s: cannot read \n", argv[0]);
    fdrep = opendir(nom);
    if (fdrep == 0)
    {
        perror("pb open dir");
        exit(0);
    }

    /**** Boucle de parcours des informations repertoires */
    for (;;)
    {

        struct dirent *entree = readdir(fdrep);
        if (entree == 0)
            break;

        if (entree->d_ino == 0) //entrée inode non utilisée
            continue;

        if (stat(entree->d_name, &bufstat) == -1)
        {
            printf("cannot stat %s\n", entree->d_name);
            perror("wtf");
            return -1;
        }

        //TO Q3 APPELER cette fonction si option -l
        //TESTER si avec option -l sur ligne de commande
        if (argc == 3 || argc == 2)
        {
            if (strcmp(argv[1], "-l") == 0)
            {
                if (mode(entree->d_name) == 0) //fonction analyse des droits
                    return 0;
            }
        }
        //affiche le nom du fichier courant
        printf("%s \n", entree->d_name);
    }
    closedir(fdrep);

    close(fd);
    /**********  fin boucle parcours repertoire ****/
}
