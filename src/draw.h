#ifndef DRAW_H 
#define DRAW_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "types.h"

typedef struct
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	u32 windowFlags;
	u32 rendererFlags;
} Draw;

typedef struct
{
	int x, y;
	SDL_Texture *texture;	
} Entity;

SDL_Window *createWindow(const char *name, int pos_x, int pos_y, int width, int height, u32 flags);
SDL_Renderer *createRenderer(SDL_Window *window, u32 flags);
SDL_Texture *drawTexture(char *file);
void drawObject(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b, int a); 
void blit(SDL_Renderer *renderer SDL_Texture *texture, int x, int y;
void pixel(int x, int y, int c);
void drawPixel(void);
void display(void);
void initRenderer(SDL_Renderer *renderer);
void presentRenderer(SDL_Renderer *renderer);

#endif // DRAW_H 
