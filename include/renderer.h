#ifndef RENDERER_H
#define RENDERER_H

//includes
#include "common.h"

//prototypes
int RenderingTexture(SDL_Renderer* r, SDL_Texture* t, point p, size s);
SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file);
void NewRect(SDL_Rect* texture_rect, point p, size s);
void NewRect_with_param(SDL_Rect* texture_rect, float x, float y, float width, float height);
void CloseWindow(SDL_Renderer* renderer, SDL_Window* win);

#endif /*RENDERER_H*/