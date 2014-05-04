#include "spaceship.h"

const float Spaceship::NATURAL_G = 0.00003;
const float Spaceship::JET_POWER = 0.0001;

Spaceship::Spaceship(void)
{
	mPosX = Graphics::SCREEN_WIDTH / 2 - DOT_WIDTH / 2;
	mPosY = Graphics::SCREEN_HEIGHT - DOT_HEIGHT;

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

//float Spaceship::ApplyGravity()
//{
//	landerSpeedY = landerSpeedY += NATURAL_G / mDeltaTime;
//	return
//}

void Spaceship::Update(float deltaTime, Action landerAction)
{
	mDeltaTime = deltaTime;

	mPosX = mPosX += landerSpeedX/deltaTime;
	mPosY = mPosY += landerSpeedY/deltaTime;
	
	landerSpeedY = landerSpeedY += NATURAL_G / mDeltaTime;


	if(landerSpeedX > 0) {
		landerSpeedX -= 0.0001f / mDeltaTime;
	}
	else if(landerSpeedX < 0) {
		landerSpeedX += 0.0001f / mDeltaTime;
	}



	if(mPosX < 0)
        mPosX = 0;
	else if( mPosX + DOT_WIDTH > Graphics::SCREEN_WIDTH ) {
		landerSpeedX = 0;
		mPosX = Graphics::SCREEN_WIDTH - DOT_WIDTH;
	}

	if(mPosY < 0)
        mPosY = 0;
	else if( mPosY + DOT_HEIGHT > Graphics::SCREEN_HEIGHT ) {
		landerSpeedY = 0;
		mPosY = Graphics::SCREEN_HEIGHT - DOT_HEIGHT;
	}


	//jetAccelerationY = 0;
	//jetAccelerationX = 0;

	if(landerAction == Action::moveup)
	{
		landerSpeedY = landerSpeedY -= JET_POWER/deltaTime;
	}

	if(landerAction == Action::movedown)
	{
		landerSpeedY = landerSpeedY += JET_POWER/deltaTime;
	}

	if(landerAction == Action::moveright)
	{
		landerSpeedX = landerSpeedX += JET_POWER/deltaTime * 2;
	}

	if(landerAction == Action::moveleft)
	{
		landerSpeedX = landerSpeedX -= JET_POWER/deltaTime * 2;
	}

}

void Spaceship::Render(Texture &texture)
{
	texture.render( mPosX, mPosY );
}