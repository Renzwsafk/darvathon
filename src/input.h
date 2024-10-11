#ifndef INPUT_H 
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "draw.h"
#include "types.h"

typedef struct
{
	int right;
	int left;
	int jump;
	int crouch;	
} Input;


void inputSDL2(SDL_Window *window, SDL_Renderer *renderer, SDL_Event ev);
void keyDown(SDL_KeyboardEvent *event);
void keyUp(SDL_KeyboardEvent *event);


#endif // INPUT_H
