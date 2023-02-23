/******************
* This file holds the functions that relate to the provided tables along with the main function. A lot of this needs to be moved into the projectile class.
******************/

//TODO fix linear interpolation equasion 
//TODO Make on linear interpolation function.
//TODO Move the m795 calculation stuff into the projectile class meaning the functions also must be moved.
//TODO Linear interprolation for when it hits the ground.

#include <iostream>
#include <cassert>

#include "Projectile.h"

const double interval = 0.01;
using namespace std;
// Declare functions in advance
double getGravity(double altitude);
double getDensity(double altitude);
double getDragCoefficient(double speed, double altitude);
double interpolate(const PT& ptZero, const PT& ptOne, double middle);
double calcSpeedOfSound(double altitude);
/******************
* getGravity()
* Calculate gravity
* given altitude
******************/
double getGravity(double altitude)
{
   if (altitude > 25000.00)
   {
      double slope = .015 / -5000.0;
      return 9.730 - (slope * (altitude - 25000));
   }

   double altitudes[] = { 0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 15000.0, 20000.0, 25000.0 };
   double gravities[] = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730 };
   int i = 0;
   while (altitude > altitudes[i])
   {
      i++;
   }

   PT first;
   first.x = altitudes[i - 1];
   first.y = gravities[i - 1];

   PT second;
   second.x = altitudes[i];
   second.y = gravities[i];

   return interpolate(first, second, altitude);

}

/******************
* getDensity()
* Calculate density
* given altitude
******************/
double getDensity(double altitude)
{
   if (altitude > 80000.00)
   {
      double slope = 0.0000643 / -10000.0;
      return 0.0000185 - (slope * (altitude - 80000));
   }

   double altitudes[] = { 0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 15000.0, 20000.0, 25000.0, 30000.0, 40000.0, 50000.0, 60000.0, 70000.0, 80000.0 };
   double densities[] = { 1.225, 1.112, 1.007, 0.9093, 0.8194, 0.7364, 0.6601, 0.59, 0.5258, 0.4671, 0.4135, 0.1948, 0.08891, 0.04008, 0.01841, 0.003996, 0.001027, 0.0003097, 0.0000828, 0.0000185 };
   int i = 0;
   while (altitude > altitudes[i])
   {
      i++;
   }

   PT first;
   first.x = altitudes[i - 1];
   first.y = densities[i - 1];

   PT second;
   second.x = altitudes[i];
   second.y = densities[i];

   return interpolate(first, second, altitude);
}

/******************
* getDrag()
* Calculate drag
* given speed
******************/
double getDragCoefficient(double speed, double altitude)
{
   double currentMach = speed / calcSpeedOfSound(altitude);
   if (currentMach > 5.0)
   {
      double slope = -0.035 / -2.11;
      return 0.2656 * (slope * (currentMach - 5.0));
   }
   else if (currentMach < 0.3)
   {
      double slope = 0.2;
      return 0.1629 * (slope * (0.3 - currentMach));
   }
   double machs[] = { 0.3, 0.5, 0.7, 0.89, 0.92, 0.96, 0.98, 1.0, 1.02, 1.06, 1.24, 1.53, 1.99, 2.87, 2.89, 5.0 };
   double coefficients[] = { 0.1629, 0.1659, 0.2031, 0.2597, 0.3010, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2297, 0.2306, 0.2656 };
   int i = 0;
   while (currentMach > machs[i])
   {
      i++;
   }

   PT first;
   first.x = machs[i - 1];
   first.y = coefficients[i - 1];

   PT second;
   second.x = machs[i];
   second.y = coefficients[i];

   return interpolate(first, second, currentMach);
}

/*************************
* calcSpeedOfSound()
* Calculate speed of sound
* given altitude
*************************/
double calcSpeedOfSound(double altitude)
{
   if (altitude > 40000.0)
   {
      double slope = 19.0 / 10000.0;
      return 324 * (slope * (altitude - 40000));
   }
   double altitudes[] = { 0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 15000.0, 20000.0, 25000.0, 30000.0, 40000.0 };
   double speedsOfSound[] = { 340.0, 336.0, 332.0, 328.0, 324.0, 320.0, 316.0, 312.0, 308.0, 303.0, 299.0, 295.0, 295.0, 295.0, 305.0, 324.0 };
   int i = 0;
   while (altitude > altitudes[i])
   {
      i++;
   }

   PT first;
   first.x = altitudes[i - 1];
   first.y = speedsOfSound[i - 1];

   PT second;
   second.x = altitudes[i];
   second.y = speedsOfSound[i];

   return interpolate(first, second, altitude);


}

/*************************
* Interpolate
* Calculate a middle point
* given two endpoints
*************************/
double interpolate(const PT& ptZero, const PT& ptOne, double middle)
{
   return ((ptOne.y - ptZero.y) / (ptOne.x - ptZero.x)) * (middle - ptZero.x) + ptZero.y;
}

int main()
{
   double degrees;
   cout << "What is the angle of the howizter where 0 is up? " << endl;
   cin >> degrees;

   PT startingPosition;
   startingPosition.x = 0.0;
   startingPosition.y = 0.0;
   Projectile M795(46.7, 0.77445, startingPosition, degrees, 827.0);

   double hangTime = 0;
   double altitude = 1; //this gets reset to the correct altitude this is just so it does not trigger on the first loop.

   while (altitude > 0)
   {
      altitude = M795.getAltitude();
      double velocityX = M795.getVelocityX();
      double velocityY = M795.getVelocityY();
      double mass = M795.getMass();
      double area = PI * M795.getRadius() * M795.getRadius();

      double dragForceX = 0.5 * getDragCoefficient(velocityX, altitude) * getDensity(altitude) * velocityX * velocityX * area;
      double dragForceY = 0.5 * getDragCoefficient(velocityY, altitude) * getDensity(altitude) * velocityY * velocityY * area;
      double accelerationX = dragForceX / mass;
      double accelerationY = (dragForceY - getGravity(altitude)) / mass;

      M795.update(accelerationX, accelerationY);

      hangTime++;

      altitude = M795.getAltitude();
   }

   cout << "Distance:\t" << M795.getDistance() << "\tHang Time:\t" << hangTime << endl;

   return 0;
}