#include "Velocity.h"

/*************************************************************************
 * Constructor to initialize velocity
 *************************************************************************/
Velocity::Velocity(double velocity, double angle)
{
   this->velocityX = velocity * cos(angle);
   this->velocityY = velocity * sin(angle);
}

/*************************************************************************
 * Constructor to initialize everything to 0;
 *************************************************************************/
Velocity::Velocity()
{
   velocityX = 0;
   velocityY = 0;
}

/*************************************************************************
 * adds acceleration to the components
 *************************************************************************/
void Velocity::update(double accelerationX, double accelerationY)
{
   velocityX += accelerationX;
   velocityY += accelerationY;
}

/*************************************************************************
 * Getters for the components
 *************************************************************************/
double Velocity::getVelocityX() const
{
   return velocityX;
}

double Velocity::getVelocityY() const
{
   return velocityY;
}

/*************************************************************************
 * Getters for the total velocity (used for speed)
 *************************************************************************/
double Velocity::getTotalVelocity() const
{
   return std::sqrt(velocityX * velocityX + velocityY * velocityY);
}