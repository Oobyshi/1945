#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//includes
#include "common.h"
#include "renderer.h"

typedef struct {
    point position;
    size t_size;
    char* t_path;
} GameObject;

//prototypes
void NewGO(GameObject* go, point p, size t_s, char* t_p);
void RenderingGO(SDL_Renderer* renderer, GameObject* go);

#endif /*GAMEOBJECT_H*/