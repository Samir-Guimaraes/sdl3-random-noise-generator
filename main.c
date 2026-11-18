#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIGTH 800
#define WINDOW_HEIGHT 600

void print_random_data(SDL_Surface *surface){
    if(surface == NULL){
        printf("Surface is NULL\n");
        return;
    }

    SDL_LockSurface(surface);

    Uint32 *pixels = (Uint32 *) surface->pixels;
    int pitch_in_pixels = surface->pitch / sizeof(Uint32);
    int num_pixel_por_linha = surface->w;

    for(int i = 0; i < surface->h; i++){
        Uint32 *row = pixels + i * pitch_in_pixels;
        for(int j = 0; j <num_pixel_por_linha; j++){
            row[j] = (Uint32)rand();
        }
    }

    SDL_UnlockSurface(surface);
}

int main(int argc, char **argv){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("My broken TV", WINDOW_WIGTH, WINDOW_HEIGHT, 0);
    if(window == NULL){
        fprintf(stderr, "Erro na abertura da janela: %s", SDL_GetError());
        return 1;
        }

    SDL_Surface  *surface = SDL_GetWindowSurface(window);
    if(surface == NULL){
        fprintf(stderr, "Erro ao obter o surface: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    int running = 1;

    while(running){

        SDL_PollEvent(&event);
        if(event.type == SDL_EVENT_QUIT)
            running = 0;

        print_random_data(surface);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(160);
    }

    return 0;
}
