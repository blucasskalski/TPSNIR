//
//  main.c
//  myls
//
//  Created by maylaender patrick on 10/07/2014.
//  Copyright (c) 2014 maylaender patrick. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <time.h>
#include <pwd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>




#define TBUF 1024
#define HEADSIZE    (sizeof(struct direct) - (MAXNAMLEN + 1))
/*****************************************************
* Role : analyse les types de fichiers et les droits *
*        E : 1 : nom du fichier courant              *
*        Sortie : int 0 = NOK ; 1 = OK               *
*****************************************************/
int mode(char *nom)
    {
        struct stat bufstat2;
        
        char t[11] , *p;  //pointe chaine des droits
        p = t;
        
        strcpy(p,"----------");   //remet à 0  les droits pour nouveau fichier courant
        
        if(stat(nom,&bufstat2) == -1)    //recupere info fichier courant
        {
            perror("stat in mode");
            return 0;
        }
        if ( (bufstat2.st_mode & S_IFMT) == S_IFDIR )
        {
            *p = 'd';
        }
        else if ( (bufstat2.st_mode & S_IFMT) == S_IFCHR )  //fichier special mode caractere
        {
            *p = 'c';
        }
        else if ( (bufstat2.st_mode & S_IFMT) == S_IFBLK )  //fichier special mode bloc
        {
            *p = 'b';
        }
        else if ( (bufstat2.st_mode & S_IFMT) == S_ISUID )  //euid  (sticky bit positionne)
        {
            p +=3;  //se place sur le champ x du owner
            *p = 's';
            p -=3; //se replace sur champ initial
        }
       
        if ( (bufstat2.st_mode & S_IRWXU) == S_IRWXU)
        {   //OWNER
            
            //printf("acces total user");
            p += 1;
            *p++ = 'r';
            *p++ = 'w';
            *p = 'x';
            p -= 3;
            
        }
	if ( (bufstat2.st_mode & S_IRUSR) == S_IRUSR)
        {   //OWNER
            
            //printf("acces lecture user");
            p += 1;
            *p = 'r';
            p -= 1;
            
        }
	if ( (bufstat2.st_mode & S_IWUSR) == S_IWUSR)
        {   //OWNER
            
            //printf("acces lecture user");
            p += 2;
            *p = 'w';
            p -= 2;
            
        }
	if ( (bufstat2.st_mode & S_IXUSR) == S_IXUSR)
        {   //OWNER
            
            //printf("acces lecture user");
            p += 3;
           *p = 'x';
            p -= 3;
            
        }
	if ( (bufstat2.st_mode & S_IRWXG) == S_IRWXG)
        {   //GROUP
            
            //printf("acces total groupe");
            p += 4;
            *p++ = 'r';
            *p++ = 'w';
            *p = 'x';
            p -= 6;
            
        }
	if ( (bufstat2.st_mode & S_IRGRP) == S_IRGRP)
        {   //GROUP
            
            //printf("acces lecture groupe");
            p += 4;
            *p = 'r';
            p -= 4;
            
        }
	if ( (bufstat2.st_mode & S_IWGRP) == S_IWGRP)
        {   //GROUP
            
            //printf("acces lecture groupe");
            p += 5;
            *p = 'w';
            p -= 5;
            
        }
	if ( (bufstat2.st_mode & S_IXGRP) == S_IXGRP)
        {   //GROUP
            
            //printf("acces lecture groupe");
            p += 6;
            *p = 'x';
            p -= 6;
            
        }
	if ( (bufstat2.st_mode & S_IRWXO) == S_IRWXO)
        {   //OTHER
            
            //printf("acces total autre");
            p += 7;
            *p++ = 'r';
            *p++ = 'x';
            *p = 'w';
            p -= 9;
            
        }
	if ( (bufstat2.st_mode & S_IROTH) == S_IROTH)
        {   //OTHER
            
            //printf("acces lecture autre");
            p += 7;
            *p = 'r';
            p -= 7;
        }
	if ( (bufstat2.st_mode & S_IWOTH) == S_IWOTH)
        {   //OTHER
            
            //printf("acces lecture autre");
            p += 8;
            *p = 'w';
            p -= 8;
        }
	if ( (bufstat2.st_mode & S_IXOTH) == S_IXOTH)
        {   //OTHER
            
            //printf("acces lecture autre");
            p += 9;
            *p = 'x';
            p -= 9;
        }

    /* affiche les flags type de fichier, et droits */
    char buffer[80];
    struct passwd *uid, *gid;
    uid = getpwuid(bufstat2.st_uid);
    gid = getpwuid(bufstat2.st_gid);
    strftime(buffer, sizeof(buffer),"%h. %e %I:%M",localtime(&bufstat2.st_mtime));
    printf(" %s", t);
    printf(" %ld", bufstat2.st_nlink);
    printf(" %s", uid->pw_name);
    printf(" %s", gid->pw_name);
    printf(" %zu \t", bufstat2.st_size);
    printf(" %s", buffer);

    return 1;
}



int main(int argc, const char * argv[])
{
    
    struct stat bufstat ;
    int fd;
    DIR *fdrep ;
    int targv;
    
    /* par defaut listage repertoire courant */
    //TO DO ELEVE   Q3
    char nom[25];
    if(argc > 1){
	    
    }
    if(argc == 1){
	    strcpy(nom,".");
    }else if(argc == 2){
	char* temp = argv[1];
	if(*temp == '-'){
	    strcpy(nom,".");
	    targv = -1;
	}else{
	    strcpy(nom, argv[1]);
	}
    }else{
	    strcpy(nom,argv[2]);
    }

        /* fichier ne peut etre ouvert */
    if (stat(nom,&bufstat) == -1 )
        printf("%s: cannot stat %s\n",argv[0] , nom);
    /* n'est pas un repertoire */
    if ( (bufstat.st_mode & S_IFMT) != S_IFDIR )
        printf("%s: %s is not a directory \n",argv[0] , nom);
    /* n'est pas lisible  */
    if ((fd = open(nom,O_RDONLY) ) == -1 )
        printf("%s: cannot read \n",argv[0] );
   


    fdrep = opendir(nom);
    if(fdrep == 0)
    {
        perror("pb open dir");
        exit(0);
    }

    
       /**** Boucle de parcours des informations repertoires */
    for(;;)
    {
        
        struct dirent *entree = readdir(fdrep);
        if(entree == 0)
        break;
        
        if(entree->d_ino == 0){     //entrée inode non utilisée
            continue;
	}

            if (stat(entree->d_name,&bufstat) == -1 )
            {
                printf("cannot stat %s\n",entree->d_name);
                return -1;
            }
        
            //TO Q3 APPELER cette fonction si option -l
           //TESTER si avec option -l sur ligne de commande
        for(int i=1;i<argc;i++){
		char* p = argv[i];
		if(*p == '-'){
			switch(*(p+1)){
				case 'l' : 
					if( mode(entree->d_name) == 0){
						return 0;
					}
					break;
			}
		}else{
			strcpy(nom,".");
		}
	}
        
        //affiche le nom du fichier courant
        printf(" %s\n", entree->d_name);
        
    }
    closedir(fdrep);

    close(fd);
    /**********  fin boucle parcours repertoire ****/
    
    
}
