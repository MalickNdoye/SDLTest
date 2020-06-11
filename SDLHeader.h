//
// Created by guest on 09/06/2020.
//

#ifndef SDLTEST_SDLHEADER_H
#define SDLTEST_SDLHEADER_H

/*
    GNU/Linux et MacOS
        > gcc main.c $(sdl2-config --cflags --libs) -o prog
        > gcc *.c $(sdl2-config --cflags --libs) -o prog
    Windows
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1080
#define FPS_LIMIT 16
void SDL_ExitWithError(const char *message);
void SDL_Limit_FPS(unsigned int limit);
#endif //SDLTEST_SDLHEADER_H
