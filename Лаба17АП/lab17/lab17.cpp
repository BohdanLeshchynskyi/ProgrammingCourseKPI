#include <iostream>
#include <SDL.h>
#include <math.h>
#define w 1280
#define h 720
#define con 230


using namespace std;


void osi(SDL_Renderer* renderer) {


    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, h / 2, w, h / 2);
    SDL_RenderDrawLine(renderer, w / 2, 0, w / 2, h);
    SDL_RenderPresent(renderer);

}

float func(float x) {
    return log(x) + pow((x+1),3);
}


float IamLazy(float* f(float), double X)
{
    return *f(X);
}

void draw(SDL_Renderer* renderer) {
    int x, y;

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    for (int i = -w; i < w; i++) {
        if (i != 4) {
            SDL_RenderDrawLine(renderer,w/2 + i , h/2 - (func((float)i/con)*con), w/2 + i + 1 , h/2 - (func((float)(i + 1)/con)*con));
            //SDL_RenderDrawPoint(renderer, w / 2 + i, h / 2 - (func((float)i / con)) * con);
        }
    }
    SDL_RenderPresent(renderer);
}


int main(int argc, char* args[]) {
    /*float val = 0;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    float* x;

    if (SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer) != 0) return 1;

    SDL_bool done = SDL_FALSE;

    osi(renderer);
    draw(renderer);

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }
        SDL_Delay(20);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();*/

    

    return 0;
}
