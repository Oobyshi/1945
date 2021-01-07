#include <gameobject.h>

void NewGO(GameObject* go, point p, size t_s, char* t_p){
    go->position = p;
    go->t_path = t_p;
    go->t_size = t_s;
}

void RenderingGO(SDL_Renderer* renderer, GameObject* go){
   SDL_Texture* texture = NewTexture(renderer, go->t_path);
   RenderingTexture(renderer,texture, go->position, go->t_size);
   SDL_DestroyTexture(texture);
}
