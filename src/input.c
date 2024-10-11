#include "input.h"

void inputSDL2(SDL_Window *window, SDL_Renderer *renderer, SDL_Event event, Input input)
{

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				printf("Thanks for playing! (^_^)\n");
				printf("Quiting...\n");
				exit(0);
				break;
			case SDL_KEYDOWN:
				keyDown(event.key, input);
			       	break;
			case SDL_KEYUP:
				keyUp(event.key, input);
				break;	

			default:
				break;
		}
	}
}

void keyDown(SDL_KeyboardEvent *event, Input input)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_D)
		{
			input.right = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_A)
		{
			input.left = 1;
		}

	}
}	

void keyUp(SDL_KeyboardEvent *event, Input input)
{
	if (event->repeat == 1)
	{
		if (event->keysym.scancode == SDL_SCANCODE_D)
		{
			input.right = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_A)
		{
			input.left = 0;
		}
	}
}

