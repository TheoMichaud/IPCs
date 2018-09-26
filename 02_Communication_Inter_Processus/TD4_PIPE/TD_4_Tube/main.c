/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 25 septembre 2018, 11:16
 * 
 */







 /* 
 * En utilisant popen, afficher le résultat donné par le programme externe "/bin/uname".
 */
 
 
 
 
 
 /* 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *fd;
    char buffer[1024];
    int nbRead;
    
    memset(buffer,0,1024);      //Vide le buffer 
    
    fd = popen("/bin/uname ","r");
    if ( fd == NULL)
    {
        printf("Pb avec popen : %s",strerror(errno));
        exit(0);
    }
    
    nbRead = fread(buffer, sizeof(buffer),1,fd);
    
    printf("%s",buffer);
    
    pclose(fd);
    
    return (EXIT_SUCCESS);
}

