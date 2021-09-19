#include <iostream>
#include <string>
#include "SDL.h"

int main(int argc, char* argv[])
{
	// SDL quit at exit
	atexit(SDL_Quit);

	// SDL initialization
	SDL_Init(SDL_INIT_EVERYTHING);

	// SDL Window
	// Must be a pointer
	SDL_Window* Window;

	// Create Window
	// Give the creation to the `Window Var`
	Window = SDL_CreateWindow("Main Application", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);

	SDL_Event event;
	bool Running = true;

	while (Running)
	{
		while (SDL_PollEvent(&event))
		{
			// Detect if we press "X" to close our window
			if (event.type == SDL_QUIT)
			{
				Running = false;
				break;
			}
		}
	}
	
	SDL_DestroyWindow(Window);
	return 1;
}