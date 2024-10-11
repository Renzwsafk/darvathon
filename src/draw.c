#include "draw.h"

SDL_Window *createWindow(const char *name, int pos_x, int pos_y, int width, int height, u32 flags)
{
	printf("Creating %s window...\n", name);

	SDL_Window *window = SDL_CreateWindow(name, pos_x, pos_y, width, height, flags);
	
	if (window == NULL)
	{
		fprintf(stderr, "Failed to create %s window. SDL2 error: %s\n", name, SDL_GetError());
		exit(1);
	}

	printf("%s window successfully created\n", name);

	return window;
}

SDL_Renderer *createRenderer(SDL_Window *window, u32 flags)
{
	
	printf("Creating renderer\n");

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, flags);	
	
	if (renderer == NULL)
	{
		fprintf(stderr, "Failed to create renderer. SDL2 error: %s\n", SDL_GetError());
		exit(1);
	}

	printf("Renderer successfully created\n");	

	return renderer;
}

SDL_Texture *loadTexture(SDL_Renderer *renderer, char *file)
{
	SDL_Texture *texture;
	SDL_LogMessages(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", file);	
	texture = IMG_LoadTexture(renderer, file);
	return texture;
}

void blit(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void pixel(SDL_Renderer *render, int x, int y, int c)
{
	int rgb[3];
	if (c == 0) {rgb[0] = 255; rgb[1] = 0; rgb[2] = 0;} 	// RED
       	if (c == 1) {rgb[0] = 0; rgb[1] = 255; rgb[2] = 0;} 	// GREEN
	if (c == 2) {rgb[0] = 0; rgb[1] = 0; rgb[2] = 255;} 	// BLUE
	if (c == 3) {rgb[0] = 0; rgb[1] = 255; rgb[2] = 255;} 	// CYAN	
	if (c == 4) {rgb[0] = 0; rgb[1] = 90; rgb[2] = 0;}	// DARK GREEN	
	if (c == 5} {rgb[0] = 0; rgb[1] = 0; rgb[2] = 50;}	// BACKGROUND 
								
	SDL_RenderDrawColor(render, rgb[0], rgb[1], rgb[2], 255);
	SDL_RenderDrawPoint(render, x*PIXELSCALE+2, y*PIXELSCALE+2)

}

void clearBackground(SDL_Renderer *render, int SW, int SH)
{
	int x, y;
	for (y = 0; y < SH; y++)
	{
		for (x = 0; x < SW; x++)
		{
			pixel(render, x, y, 5);
		}
	}
}

void draw3D(Draw self)
{

}

void initRenderer(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void presentRenderer(SDL_Renderer *renderer)
{
	SDL_RenderPresent(renderer);
}
