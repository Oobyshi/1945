#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//includes
#include "common.h"
#include "renderer.h"

typedef struct {
    point position;
    size t_size;
    char* t_path;
    boolean isActive;
} GameObject;

enum IslandsType{Normal = 0, Vulcan, Sand};
typedef enum IslandsType_ IslandsType;

//prototypes
void NewGO(GameObject* go, point p, size t_s, char* t_p);
void RenderingGO(SDL_Renderer* renderer, GameObject* go);
point RandomPoint(size* s);
GameObject NewIsland(IslandsType it);
void RenderGOList(SDL_Renderer* renderer, List* goList, float deltaTime);
void RenderGOActive(SDL_Renderer* renderer, GameObject* go);

#endif /*GAMEOBJECT_H*/