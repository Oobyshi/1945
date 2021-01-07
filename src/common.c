#include <common.h>

size NewSize(float width, float height){
    size s;
    s.Width = width;
    s.Height = height;
    return s;
}

point NewPoint(float x, float y){
    point p;
    p.x = x;
    p.y = y;
    return p;
}

