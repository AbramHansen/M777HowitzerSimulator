#pragma once
#include "Velocity.h"
#include "Angle.h"
/************************
* Projectile Class
* Represents a projectile
*************************/
struct PT
{
   double x;
   double y;
};

class Projectile
{
private:
   double mass;
   double radiusInMeters;
   Velocity velocity;
   PT currentPosition;

public:
   Projectile(const double mass, const double radiusInMeters, const PT& startingPosition, const double startingAngleDegrees, const double startingVelocity);

   void update(double accelerationX, double accelerationY);

   double getMass() const;

   double getRadius() const;

   double getAltitude() const;
   
   double getVelocityX() const;

   double getVelocityY() const;

   double getDistance() const;
};