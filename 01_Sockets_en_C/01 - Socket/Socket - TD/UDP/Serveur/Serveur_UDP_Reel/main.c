/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 14 septembre 2018, 11:33
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
typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;

int main(int argc, char** argv) {
 int socketServeur;
    int valeurRecu;
    int valeurRetour = 10;
    int tailleStructure;
    int ret;
    int retour;
    int retourB;
    struct sockaddr_in adresse;
    struct sockaddr_in infoClient;
    
    //Création de la socket UDP
    socketServeur = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socketServeur == -1) {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    }

    
    //Init des informations
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(2222); //numero de port du serveur dans l'ordre des octets du réseau
    adresse.sin_addr.s_addr = htonl(INADDR_ANY); // adresse IP du serveur dans l'ordre des octets du reseau

    retourB = bind(socketServeur, (struct sockaddr*) &adresse, sizeof (adresse)); //attachement ip-port
    
    
    
    
    tailleStructure = sizeof(infoClient);
    //envoi de l'entier au client
    ret = recvfrom(socketServeur, &valeurRecu, sizeof(valeurRecu), 0, (struct sockaddr *) &infoClient, &tailleStructure);

    
    //affiche la valeur reçu
    printf("message du client %s Réponse : %d\n", inet_ntoa(infoClient.sin_addr), valeurRecu);

    retour = sendto(socketServeur, &valeurRetour, sizeof(valeurRetour), 0, (struct sockaddr *) &infoClient, tailleStructure);

    

    
    
    
    return (EXIT_SUCCESS);
}