/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 26 septembre 2018, 09:40
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
/*
 * 
 */
char message[255];	// Zone commune

void *ma_fonction_thread(void *arg) {
    printf("dans le threadl'argument etait :%s\n", (char *)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit((void *)"merci pour le temps CPU");
}

int main() {
    int res;
    pthread_t un_thread;
    void *thread_result;
    
	strcpy(message,"Debian inside");
    
	res = pthread_create(&un_thread, NULL, ma_fonction_thread, (void *)message);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("attente de la fin du thread...\n");
    
	res = pthread_join(un_thread, &thread_result);
    if (res != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join :%s\n", (char *)thread_result);
    printf("Le message est maintenant %s\n", message);
    
    exit(EXIT_SUCCESS);
}

