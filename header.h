//
// Created by ludovic on 06/01/23.
//

#ifndef UNTITLED_HEADER_H


//Include section
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


//Macro section
#define Message_Bienvenue "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define PROMPT "enseash % "
#define Message_ByeBye "Bye Bye...\n$ "
#define  MAX_BUFFER_SIZE 512

//Prototype section

void displayBienvenue();
void displayPrompt();
void executeCommande();
void exitCommande();


#define UNTITLED_HEADER_H

#endif //UNTITLED_HEADER_H
