#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Graphics.h"

class Spaceship
{
public:

	//The dimensions of the dot
	static const int DOT_WIDTH = 78;
	static const int DOT_HEIGHT = 78;

	static const float NATURAL_G;
	static const float JET_POWER;

	enum Action{
		idle,
		moveup,
		movedown,
		moveleft,
		moveright
	};

	//Maximum axis velocity of the dot
	//static const int DOT_VEL = 10;

	//Initializes the variables
	//Dot();
	Spaceship(void);
	~Spaceship(void);

	//Takes key presses and adjusts the dot's velocity
	//void handleEvent(SDL_Event& e , float deltaTime);
	void Update(float deltaTime, Action landerAction);
	void Render(Texture &texture);

private:

	//float mAcceleration;
	//float mMaxSpeed;
	float ApplyGravity();

	float mPosX; 
	float mPosY;

	float landerSpeedX;
	float landerSpeedY;

	float jetY;
	float jetX;

	float jetAccelerationY;
	float jetAccelerationX;

	float mDeltaTime;
};





