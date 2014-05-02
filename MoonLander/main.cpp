#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Spaceship.h"
#include "Texture.h"
#include "Graphics.h"
#include <windows.h>
#include "GameTimer.h"

using namespace std;

Texture gLanderTexture;
GameTimer gTimer;

bool initSDL()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		Graphics::gWindow = SDL_CreateWindow( "MoonLander", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( Graphics::gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			Graphics::gRenderer = SDL_CreateRenderer( Graphics::gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( Graphics::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	char buffer[MAX_PATH];
	GetModuleFileName( NULL, buffer, MAX_PATH );

	char *pos = strrchr(buffer, '\\');
	if (pos != NULL) 
	   *pos = '\0';

	string p(buffer);

	//Load dot texture
	//if( !gLanderTexture.loadFromFile( "Release/lander.png" ) )
	if( !gLanderTexture.loadFromFile( p + "\\Assets\\lander.png" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gLanderTexture.free();

	//Destroy window	
	SDL_DestroyRenderer( Graphics::gRenderer );
	SDL_DestroyWindow( Graphics::gWindow );
	Graphics::gWindow = NULL;
	Graphics::gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Init timer by reseting
	gTimer.Reset();

	//Start up SDL and create window
	if( !initSDL() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Spaceship ship;

			//While application is running
			while( !quit )
			{
				//Tick timer forward
				gTimer.Tick();

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					//Handle input for the dot
					ship.handleEvent(e, gTimer.DeltaTime());
				}

				//Move the dot
				ship.move();

				//Clear screen
				SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( Graphics::gRenderer );

				//Render objects
				ship.render(gLanderTexture);

				//Update screen
				SDL_RenderPresent( Graphics::gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	//if(!success)
	string str;
	cin >> str;

	return 0;
}