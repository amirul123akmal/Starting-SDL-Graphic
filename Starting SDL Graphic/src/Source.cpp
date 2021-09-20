#include <iostream>
#include <vector>
#include <string>
#include "SDL.h"

#define FPS 60
#define Wwidth 640
#define Wheight 480

void capFrame(uint32_t Time);

// all of the "Sprite" is based on Python's PyGame Framework
class Sprite
{
protected:
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
		rect.x = x;
		rect.y = y;
	}

	void update()
	{
		// later
	}
	void draw(SDL_Surface* Destination)
	{
		SDL_BlitSurface( image, NULL, Destination, &rect);
	}
	SDL_Surface* get_image() const
	{
		return image;
	}
	bool operator==( const Sprite &other ) const
	{
		return ( image == other.get_image());
	}

};
class SpriteGroup
{
	// <Sprite*> is to make sure all the data in each object are same
	std::vector<Sprite*> sprites;
	int spriteSize = 0;
public:
	SpriteGroup copy()
	{
		SpriteGroup new_group;
		for (int i = 0 ; i < spriteSize; i++ )
		{
			new_group.add(sprites[i]);
		}
	}
	void add(Sprite *sprite)
	{
		sprites.push_back(sprite);
		spriteSize = sprites.size();
	}
	void remove( Sprite sprite_object)
	{
		for (int i = 0 ; i < spriteSize ; i++)
		{
			if ( *sprites[i] == sprite_object)
			{
				sprites.erase(sprites.begin() + i);
			}
			spriteSize = sprites.size();
		}
	}
	bool has( Sprite sprite_obj)
	{
		for (int i = 0; i < spriteSize; i++)
		{
			if (*sprites[i] == sprite_obj)
			{
				return true;
			}
			return false;
		}
	}
	void update()
	{
		if (!sprites.empty())
		{
			for (int i = 0; i < spriteSize; i++)
			{
				sprites[i]->update();
			}
		}
	}
	void draw(SDL_Surface * Destination)
	{
		if (!sprites.empty())
		{
			for (int i = 0; i < spriteSize; i++)
			{
				sprites[i]->draw(Destination);
			}
		}
	}
	void empty()
	{
		sprites.clear();
		spriteSize = sprites.size();
	}
	int size()
	{
		return spriteSize;
	}
	std::vector<Sprite*> getSprites()
	{
		return sprites;
	}

};
class Block : public Sprite
{
public:
	Block(uint32_t color, int x, int y, int w = 64, int h = 48) :
	Sprite(color, x, y, w, h)
	{
		update_properties();
	}
	void update_properties()
	{
		OriginX = 0;
		OriginY = 0;

		set_position(rect.x, rect.y);
	}
	void set_position(int x, int y)
	{
		rect.x = x - OriginX;
		rect.y = y - OriginY;
	}
	void set_image(const char filename[])
	{
		if (filename != NULL)
		{
			SDL_Surface* loaded_image = SDL_LoadBMP(filename);

			if (loaded_image != NULL)
			{
				image = loaded_image;
				int old_x = rect.x, old_y = rect.y;

				rect = image->clip_rect;

				rect.x = old_x;
				rect.y = old_y;

				update_properties();

			}
			else
			{
				std::cout << "Failed loading images" << std::endl;
			}
		}
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
	uint32_t blue = SDL_MapRGB(Screen->format, 0, 0, 255);
	SDL_FillRect(Screen, NULL, color);

	Block block(red, 0, 0);
	block.set_image("res/ES31_willowisp.bmp");
	Block block2(blue, 100, 100);

	SpriteGroup active_sprite;
	active_sprite.add(&block);
	active_sprite.add(&block2);
	
	// active_sprite.remove(red_box);

	active_sprite.draw(Screen);

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