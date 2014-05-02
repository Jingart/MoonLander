#include "spaceship.h"

const float Spaceship::NATURAL_G = 0.00000981;


Spaceship::Spaceship(void)
{
	//Initialize the offsets
	//mPosX = SCREEN_WIDTH / 2 - DOT_WIDTH / 2;
	//mPosY = SCREEN_HEIGHT - DOT_HEIGHT;

	//jetX = SCREEN_WIDTH / 2;
	//jetY = SCREEN_HEIGHT;

	

	mPosX = 0;
	mPosY = 0;

	jetX = DOT_WIDTH / 2;
	jetY = DOT_HEIGHT / 2;

    landerSpeedX = 0;
    landerSpeedY = 0;

	jetAccelerationX = 0;
	jetAccelerationY = 0;

	//mAcceleration = 50.f;
	//mMaxSpeed = 1000.f;
}


Spaceship::~Spaceship(void)
{
}


void Spaceship::handleEvent(SDL_Event& e, float deltaTime)
{
    //If a key was pressed
	//if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
 //   {
 //       //Adjust the velocity
 //       switch( e.key.keysym.sym )
 //       {
 //           case SDLK_UP: mVelY -= DOT_VEL; break;
 //           case SDLK_DOWN: mVelY += DOT_VEL; break;
 //           case SDLK_LEFT: mVelX -= DOT_VEL; break;
 //           case SDLK_RIGHT: mVelX += DOT_VEL; break;
 //       }
 //   }
 //   //If a key was released
 //   else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
 //   {
 //       //Adjust the velocity
 //       switch( e.key.keysym.sym )
 //       {
 //           case SDLK_UP: mVelY += DOT_VEL; break;
 //           case SDLK_DOWN: mVelY -= DOT_VEL; break;
 //           case SDLK_LEFT: mVelX += DOT_VEL; break;
 //           case SDLK_RIGHT: mVelX -= DOT_VEL; break;
 //       }
 //   }






	//If a key was pressed
	//if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
 //   {
 //       //Adjust the velocity
 //       switch( e.key.keysym.sym )
 //       {
 //           case SDLK_UP: 
	//			mSpeedY -= deltaTime * mAcceleration; 
	//			break;
 //           case SDLK_DOWN: 
	//			mSpeedY += deltaTime * mAcceleration; 
	//			break;
 //           case SDLK_LEFT: 
	//			mSpeedX -= deltaTime * mAcceleration; 
	//			break;
 //           case SDLK_RIGHT: 
	//			mSpeedX += deltaTime * mAcceleration; 
	//			break;
 //       }
 //   }
}

void Spaceship::move(float deltaTime)
{
    ////Move the dot left or right
    //mPosX += mSpeedX;

    ////If the dot went too far to the left or right
    //if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    //{
    //    //Move back
    //    mPosX -= mSpeedX;
    //}

    ////Move the dot up or down
    //mPosY += mSpeedY;

    ////If the dot went too far up or down
    //if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    //{
    //    //Move back
    //    mPosY -= mSpeedY;
    //}

	mPosX = mPosX += landerSpeedX/deltaTime;
	mPosY = mPosY += landerSpeedY/deltaTime;
	
	landerSpeedY = landerSpeedY += NATURAL_G/deltaTime;
	if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        landerSpeedY = 0;
    }

	

}

void Spaceship::render(Texture &texture)
{
    //Show the dot
	texture.render( mPosX, mPosY );
}