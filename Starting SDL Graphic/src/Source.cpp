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

	int x, y; // Top Left Coordinate
	int w, h; // Size of the window from (x, y) Coord 

	// For the Window Functionality:
	// https://web.archive.org/web/20210210112300/http://wiki.libsdl.org/CategoryVideo

	SDL_SetWindowTitle(Window, "Nama Saya ikan");

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

		SDL_GetWindowPosition(Window, &x, &y);
		std::cout << "X: " << x << ",  Y :" << y << std::endl;
	}
	
	SDL_DestroyWindow(Window);
	return 1;
}