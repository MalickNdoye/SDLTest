#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {

    if (argv[1]==NULL || argc>0) {
        printf("Hello, World!\n");
    }

    SDL_Window  * window = NULL ;

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("ERREUR : Initialisation SDL > %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    //Execution du programme
    window = SDL_CreateWindow("Première fenêtre",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,600,0);

    if (NULL == window){
        SDL_Log("ERREUR: Echec création fenêtre > %s\n",
                SDL_GetError());
        return EXIT_FAILURE ;
    }

    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
