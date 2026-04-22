/*! \file CRombo.cpp
    \brief implementation of class Rombo
    \author Alessandro Passaggio
*/

#include "CRombo.h"
#include <iostream>
#include <math.h>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
Rombo::Rombo() : Shape()
{
    cout << "Rombo - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
Rombo::Rombo(float px, float py, float w, float h) : Shape(px, py, w, h)
{
    cout << "Rombo - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
Rombo::Rombo(const Rombo &r) : Shape(r)
{
    cout << "Rombo - copy constructor" << endl;
}

/// @brief destructor
Rombo::~Rombo()
{
    cout << "Rombo - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
Rombo& Rombo::operator=(const Rombo &r)
{
    if (this != &r) 
        Shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool Rombo::operator==(const Rombo &r)
{
    return Shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void Rombo::Init()
{
    Shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rombo::Init(const Rombo &r)
{
    Shape::Init(r);
}

/// @brief total reset of the object  
void Rombo::Reset()
{
    Shape::Reset();
}

/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the height of the Rombo
/// @return height
float Rombo::Get1Diagonal()
{
	return height;
    
}

/// @brief to get the width of the Rombo
/// @return width
float Rombo::Get2Diagonal()
{
    return width;
}

/// @brief to get the side of the Rombo
/// @return side
float Rombo::GetSide()
{
    return sqrt((width*width)/4.0 + (height*height)/4.0);
}

/// @brief computes the area of the Rombo
/// @return area 
float Rombo::GetArea()
{
    return (width * height)/2.0;
}

/// @brief computes the perimeter of the Rombo
/// @return perimeter 
float Rombo::GetPerimeter()
{
    return 4.0*GetSide();
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void Rombo::Dump()
{
    cout << "Rombo Dump:" << endl;
    cout << "  Bounding box position: (" << x << ", " << y << ")" << endl;
    cout << "  Bounding box width:  " << width << endl;
    cout << "  Bounding box height: " << height << endl;
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
}