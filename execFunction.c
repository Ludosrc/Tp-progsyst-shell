//
// Created by ludovic on 06/01/23.
//
#include <wait.h>
#include "header.h"


void executeCommande(){
    int nbCharRead; // permet de récupérer plus tard pour suprimmer
    // le dernier caractère de la chaine

    int status;
    char buffer[MAX_BUFFER_SIZE];
    nbCharRead = read(STDIN_FILENO,buffer, MAX_BUFFER_SIZE);
    buffer[nbCharRead-1] = 0; // supression du dernier caractère qui est "entrée"
    // qui si on ne le supprime pas empêche l'execution de la commande
    pid_t ret = fork();
    if(ret == 0){
        execlp(buffer,buffer,NULL);
        exit(EXIT_FAILURE);
    }

    else{
        wait(&status);
        // On attend que le fils est fini pour afficher prompt
        displayPrompt();
    }
}

