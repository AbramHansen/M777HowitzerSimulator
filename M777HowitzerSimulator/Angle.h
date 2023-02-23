// Angle.h, will contain the declaration of the Angle class
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14159

/************************************
* Class to hold an angle in radians
************************************/
class Angle
{
private:
   double radians;
   /************************************
   * Convert radians to degrees
   ************************************/
   double convertToDegrees(double radians) const;
   /************************************
   * Convert degrees to radians
   ************************************/
   double convertToRadians(double degrees) const;
   /************************************
   * Convert normalize an angle in either
   * radians or degrees depending on if
   * isDegrees is true or false.
   ************************************/
   double normalize(double angle, bool isDegrees) const;
public:
   /************************
   * Default Constructor
   ************************/
   Angle();
   /************************
   * Non-Default Constructor
   ************************/
   Angle(double newRadians);
   /************************
   * Copy Constructor
   ************************/
   Angle(const Angle& angle);
   /************************************
   * Displays the angle in degrees to one decimal of precision.
   ************************************/
   void display() const;
   /***********************************
   * Getter methods for member variable
   * in radian format and degree format
   ***********************************/
   double getRadians() const;
   double getDegrees() const;
   /***********************************
   * Setter methods for member variable
   * in radian format and degree format
   ***********************************/
   void setDegrees(double degrees);
   void setRadians(double radians);
};