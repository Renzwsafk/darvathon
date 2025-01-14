#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <raylib.h>

class entity
{
public:
    void draw();
    Rectangle id;
    float x, y;
    float width, height;
    int speed;
    int health;
    Color color;
};

#endif // ENTITY_HPP
