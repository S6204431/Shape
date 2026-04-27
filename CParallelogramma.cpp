/*! \file CParallelogram.cpp
    \brief implementation of class Parallelogram
    \author Paolo Gastaldo
*/

#include "CParallelogramma.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
Paral::Paral() : Shape()
{
    cout << "Parallelogram - default constructor" << endl;

    offset = 0.0;
}

/// @brief constructor
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
/// @param off horizontal offset of the upper base
Paral::Paral(float px, float py, float w, float h, float off) : Shape(px, py, w, h)
{
    cout << "Parallelogram - constructor" << endl;

    SetOffset(off);
}

/// @brief copy constructor
/// @param p reference to the object to be copied
Paral::Paral(const Paral &p) : Shape(p)
{
    cout << "Parallelogram - copy constructor" << endl;

    offset = p.offset;
}

/// @brief destructor
Paral::~Paral()
{
    cout << "Parallelogram - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator =
/// @param p reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
Paral& Paral::operator=(const Paral &p)
{
    if (this != &p) {
        Shape::operator=(p);
        offset = p.offset;
    }

    return *this;
}

/// @brief overload of operator ==
/// @param p reference to the object on the right side of the operator
/// @return true if the two parallelograms have the same bounding box and the same offset
bool Paral::operator==(const Paral &p)
{
    const float eps = 1e-6f;

    if (!Shape::operator==(p))
        return false;

    if (fabs(offset - p.offset) > eps)
        return false;

    return true;
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void Paral::Init()
{
    Shape::Init();
    offset = 0.0;
}

/// @brief initialization of the object as a copy of an object
/// @param p reference to the object that should be copied
void Paral::Init(const Paral &p)
{
    Shape::Init(p);
    offset = p.offset;
}

/// @brief total reset of the object
void Paral::Reset()
{
    Shape::Reset();
    offset = 0.0;
}

/* ----------------------------
   SETTERS / GETTERS
   ---------------------------- */

/// @brief set the horizontal offset of the parallelogram
/// @param off horizontal offset
void Paral::SetOffset(float off)
{
    if (off < 0.0) {
        WarningMessage("SetOffset: negative value, clamped to 0");
        off = 0.0;
    }

    if (off > width) {
        WarningMessage("SetOffset: value too large, clamped to width");
        off = width;
    }

    offset = off;
}

/// @brief get the horizontal offset of the parallelogram
/// @return offset
float Paral::GetOffset()
{
    return offset;
}

/// @brief get the height of the parallelogram
/// @return heigth
float Paral::GetVSize()
{
    return height;
}

/// @brief get the base of the parallelogram
/// @return horizontal side
float Paral::GetHSide()
{
    return width;
}

/// @brief get the left side of the parallelogram
/// @return left side
float Paral::GetLSide()
{
    float side;

    side = sqrt(offset * offset + height * height);
	
	return side;
}



/// @brief computes the area of the parallelogram
/// @return area
float Paral::GetArea()
{
    return GetHSide() * GetVSize();
}

/// @brief computes the perimeter of the parallelogram
/// @return perimeter
float Paral::GetPerimeter()
{

    return 2.0 * (width + GetLSide());
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void Paral::Dump()
{
    cout << "Parallelogram Dump:" << endl;
    cout << "  Bounding box position: (" << x << ", " << y << ")" << endl;
    cout << "  Bounding box width:    " << width << endl;
    cout << "  Bounding box height:   " << height << endl;
    cout << "  Offset:                " << offset << endl;
    cout << "  Horizontal side:       " << GetHSide() << endl;
    cout << "  Left side:         	  " << GetLSide() << endl;
    cout << "  Figure area:           " << GetArea() << endl;
    cout << "  Figure perimeter:      " << GetPerimeter() << endl;
    cout << "  Text:                  " << (text ? text : "(null)") << endl;
}