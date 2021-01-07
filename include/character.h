#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobject.h"

typedef struct 
{
    GameObject Go;
    int Hp;
    float Speed;
} Character;


void NewCharacter(Character* c, point p, size t_s, int hp, float speed, char* t_p);
void RenderingCharacter(SDL_Renderer* renderer, Character* c);
#endif /*CHARACTER_H*/