#include "header.h"


int main(int argc, char *argv[]) {
    displayBienvenue();
    displayPrompt();

    while(1){
        executeCommande();

    }

    return EXIT_SUCCESS;
}

