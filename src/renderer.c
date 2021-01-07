#include <renderer.h>


int RenderingTexture(SDL_Renderer* r, SDL_Texture* t, point p, size s){
    SDL_Rect rect;
    NewRect(&rect, p, s);
    return SDL_RenderCopy(r, t, NULL, &rect);
}

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file){
    return (SDL_Texture*)IMG_LoadTexture(renderer, path_file);
}

void NewRect(SDL_Rect* texture_rect, point p, size win){
    texture_rect->x = p.x;
    texture_rect->y = p.y;
    texture_rect->w = win.Width;
    texture_rect->h = win.Height;
}

void NewRect_with_param(SDL_Rect* texture_rect, float x, float y, float width, float height){
    texture_rect->x = x;
    texture_rect->y = y;
    texture_rect->w = width;
    texture_rect->h = height;
}

void CloseWindow(SDL_Renderer* renderer, SDL_Window* win){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);  
    SDL_Quit();
}

