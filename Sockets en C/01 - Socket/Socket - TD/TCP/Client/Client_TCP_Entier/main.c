/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 18 septembre 2018, 08:13
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int socketClient;
    struct sockaddr_in infoServeur;
    int entierAEnvoyer=140;
    int entierRecu;
    int tailleStructure;
    int retour;
    
    socketClient=socket(PF_INET , SOCK_STREAM, IPPROTO_TCP);
    if(socketClient==-1)
    {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    }
    
    infoServeur.sin_family=AF_INET;
    infoServeur.sin_port=htons(5555);
    infoServeur.sin_addr.s_addr=inet_addr("172.18.58.79");
    //infoServeur.sin_addr.s_addr=inet_addr("127.0.0.1");//tester avec soi-même
    
    retour=connect(socketClient, (struct sockaddr *)&infoServeur, sizeof(infoServeur));
    if(retour==-1)
    {
        printf("pb connect : %s \n", strerror(errno));
        exit(errno);
    }
    
    retour=sendto(socketClient, &entierAEnvoyer, sizeof(entierAEnvoyer), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur));       
    
    if(retour==-1)
    {
        printf("pb sendto : %s \n",strerror(errno));
        exit(errno);
    }

    tailleStructure=sizeof(infoServeur);
    retour=recvfrom(socketClient, &entierRecu, sizeof(entierRecu), 0, (struct sockaddr *)&infoServeur, &tailleStructure);
    
    if(retour==-1)
    {
        printf("pb recvfrom: %s \n",strerror(errno));
    }  
    //afficher l'entier du serveur
    printf("message reçu : %d \n", entierRecu);

    return (EXIT_SUCCESS);
}