#include "bullet.h"

Bullet NewBullet(BulletType bulletType){
   Bullet bullet;
   if(bulletType == playerBullet){
        bullet.Damage = 30;
        bullet.Speed = 100;
        bullet.Go.isActive = false;
        bullet.Go.position = NewPoint(20,20);
        bullet.Go.t_path = "assets/player/bullet.png";
        bullet.Go.t_size = NewSize(10,10); // in base alla texture usata cambia la size
        //NewGameObject(&bullet.Go, *p, NewSize(10,10) ,"playerbullet");
    }
    else if(bulletType == enemyBullet)
    {
        bullet.Damage = 20;
        bullet.Speed = -10;
        bullet.Go.isActive = false;
        bullet.Go.position = NewPoint(20,20);
        bullet.Go.t_path = "assets/enemy/enemybullet1.png";
        bullet.Go.t_size = NewSize(10,10); // in base alla texture usata cambia la size
    }
    else if(bulletType == normal)
    {
        bullet.Damage = 10;
        bullet.Speed = 10;
        bullet.Go.isActive = false;
        bullet.Go.position = NewPoint(20,20);
        bullet.Go.t_path = "assets/enemy/enemybullet2.png";
        bullet.Go.t_size = NewSize(10,10); // in base alla texture usata cambia la size
    }
    return bullet;
}

void RenderingBullet(SDL_Renderer* renderer, Bullet* b){
    if(b->Go.position.y < 0){
        b->Go.isActive = false;
    }
    else{
        RenderingGO(renderer, &b->Go);
    }
}

void RenderingBullets(SDL_Renderer* renderer, List* b_list, float deltaTime){
    int count = 0;
    Lnode* each = b_list->__head;
    Bullet* free_b;
    while (each)
    {
        Lnode* next = each->next;
        if(((Bullet*)each->data)->Go.isActive){
            free_b = (Bullet*)each->data;
            free_b->Go.position.y += -1 * free_b->Speed * deltaTime;
            RenderingBullet(renderer, free_b);
        }
        count++;
        each = next;
    }
    
}