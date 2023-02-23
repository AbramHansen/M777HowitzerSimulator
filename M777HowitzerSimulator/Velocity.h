#pragma once
#include <cmath>

/*************************************************************************
 * Veloity
 * holds the velocity of an object and updates it from an acceleration
 *************************************************************************/
class Velocity
{
private:
   double velocityX;
   double velocityY;

public:
   Velocity(double velocityX, double velocityY);
   Velocity();
   void update(double accelerationX, double accelerationY);

   double getVelocityX() const;
   double getVelocityY() const;
   double getTotalVelocity() const;
};

