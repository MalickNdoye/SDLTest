#include "SDLHeader.h"


int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");

    //Création fenêtre
    window = SDL_CreateWindow("Première fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if(window == NULL)
        SDL_ExitWithError("Creation fenetre echouee");

    /*------------------------------------------------------------*/
    SDL_Delay(6000);
    /*------------------------------------------------------------*/

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}