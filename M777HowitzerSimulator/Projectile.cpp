#include "Projectile.h"

Projectile::Projectile(const double mass, const double radiusInMeters, const PT& startingPosition, const double startingAngleDegrees, const double startingVelocity)
{
   this->mass = mass;
   this->radiusInMeters = radiusInMeters;
   Angle startingAngle;
   startingAngle.setDegrees(startingAngleDegrees);
   this->velocity = Velocity(startingVelocity, startingAngle.getRadians());
   currentPosition = startingPosition;
}

void Projectile::update(double accelerationX, double accelerationY)
{
   velocity.update(accelerationX, accelerationY);
   currentPosition.x += velocity.getVelocityX();
   currentPosition.y += velocity.getVelocityY();
}

double Projectile::getMass() const
{
   return mass;
}

double Projectile::getRadius() const
{
   return radiusInMeters;
}

double Projectile::getAltitude() const
{
   return currentPosition.y;
}

double Projectile::getVelocityX() const
{
   return velocity.getVelocityX();
}

double Projectile::getVelocityY() const
{
   return velocity.getVelocityY();
}

double Projectile::getDistance() const
{
   return currentPosition.x;
}