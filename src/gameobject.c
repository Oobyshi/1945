#include <gameobject.h>

void NewGO(GameObject* go, point p, size t_s, char* t_p){
    go->position = p;
    go->t_path = t_p;
    go->t_size = t_s;
    go->isActive = true;
}

void RenderingGO(SDL_Renderer* renderer, GameObject* go){
   SDL_Texture* texture = NewTexture(renderer, go->t_path);
   RenderingTexture(renderer,texture, go->position, go->t_size);
   SDL_DestroyTexture(texture);
}

point RandomPoint(size* s)
{
    int posX = GetRandomInRange(WIDTH_WINDOW - 1, 0);
    int posY = -GetRandomInRange(s->Height - 300, s->Height);
    printf("random x: %d y: %d \n ", posX, posY);

    return NewPoint(posX, posY);
}

GameObject NewIsland(IslandsType it)
{
    GameObject go;
    go.isActive = true;
    if(it == Normal)
    {
        go.t_size = NewSize(25, 45);
        go.position = RandomPoint(&go.t_size);
        go.t_path = "./assets/map/island1.png";
    }
    else if(it == Vulcan)
    {
        go.t_size = NewSize(40, 40);
        go.position = RandomPoint(&go.t_size);
        go.t_path = "./assets/map/island2.png";
    }
    else if(it == Sand)
    {
        go.t_size = NewSize(40, 40);
        go.position = RandomPoint(&go.t_size);
        go.t_path = "./assets/map/island3.png";
    }
    return go;
}



void RenderGOList(SDL_Renderer* renderer, List* goList, float deltaTime)
{
    int speed = 25;
    int count = 0;
    Lnode* each = goList->__head;
    GameObject* free_GO;
    while (each)
    {
        Lnode* next = each->next;
        if(((GameObject*)each->data)->isActive){
            free_GO = (GameObject*)each->data;
            free_GO->position.y += 1 * speed * deltaTime;
            RenderGOActive(renderer, free_GO);
        }
        count++;
        each = next;
    }
}

void RenderGOActive(SDL_Renderer* renderer, GameObject* go)
{
    if(go->position.y > 380 + go->t_size.Height){ //380 ref win height - UI
        //go->isActive = false;
        go->position = RandomPoint(&go->t_size);
    }
    else{
        RenderingGO(renderer, go);
    }
}

