/*! \file CParal.cpp
    \brief implementation of class Paral
    \author Paolo Gastaldo
*/

#include "CParal.h"
#include <iostream>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
Paral::Paral() : Shape()
{
    cout << "Paral - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
Paral::Paral(float px, float py, float w, float h) : Shape(px, py, w, h)
{
    cout << "Paral - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
Paral::Paral(const Paral &r) : Shape(r)
{
    cout << "Paral - copy constructor" << endl;
}

/// @brief destructor
Paral::~Paral()
{
    cout << "Paral - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
Paral& Paral::operator=(const Paral &r)
{
    if (this != &r) 
        Shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool Paral::operator==(const Paral &r)
{
    return Shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void Paral::Init()
{
    Shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Paral::Init(const Paral &r)
{
    Shape::Init(r);
}

/// @brief total reset of the object  
void Paral::Reset()
{
    Shape::Reset();
}

/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the height of the Paral
/// @return height
float Paral::GetVSide()
{
	return height;
    
}

/// @brief to get the width of the Paral
/// @return width
float Paral::GetHSide()
{
    return width;
}

/// @brief computes the area of the Paral
/// @return area 
float Paral::GetArea()
{
    return width * height;
}

/// @brief computes the perimeter of the Paral
/// @return perimeter 
float Paral::GetPerimeter()
{
    return 2.0 * (width + height);
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void Paral::Dump()
{
    cout << "Paral Dump:" << endl;
    cout << "  Bounding box position: (" << x << ", " << y << ")" << endl;
    cout << "  Bounding box width:  " << width << endl;
    cout << "  Bounding box height: " << height << endl;
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
}