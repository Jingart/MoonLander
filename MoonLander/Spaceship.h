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

	static const float NATURAL_G;

	//Maximum axis velocity of the dot
	//static const int DOT_VEL = 10;

	//Initializes the variables
	//Dot();
	Spaceship(void);
	~Spaceship(void);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e , float deltaTime);
	void move(float deltaTime);
	void render(Texture &texture);

private:

	//float mAcceleration;
	//float mMaxSpeed;

	float mPosX; 
	float mPosY;

	float landerSpeedX;
	float landerSpeedY;

	float jetY;
	float jetX;

	float jetAccelerationY;
	float jetAccelerationX;
};





