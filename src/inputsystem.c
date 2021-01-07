#include <inputsystem.h>
#include <stdio.h>


void InitButtons(Input* input, char* movement_sequence_type){
    if(!SDL_strcmp(movement_sequence_type,"wasd")){
       input->up = SDL_SCANCODE_W;
       input->left = SDL_SCANCODE_A;
       input->down = SDL_SCANCODE_S;
       input->right = SDL_SCANCODE_D;
       input->shoot = SDL_SCANCODE_SPACE;
    }
    else if(!SDL_strcmp(movement_sequence_type,"arrow")){
       input->up = SDL_SCANCODE_UP;
       input->left = SDL_SCANCODE_LEFT;
       input->down = SDL_SCANCODE_DOWN;
       input->right = SDL_SCANCODE_RIGHT;
       input->shoot = SDL_SCANCODE_SPACE;
    }
}

void InitInputSystem(Input* input, char* buttons){
    input->IsActive = true;
    InitButtons(input, buttons);
}

void HorizontalInput(SDL_Renderer* renderer, SDL_Event* event, Character* c, List* b_list, Input* input, size* size, double* deltaTime){
   if(input->IsActive){
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.scancode == input->left){
                if(c->Go.position.x > 0){
                    c->Go.position.x += -1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->right){
                if(c->Go.position.x < size->Width - c->Go.t_size.Width){
                    c->Go.position.x += 1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->shoot){
                Shoot(renderer, c, b_list, size, deltaTime);
            }
        }
    }
}

void VerticalInput(SDL_Renderer* renderer, SDL_Event* event, Character* c, List* b_list, Input* input, size* size, double* deltaTime){
    if(input->IsActive){
        if(event->type == SDL_KEYDOWN){
           if(event->key.keysym.scancode == input->up){
                if(c->Go.position.y > 0){
                    c->Go.position.y += -1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->down){
               if(c->Go.position.y < (size->Height - 100) - c->Go.t_size.Height){
                    c->Go.position.y += 1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->shoot){
                Shoot(renderer, c, b_list, size, deltaTime);
            }
        }
    }
}

void HVInput(SDL_Renderer* renderer, SDL_Event* event, Character* c, List* b_list, Input* input, size* size, double* deltaTime){

    if(input->IsActive){
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.scancode == input->up){
                if(c->Go.position.y > 0){
                    c->Go.position.y += -1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->left){
                if(c->Go.position.x > 0){
                    c->Go.position.x += -1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->down){
                if(c->Go.position.y < (size->Height - 100) - c->Go.t_size.Height){
                    c->Go.position.y += 1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->right){
                if(c->Go.position.x < size->Width - c->Go.t_size.Width){
                    c->Go.position.x += 1 * c->Speed * (*deltaTime);
                }
            }

            if(event->key.keysym.scancode == input->shoot){
                Shoot(renderer, c, b_list, size, deltaTime);
            }
        }
    }
}

void Shoot(SDL_Renderer* renderer, Character* c, List* b_list, size* size, double* deltaTime){
    if(c->Go.position.y > 0){
        int count = 0;
        int index = 0;
        Lnode* each = b_list->__head;
        while(each){
            Lnode* next = each->next;
            if (!((Bullet*)each->data)->isActive){
                ((Bullet*)each->data)->isActive = true;
                ((Bullet*)each->data)->Go.position.x = c->Go.position.x +(c->Go.t_size.Width * 0.5f) - 5;
                 ((Bullet*)each->data)->Go.position.y = c->Go.position.y +((Bullet*)each->data)->Go.t_size.Height;
                index = count;
                break;
            }
            count++;
            each = next;
        }
    }
}