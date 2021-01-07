//Per dire a SDL che si usera' il proprio main applicativo.
//Altrimenti SDL cerca di caricare il main da SDL2Main.lib
//NOTA: Si può passare anche come argomento di compilazione con -D
#define SDL_MAIN_HANDLED

#include <common.h>
#include <renderer.h>
#include <gameobject.h>
#include <character.h>
#include <inputsystem.h>
#include <bullet.h>
#include <list.h>
#include <aiv-vector.h>
#include <map.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    size win = NewSize(HEIGHT_WINDOW, WIDTH_WINDOW);

    SDL_Window* window = SDL_CreateWindow(
        "1945",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        win.Width,
        win.Height,
        0
    );

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create renderer: %s\n", SDL_GetError());
        return 2;
    }
    
    SDL_Texture* ui_texture = NewTexture(renderer,"assets/ui/bottom.png");
    SDL_Texture* hp_texture = NewTexture(renderer,"assets/ui/life.png");
    Character player; 
    NewCharacter(&player,NewPoint(290,180),NewSize(40,40),100,5000.f, "assets/ui/life.png");

    //BULLETS
    List* bullets = list_New();
    Bullet bullet0 = NewBullet(playerBullet);
    Bullet bullet1 = NewBullet(playerBullet);
    Bullet bullet2 = NewBullet(playerBullet);
    Bullet bullet3 = NewBullet(playerBullet);
    Bullet bullet4 = NewBullet(playerBullet);
    Bullet bullet5 = NewBullet(playerBullet);
    list_Add(bullets,&bullet0);
    list_Add(bullets,&bullet1);
    list_Add(bullets,&bullet2);
    list_Add(bullets,&bullet3);
    list_Add(bullets,&bullet4);
    list_Add(bullets,&bullet5);

    //ISLANDS
    List* Islands = list_New();
    GameObject island0 = NewIsland(Normal);
    GameObject island1 = NewIsland(Sand);
    GameObject island2 = NewIsland(Vulcan);
    
    list_Add(Islands, &island0);
    list_Add(Islands, &island1);
    list_Add(Islands, &island2);
    




    Input input;
    InitInputSystem(&input,"wasd");

    Uint64 curr_count = SDL_GetPerformanceCounter();
    Uint64 last_count = curr_count;
    
    double delta_time = 0.f;

    char title[100];
    float update_time = 0.f;
    float time_counter = 0.f;

    boolean done = false; 
    
    while (!done) 
    {
        SDL_RenderClear(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
                break;
            }
            HVInput(renderer, &event, &player, bullets, &input, &win, &delta_time);
        }

        last_count = curr_count;
        curr_count = SDL_GetPerformanceCounter();
        delta_time = (float)(curr_count - last_count) / (float)SDL_GetPerformanceFrequency();
        int fps = (int)(1.f / delta_time);
        
        update_time += delta_time;
        if (update_time >= 1.f) {
            update_time -= 1.f;
            sprintf_s(title, sizeof(title), "Delta Time: %.6f - Fps: %d", delta_time, fps);
            SDL_SetWindowTitle(window, title);
        }
        renderWater(renderer);
        RenderGOList(renderer, Islands, delta_time);
        RenderingBullets(renderer, bullets, delta_time);
        RenderingCharacter(renderer, &player);

         
        //UI Graphic
        RenderingTexture(renderer, ui_texture, NewPoint(0, win.Height - 99), NewSize(win.Width, 100));
        
        RenderingTexture(renderer, hp_texture, NewPoint(100,win.Height - 90), NewSize(40,40));
        RenderingTexture(renderer, hp_texture, NewPoint(55,win.Height - 90), NewSize(40,40));
        RenderingTexture(renderer, hp_texture, NewPoint(10,win.Height - 90), NewSize(40,40));
        // Blit
        SDL_RenderPresent(renderer);
    }
    
    //Clean Up
    CloseWindow(renderer,window);

    list_Destroy(bullets);
    

    return 0;
}
