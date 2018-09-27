/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tmichaud
 *
 * Created on 26 septembre 2018, 09:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
/*
 * 
 */
void traitement(int sig)
{
    (void) signal(SIGUSR1,traitement);
    printf("Interception du signal %i\n",sig);
}


int main(int argc, char** argv) {

    int pid;
    int pid3;
    int pidP3Reception;
    int descTube[2];

    (void) signal(SIGUSR1,traitement);

        //p1
        //creation tube
        if (pipe(descTube) == 0) {
        
            pid = fork();
            if (pid == 0) //p2
            {
                pid = fork();
                if (pid == 0) //p3
                {
                    printf("Pid p3 : %d\n",getpid());
                    pid3=getpid();
                    //Ecriture PidP3 dans tube
                    write(descTube[1],&pid3,sizeof(pid3));
                    pause();
                }
                else //p2
                {
                    printf("Pid p2 : %d\n",getpid());
                    pause();
                }
            }
            else //p1
            {
                printf("Pid p1 : %d\n",getpid());
                kill(pid,SIGUSR1);
                //Lecture de PidP3 dans le tube
                read(descTube[0],&pidP3Reception,sizeof(int));
                kill(pidP3Reception,SIGUSR1);

            }
        
    }
    return (EXIT_SUCCESS);
}

