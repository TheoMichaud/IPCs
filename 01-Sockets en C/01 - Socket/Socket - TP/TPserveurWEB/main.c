/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 18 septembre 2018, 11:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


/*
 * 
 */
int main(int argc, char** argv) {
    int socketServeur;
    int socketDeux;
    int valeurRecue;
    int valeurRetour;
    int tailleStructure;
    int retourListen;
    int retourRead;
    int retourWrite;
    int retourB;
    struct sockaddr_in adresse;
    struct sockaddr_in infoClient;
    FILE *fic;

    //Ouverture du fichier
    fic = fopen("/home/USERS/ELEVES/SNIR2017/dlevillain/SNIR2/IPC/01-Socket/TCP/Serveur/Serveur_TCP_PageWEB/index.html", "r");
    
    
    //Création de la socket TCP
    socketServeur = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    return (EXIT_SUCCESS);
}

