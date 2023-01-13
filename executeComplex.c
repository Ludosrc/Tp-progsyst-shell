//
// Created by ludovic on 06/01/23.
//
#include "header.h"


void executeComplex(){
    // Définition des variables
    int nbCharRead; //Permet de connaitre notre taille de buffer
    int temps;
    int status;
    char* partie[TAILLE_PARTIE];
    char buffer[MAX_BUFFER_SIZE];
    struct timespec clk_debut, clk_fin;
    //Permet de calculer le temps d'execution de la commande


    nbCharRead = read(STDIN_FILENO,buffer, MAX_BUFFER_SIZE);
    buffer[nbCharRead-1] = 0;
    // supression du dernier caractère qui est "entrée"
    // qui si on ne le supprime pas empêche l'execution de la commande



    int k = 0;
    partie[k] = strtok(buffer," ");
    while(partie[k] != NULL){
        k++;
        partie[k] = strtok(NULL," ");
    }
    //Séparation de buffer en parties dans un tableau afin de pouvoir executer une commande qui a plusieurs arguments


    if(strcmp(buffer,"exit") == 0 | strcmp(buffer,"")==0){
        write(STDOUT_FILENO,Message_ByeBye, sizeof(Message_ByeBye)-1);
        exit(EXIT_SUCCESS);
    }
    //On regarde si le buffer est égal à exit ou "" et on quitte le programme avec exit_success
    //On compare avant le fork sinon on ne ferme que le fils ou le père



    clock_gettime(CLOCK_REALTIME,&clk_debut); //Capture du temps de début de la commande
    pid_t ret = fork(); //duplication du processus

    if(ret == 0){ //On est dans le fils
        //execlp(buffer,buffer,NULL); // n'execute que arguments par arguments donc ne correspond pas à l'usage d'une commande à plusieurs arguments
        execvp(partie[0],partie); //permet d'executer tous les arguments en une fois
        exit(EXIT_FAILURE);
    }

    else{ //On est dans le père

        wait(&status); //On attend que le fils soit terminé

        clock_gettime(CLOCK_REALTIME,&clk_fin); //on récupère le temps de fin du programme

        temps = (clk_fin.tv_sec-clk_debut.tv_sec)*1000 + (clk_fin.tv_nsec-clk_debut.tv_nsec)/1000000;
        //On calcule le temps d'execution de la commande

        displayNextPrompt(status,temps);
        // On attend que le fils est fini pour afficher prompt

    }
}

