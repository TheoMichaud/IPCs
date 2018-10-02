/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 2 octobre 2018, 10:56
 */



#include <string.h>
#include "zone.h"

int main(int argc, char** argv) {

    struct donnees maFile;
    int idFile;
    int ret;

    /*Obtention de la clé*/
    key_t key;
    if ((key = ftok("/tmp/bidon", 5678)) == -1) {
        perror("ftok");
        exit(2);
    }
    /* obtention de la file pour la clé key*/
    idFile = msgget(key, 0666 | IPC_CREAT);
    if (idFile == -1) {
        printf("Pb creation file : %s \n", strerror(errno));
        exit(0);
    }
    
    while(1){
        memset(maFile.texte,'\0',9); //efface le texte
        ret=msgrcv(idFile,(void*)&maFile,9,2,IPC_NOWAIT); // on retire le message de type 2
        if(ret!=-1){
            printf("temp : %s \n",maFile.texte);
        }
        memset(maFile.texte,'\0',9); //efface le texte
        ret=msgrcv(idFile,(void*)&maFile,9,3,IPC_NOWAIT); // on retire le message de type 3
        if(ret!=-1){
            printf("ordre : %s \n",maFile.texte);
        }
        memset(maFile.texte,'\0',9); //efface le texte
        ret=msgrcv(idFile,(void*)&maFile,9,4,IPC_NOWAIT); // on retire le message de type 4
        if(ret!=-1){
            printf("press : %s \n",maFile.texte);
        }
        
    }
    return (EXIT_SUCCESS);
}