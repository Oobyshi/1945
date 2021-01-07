#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "common.h"
#include "list.h"
#include "character.h"
#include "bullet.h"


typedef struct 
{
    boolean IsActive;
    SDL_Scancode up;
    SDL_Scancode left;
    SDL_Scancode down;
    SDL_Scancode right;
    SDL_Scancode shoot;
} Input;

void InitButtons(Input* buttons, char* movement_sequence_type);
void InitInputSystem(Input* input, char* buttons);
void HorizontalInput(SDL_Renderer* renderer, SDL_Event* event, Character* c, List* b_list, Input* input, size* size, double* deltaTime);
void VerticalInput(SDL_Renderer* renderer, SDL_Event* event, Character* c, List* b_list, Input* input, size* size, double* deltaTime);
void HVInput(SDL_Renderer* renderer, SDL_Event* event, Character* c, List* b_list, Input* input, size* size, double* deltaTime);
void Shoot(SDL_Renderer* renderer, Character* c, List* bullets, size* size, double* deltaTime);
#endif /*INPUT_SYSTEM_H*/