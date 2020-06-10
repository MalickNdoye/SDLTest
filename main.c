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
    SDL_Rect rect ;
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_ExitWithError("Initialisation SDL");
    }
    //Création de fenetre et de rendu
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,0,&window,&renderer) != 0) {
        SDL_ExitWithError("Impossible de créer la fenêtre et le rendu");
    }

    /*------------------------------------------------------------*/
    if(SDL_SetRenderDrawColor(renderer,200,100,267,SDL_ALPHA_OPAQUE) != 0){
        SDL_ExitWithError("Impossible de choisir une couleur");
    }
    if(SDL_RenderDrawPoint(renderer, 100,450) != 0){
        SDL_ExitWithError("Impossible de dessiner le point");
    }
    if(SDL_RenderDrawLine(renderer, 0,0,WINDOW_WIDTH-1,WINDOW_HEIGHT-1) != 0){
        SDL_ExitWithError("Impossible de dessiner une ligne");
    }
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 200;
    rectangle.h = 120;
    if(SDL_SetRenderDrawColor(renderer,155,425,256,SDL_ALPHA_OPAQUE) != 0){
        SDL_ExitWithError("Impossible de choisir une couleur");
    }
    if(SDL_RenderDrawRect(renderer,&rectangle) != 0){
        SDL_ExitWithError("Impossible de dessiner un rectangle");
    }

    image = SDL_LoadBMP("Greenery800.bmp");
    if (NULL == image){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    texture = SDL_CreateTextureFromSurface(renderer,image);
    SDL_FreeSurface(image);
    if (NULL == texture){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    if(SDL_QueryTexture(texture,NULL,NULL, &rect.w,&rect.h)!=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    rect.x = (WINDOW_WIDTH - rect.w)/2 ;
    rect.y = (WINDOW_HEIGHT - rect.h)/2 ;

    if(SDL_RenderCopy(renderer,texture,NULL,&rect)){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    };

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