#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

class player : public entity
{
public:
    player(Vector2 position, float width, float height, Color color);
    ~player();
}

#endif // PLAYER_HPP