#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>

#include "input.hpp"
#include "player.hpp"
#include "ui.hpp"

class game
{
public:
    game();
    ~game();
    void handleInput();
private:
    void initGame();
    input key;
};

#endif // GAME_HPP
