#include "SDLHeader.h"

/*
 * SDL_RENDERER_SOFTWARE
 * SQL_RENDERER_ACCELERATED
 * SDL_RENDERER_PRESENTVSYNC
 * SDL_RENDERER_TARGETTEXTURE
 */
int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL ;
    SDL_Rect rectangle ;
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;
    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_ExitWithError("Initialisation SDL");
    }

    //Création de fenetre et de rendu
    if (SDL_CreateWindowAndRenderer(800,600,0,&window,&renderer) != 0) {
        SDL_ExitWithError("Impossible de créer la fenêtre et le rendu");
    }

    /*------------------------------------------------------------*/
    if(SDL_SetRenderDrawColor(renderer,200,100,267,SDL_ALPHA_OPAQUE) != 0){
        SDL_ExitWithError("Impossible de choisir une couleur");
    }
    if(SDL_RenderDrawPoint(renderer, 100,450) != 0){
        SDL_ExitWithError("Impossible de dessiner le point");
    }
    if(SDL_RenderDrawLine(renderer, 50,50,500,500) != 0){
        SDL_ExitWithError("Impossible de dessiner une ligne");
    }
    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 120;
    if(SDL_SetRenderDrawColor(renderer,155,425,256,SDL_ALPHA_OPAQUE) != 0){
        SDL_ExitWithError("Impossible de choisir une couleur");
    }
    if(SDL_RenderDrawRect(renderer,&rectangle) != 0){
        SDL_ExitWithError("Impossible de dessiner un rectangle");
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(6000);
    /*------------------------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}