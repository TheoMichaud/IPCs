/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   zone.h
 * Author: tmichaud
 *
 * Created on 2 octobre 2018, 10:57
 */

#ifndef ZONE_H
#define ZONE_H


#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>

struct donnees {
    long type;
    char texte[9];
};

#endif