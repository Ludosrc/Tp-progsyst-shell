#include "header.h"

void displayBienvenue(){
    write(STDOUT_FILENO,Message_Bienvenue, sizeof(Message_Bienvenue)-1);
}

void displayPrompt(){
    write(STDOUT_FILENO,PROMPT,sizeof(PROMPT)-1);
}
//
// Created by ludovic on 06/01/23.
//
