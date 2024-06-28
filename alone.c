#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

void draw_graph(SDL_Renderer *renderer, float a) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < WIDTH; ++i) {
        float x = (i - WIDTH / 2) * (2.0f * sqrtf(33) / WIDTH);
        float y = powf(fabs(x), 2.0f/3.0f) + 0.8f * sqrtf(33 - x * x) * sinf(0.01f * a * M_PI * x);
        int screen_y = HEIGHT / 2 - (int)(y * 20);
        SDL_RenderDrawPoint(renderer, i, screen_y);
    }
    
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow("Graph Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    int quit = 0;
    SDL_Event event;
    float a = 1;
    
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        
        draw_graph(renderer, a);
        a += 1;
        SDL_Delay(20);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
