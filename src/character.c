#include <character.h>

void NewCharacter(Character* c, point p, size t_s, int hp, float speed, char* t_p){
   c->Hp = hp;
   c->Speed = speed;
   NewGO(&c->Go, p, t_s, t_p);
}

void RenderingCharacter(SDL_Renderer* renderer, Character* c){
   RenderingGO(renderer, &c->Go);
}