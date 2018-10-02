/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 2 octobre 2018, 10:55
 */

#include <string.h>
#include "zone.h"

/*
 * 
 */
float randomF() {
    return ((float) 100.0 * rand() / (RAND_MAX + 0.1));
}

unsigned int randomI() {
    return ((unsigned int) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

int main(int argc, char *argv[]) {
    struct donnees maFile;
    int idFile;
    unsigned int val = 0;
    float valF;

    /* obtention de la clé */
    key_t key;
    if ((key = ftok("/tmp/bidon", 5678)) == -1) {
        perror("ftok");
        exit(2);
    }

    /* obtention de la file pour la clé key*/
    idFile = msgget(key, 0666 | IPC_CREAT);
    if (idFile == -1) {
        printf("Pb creation file : %s \n", strerror(errno));
        sleep(2);
    }

    while (1) {
        valF = randomF(); // tirage au sort d'un float 
        sprintf(maFile.texte, "%f", valF); //conversion en chaines de caractères
        maFile.type = 2; //message de type 2
        printf("type = %1d message = %s \n", maFile.type, maFile.texte); //affichage du message 
        msgsnd(idFile, (void*) &maFile, sizeof (maFile.texte), IPC_NOWAIT); // envoi du message 

        val = randomI();
        sprintf(maFile.texte, "%d", val);
        maFile.type = 4;
        printf("type = %1d message = %s \n", maFile.type, maFile.texte); //affichage du message 
        msgsnd(idFile, (void*) &maFile, sizeof (maFile.texte), IPC_NOWAIT); // envoi du message 
        sleep(1);

    }
    return (EXIT_SUCCESS);
}

