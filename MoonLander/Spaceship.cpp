#include "spaceship.h"

const float Spaceship::NATURAL_G = 0.000015;
const float Spaceship::JET_POWER = 0.0001;

Spaceship::Spaceship(void)
{
	mPosX = SCREEN_WIDTH / 2 - DOT_WIDTH / 2;
	mPosY = SCREEN_HEIGHT - DOT_HEIGHT;

	//jetX = SCREEN_WIDTH / 2;
	//jetY = SCREEN_HEIGHT;

	//jetX = DOT_WIDTH / 2;
	//jetY = DOT_HEIGHT / 2;

    landerSpeedX = 0;
    landerSpeedY = 0;

	jetAccelerationX = 0;
	jetAccelerationY = 0;
}


Spaceship::~Spaceship(void)
{
}

void Spaceship::Update(float deltaTime, Action landerAction)
{
	mPosX = mPosX += landerSpeedX/deltaTime;
	mPosY = mPosY += landerSpeedY/deltaTime;
	
	landerSpeedY = landerSpeedY += NATURAL_G/deltaTime;
	landerSpeedX = 0;

	if(mPosY < 0)
        mPosY = 0;
	else if( mPosY + DOT_HEIGHT > SCREEN_HEIGHT )
		landerSpeedY = 0;

	//jetAccelerationY = 0;
	//jetAccelerationX = 0;

	if(landerAction == Action::moveup)
	{
		//if(jetAccelerationY < 3)
		//{
		//	jetAccelerationY += 1;
		//}

		landerSpeedY = landerSpeedY -= JET_POWER/deltaTime;
		//rectangle.setY(landerY);
		//jetY = jetY += delta * 2;
	}

	if(landerAction == Action::movedown)
	{
		landerSpeedY = landerSpeedY += JET_POWER/deltaTime;
	}

	if(landerAction == Action::moveright)
	{
		landerSpeedX = landerSpeedX += JET_POWER/deltaTime * 10;
	}

	if(landerAction == Action::moveleft)
	{
		landerSpeedX = landerSpeedX -= JET_POWER/deltaTime * 10;
	}

}

void Spaceship::Render(Texture &texture)
{
	texture.render( mPosX, mPosY );
}