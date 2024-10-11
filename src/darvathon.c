#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <inttypes.h>
#include <unistd.h>

#include "draw.h"
#include "types.h"
#include "input.h"

#define res	1
#define 

typedef struct
{
	int frame1, frame2;
} time;


void cleanUp(void)
{
	SDL_DestroyWindow(draw.window);
	SDL_DestroyRenderer(draw.renderer);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	
	memset(&draw, 0, sizeof(Draw));
	memset(&input, 0, sizeof(Input));
	memset(&player, 0, sizeof(Entity));

	draw.windowFlags = SDL_WINDOW_SHOWN;
	draw.rendererFlags = SDL_RENDERER_ACCELERATED;

	printf("Initializing SDL2...\n");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Failed to initialize SDL2. SDL2 error: %s\n", SDL_GetError());
		exit(1);	
	}		

	printf("SDL2 initialized\n"); 
	
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	draw.window = createWindow("Darvathon", 30, 30, 800, 800, draw.windowFlags);	
	draw.renderer = createRenderer(draw.window, draw.rendererFlags);
	player.texture = drawTexture("res/gfx/player.png"); 
	player.x = 100;
	player.y = 100;	

	atexit(cleanUp);

	SDL_Event ev;

	while (1)
	{
		initRenderer(draw.renderer);
		inputSDL2(draw.window, draw.renderer, ev);	

		if (input.right)
		{
			player.x += 4;	
		}

		if (input.left)
		{
			player.x -= 4;
		}

		blit(draw.renderer);
		presentRenderer(draw.renderer);
	}

	return 0;
}
