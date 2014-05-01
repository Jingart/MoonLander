#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class Spaceship
{
public:


	//The dimensions of the dot
	static const int DOT_WIDTH = 78;
	static const int DOT_HEIGHT = 78;

	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	//Dot();
	Spaceship(void);
	~Spaceship(void);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent( SDL_Event& e );
	void move();
	void render(Texture &texture);

private:

	int mPosX, mPosY;
	int mVelX, mVelY;
};





