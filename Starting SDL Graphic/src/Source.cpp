#include <iostream>
#include <string>
#include "SDL.h"

#define FPS 60
#define Wwidth 640
#define Wheight 480

void capFrame(uint32_t Time);

class Sprite
{
	SDL_Surface* image = NULL;
	SDL_Rect rect;

	int OriginX = 0, OriginY = 0;
public:

	Sprite(uint32_t color, int x, int y, int w = 64, int h = 48)
	{
		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
		SDL_FillRect(image, NULL, color);

		rect = image->clip_rect;
		OriginX = rect.w / 2;
		OriginY = rect.h / 2;
		rect.x = x - OriginX;
		rect.y = y - OriginY;
	}

	void update()
	{
		// later
	}

	void draw(SDL_Surface* Destination)
	{
		SDL_BlitSurface( image, NULL, Destination, &rect);
	}

};

int main(int argc, char* argv[])
{
	// SDL quit at exit
	atexit(SDL_Quit);

	// SDL initialization
	SDL_Init(SDL_INIT_EVERYTHING);

	// SDL Window
	// Must be a pointer
	SDL_Window* Window = NULL;

	// Create Window
	// Give the creation to the `Window Var`
	Window = SDL_CreateWindow("Main Application", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Wwidth, Wheight, SDL_WINDOW_RESIZABLE);

	// FPS Limitingg
	uint8_t Ticks;

	SDL_Event event;
	bool Running = true;

	// For the Window Functionality:
	// https://wiki.libsdl.org/CategoryVideo

	// Get Window's Surface so we can modify it
	SDL_Surface* Screen = SDL_GetWindowSurface(Window);
	uint32_t color = SDL_MapRGB(Screen->format, 100, 200, 255);
	uint32_t red = SDL_MapRGB(Screen->format, 255, 0, 0);
	SDL_FillRect(Screen, NULL, color);

	Sprite application(red, Wwidth / 2, Wheight / 2);
	application.draw(Screen);

	// To Update The Screen
	// Any draw please put before this line
	SDL_UpdateWindowSurface(Window);  

	while (Running)
	{
		Ticks = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			// Detect if we press "X" to close our window
			if (event.type == SDL_QUIT)
			{
				Running = false;
				break;
			}
		}
		capFrame(Ticks);
		
	}
	SDL_DestroyWindow(Window);
	return 1;
}

void capFrame(uint32_t Time)
{
	if ((1000 / FPS) > SDL_GetTicks() - Time)
	{
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - Time));
	}
}