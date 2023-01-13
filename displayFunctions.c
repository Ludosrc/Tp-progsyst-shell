//
// Created by ludovic on 06/01/23.
//

#include "header.h"

void displayBienvenue(){
    write(STDOUT_FILENO,Message_Bienvenue, sizeof(Message_Bienvenue)-1);
    // Affichage dans la console du message bienvenue
}

void displayPrompt(){
    write(STDOUT_FILENO,PROMPT,sizeof(PROMPT)-1);
    // Affichage dans la console du message prompt normal
}

void displayNextPrompt(int status,int temps){
    char signal[50] = {0}; //On fixe tous les caractères de notre tableau à 0 pour ne pas afficher des caractère non désiré

    if(WIFEXITED(status)){
        sprintf(signal,"enseash  [exit:%d |%d ms] %% ",WEXITSTATUS(status),temps);
        write(STDOUT_FILENO,signal, strlen(signal));
    }else if(WIFSIGNALED(status)){
        sprintf(signal,"enseash  [Sign:%d |%d ms] %% ",WTERMSIG(status),temps);
        write(STDOUT_FILENO,signal, strlen(signal));
    }
    // Affichage dans la console du message prompt modifé avec les valeur de EXIT,SIGNAL et le temps d'execution de la commande
}





