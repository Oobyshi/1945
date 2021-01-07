#ifndef COMMON_H
#define COMMON_H

// includes
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum boolean_enum { false, true };
typedef unsigned char boolean;

typedef unsigned int uint;

typedef struct {
    float x;
    float y;
} vec2;

typedef struct{
    float Width;
    float Height;
} size;

typedef struct{
    float x;
    float y;
} point;

// prototypes
size  NewSize(float width, float height);
point NewPoint(float x, float y);

#endif /*COMMON_H*/