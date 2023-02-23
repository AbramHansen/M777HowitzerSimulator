#include "Angle.h"
// Angle.cpp, contains all definitions 
// for the Angle class

/************************
* Default Constructor
************************/
Angle::Angle()
{
   setRadians(0.0);
}
/************************
* Non-Default Constructor
************************/
Angle::Angle(double newRadians)
{
   setRadians(newRadians);
}
/************************
* Copy Constructor
************************/
Angle::Angle(const Angle& angle)
{
   setRadians(angle.getRadians());
}
/************************************
* Convert radians to degrees
************************************/
double Angle::convertToDegrees(double radians) const
{
   return radians * 180 / PI;
}

/************************************
* Convert degrees to radians
************************************/
double Angle::convertToRadians(double degrees) const
{
   return degrees * PI / 180;
}

/************************************
* Convert normalize an angle in either 
* radians or degrees depending on if 
* isDegrees is true or false.
************************************/
double Angle::normalize(double angle, bool isDegrees) const
{
   if (isDegrees)
   {
      //this block basically does modulus but with decimals
      int timesAround = angle / 360;
      angle -= timesAround * 360;

      //calculates the corrisponding angle if it is negative
      if (angle < 0)
      {
         angle = 360 + angle;
      }
   }
   else
   {
      //this block basically does modulus but with decimals
      int timesAround = angle / (2 * PI);
      angle -= timesAround * 2 * PI;

      //calculates the corrisponding angle if it is negative
      if (angle < 0)
      {
         angle = 2 * PI + angle;
      }
   }
   return angle;
}

/************************************
* Displays the angle in degrees to one decimal of precision.
************************************/
void Angle::display() const
{
   cout << fixed;
   cout << setprecision(1);
   cout << convertToDegrees(radians);
}

/***********************************
* Getter methods for member variable
* in radian format and degree format
***********************************/
double Angle::getRadians() const
{
   return normalize(radians, false);
}
double Angle::getDegrees() const
{
   return normalize(convertToDegrees(radians), true);
}

/***********************************
* Setter methods for member variable
* in radian format and degree format
***********************************/
void Angle::setDegrees(double degrees)
{
   radians = normalize(convertToRadians(degrees), false);
}
void Angle::setRadians(double radians)
{
   this->radians = normalize(radians, false);
}