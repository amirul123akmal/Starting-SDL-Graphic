#include <iostream>
#include <string>
#include "SDL.h"

#define FPS 60
#define Wwidth 640
#define Wheight 480

void capFrame(uint32_t Time);


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
	SDL_FillRect(Screen, NULL, color);

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