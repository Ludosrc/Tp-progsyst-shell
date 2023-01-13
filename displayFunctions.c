//
// Created by ludovic on 06/01/23.
//

#include "header.h"

void displayBienvenue(){
    write(STDOUT_FILENO,Message_Bienvenue, sizeof(Message_Bienvenue)-1);
}

void displayPrompt(){
    write(STDOUT_FILENO,PROMPT,sizeof(PROMPT)-1);
}

void displayNextPrompt(int status,int temps){
    char signal[50] = {0};

    if(WIFEXITED(status)){
        sprintf(signal,"enseash  [exit:%d |%d ms] %% ",WEXITSTATUS(status),temps);
        write(STDOUT_FILENO,signal, strlen(signal));
    }else if(WIFSIGNALED(status)){
        sprintf(signal,"enseash  [Sign:%d |%d ms] %% ",WTERMSIG(status),temps);
        write(STDOUT_FILENO,signal, strlen(signal));
    }
}





