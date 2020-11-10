#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct gameType {
    SDL_Event event;
    int loopDone;
} gameType;

gameType game;

void input()
{
    while(SDL_PollEvent(&game.event) != 0) {
        switch(game.event.type) {
            case SDL_QUIT:
                game.loopDone=1;
        }
    }
}

void update()
{
}

void draw()
{
}

int main() 
{
    SDL_Window *window;

    if(SDL_Init(SDL_INIT_VIDEO)!= 0) {
        fprintf(stderr, "Could not initialize SDL Video: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow("hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        exit(1);
    }
    while(!game.loopDone) {
        input();
        update();
        draw();
    }
    return 0;
}
