#include "stdafx.h"
#include "Engine.h"


#include <iostream>

#include <SDL\SDL.h>
#include <stdio.h>

#include "Scene.h"
#include "SceneManager.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* Scott = NULL;

SDL_Rect *ImageRect = new SDL_Rect;

namespace core
{


	Engine::Engine(scene::Scene *s)
	{
	}


	Engine::~Engine()
	{
	}

	int Engine::init()
	{

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

			//Load Splash Image
			Scott = SDL_LoadBMP( "scottjetski.bmp" );

			// Create Window
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}


			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Fill the surface white #FFFFFF
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));

				// Apply the image
				SDL_BlitSurface(Scott, NULL, screenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(window);

				//Wait two seconds
				SDL_Delay(2000);
			}
		}

		
		//Deallocate surface
		SDL_FreeSurface(Scott);
		Scott = NULL;

		//Destroy window
		SDL_DestroyWindow(window);
		window = NULL;

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}

	void Engine::print()
	{
		std::cout << "this is working" << std::endl;
	}

	void Engine::update()
	{
		Scene1->update();

		SDL_Event e;

		while (SDL_PollEvent(&e) != 0) {

			switch (e.type) {

			case SDL_KEYDOWN:

				switch (e.key.keysym.sym) {

				case SDLK_LEFT:
					
					ImageRect->x--;
					break;

				case SDLK_RIGHT:
					
					ImageRect->x++;
					break;

				case SDLK_DOWN:
					
					ImageRect->y++;
					break;

				case SDLK_UP:
					
					ImageRect->y-- ;
					break;
				}
				break;


			}
		}

		

	}

}