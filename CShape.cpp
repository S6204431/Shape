/*! \file CShape.h
    \brief Implementation of the class Shape's functions
	\author Alessandro Passaggio
*/

#include "CShape.h"
#include<iostream>
#include<cstring>    
#include<new>        
#include<cmath>

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */
/// @brief default constructor 
    Shape::Shape()
    {
        text = nullptr;
        Init();
    }

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
    Shape::Shape(float px, float py, float w, float h)
    {
        text = nullptr;
        Init();

        SetPosition(px,py);

        SetWidth(w);
        SetHeight(h);
    }

/// @brief copy constructor
/// @param r reference to the object to be copied
    Shape::Shape(const Shape &r)
    {
        text = nullptr;
        Init(r);
    }

/// @brief destructor
    Shape::~Shape()
    {
        Reset();
    }



/* ----------------------------
OPERATORS
---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
    Shape& Shape::operator=(const Shape &r)
    {
        x = r.x;
        y = r.y;
        height = r.height;
        width = r.width;
        if(text == nullptr)
        {
            text = new char[TEXTSIZE];
            if(text == nullptr)
            {
                ErrorMessage("operator= : memory allocation for text failed");
                return *this;
            }
        };
        strncpy(text, r.text, TEXTSIZE-1);
        return *this;
    }


/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
    bool Shape::operator==(const Shape &r)
    {
        return x == r.x && y == r.y && height == r.height && width == r.width && !strcmp(text, r.text);
    }



/* ----------------------------
   BASIC HANDLING
   ---------------------------- */
   
/// @brief default initialization of the object
    void Shape::Init()
    {
        x = .0;
        y = .0;

        width = .0;
        height = .0;

        if(text == nullptr)
        {
            text = new char[TEXTSIZE];
            if(text == nullptr)
            {
                ErrorMessage("Init(copy) : memory allocation for text failed");
                return;
            }
        }
        text[0] = '\0';
    }

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
    void Shape::Init(const Shape &r)
    {
        x = r.x;
        y = r.y;

        width = r.width;
        height = r.height;

        if(text == nullptr)
        {
            text = new char[TEXTSIZE];
            if(text == nullptr)
            {
                ErrorMessage("Init(copy) : memory allocation for text failed");
                return;
            }
        }
        strncpy(text, r.text, TEXTSIZE-1);
    }

/// @brief total reset of the object  
    void Shape::Reset()
    {
        if(text != nullptr)
        {
            delete[] text;
            text = nullptr;
        }

        width = .0;
        height = .0;

        x = .0;
        y = .0;

    }


    
/* ----------------------------
   GETTERS / SETTERS
   ---------------------------- */

/// @brief set position of the object
/// @param px position on x
/// @param py position on y
    void Shape::SetPosition(float px, float py)
    {
        if(px <= .0)
        {
            ErrorMessage( "The minimum value for x position is 0");
            x = .0;
        }
        else
        {
            x = px;
        }

        if(py <= .0)
        {
            ErrorMessage( "The minimum value for y position is 0");
            y = .0;
        }
        else
        {
            y = py;
        }
    }

/// @brief set height of the object
/// @param h heigh
    void Shape::SetHeight(float h)
    {
        if(h <= .0)
        {
            ErrorMessage( "The minimum value for height is 0");
            height = .0;
        }
        else
        {
            height = h;
        }
    }

/// @brief set width of the object
/// @param w width 
    void Shape::SetWidth(float w)
    {
        if(w <= .0)
        {
            ErrorMessage( "The minimum value for height is 0");
            width = .0;
        }
        else
        {
           width = w;
        }
    }

/// @brief set width and length of the object
/// @param w width 
/// @param h height
    void Shape::SetDim(float w, float h)
    {
        SetWidth(w);
        SetHeight(h);
    }


/// @brief set the text area of the object
/// @param string the text 
    void Shape::SetText(const char* string)
    {
        if(string == nullptr)
        {
            text[0] = '\0';
            return;
        }

        if(text == nullptr)
        {
            text = new char[TEXTSIZE];
            if(text == nullptr)
            {
                ErrorMessage("SetText : memory allocation for text failed");
                return;
            }
        }
        strncpy(text, string, TEXTSIZE-1);
    }



/// @brief get position of the object
/// @param px (reference to) position on x
/// @param py (reference to) position on y
    void Shape::GetPosition(float &px, float &py)
    {
        px = GetX();
        py = GetY();
    }


/// @brief get width and length of the object
/// @param w (reference to) width 
/// @param h (reference to) height
    void Shape::GetDim(float &w, float &h)
    {
        h = GetHeight();
        w = GetWidth();
    }


/// @brief get position on x of the object
/// @return position on x
    float Shape::GetX()
    {
        return x;
    }

/// @brief get position on y of the object
/// @return position on y
    float Shape::GetY()
    {
        return y;
    }

/// @brief get height of the object
/// @return height
    float Shape::GetHeight()
    {
        return height;
    }

/// @brief get width of the object
/// @return width
    float Shape::GetWidth()
    {
        return width;
    }

/// @brief computes the area of the object
/// @return area 
    float Shape::GetBoundingBoxArea()
    {
        return width*height;
    }


/// @brief returns text in the text area 
/// @param string pointer to a string 
    void Shape::GetText(char* string)
    {
        if(string == nullptr)
        {
            return;
        }
        if(text == nullptr)
        {
            string[0] = '\0';
            return;
        }

        strncpy(string, text, TEXTSIZE-1);
    }

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief write an error message 
/// @param string message to be printed
    void Shape::ErrorMessage(const char *string)
    {
        std::cerr << "[Shape - ERROR] " << (string ? string : "(null)") << std::endl;
    }

/// @brief write an warning message 
/// @param string message to be printed
    void Shape::WarningMessage(const char *string)
    {
        std::cerr << "[Shape - WARNING] " << (string ? string : "(null)") << std::endl;
    }

/// @brief for debugging: all infos about the object
    void Shape::Dump()
    {
        std::cout << "Shape Dump:" << std::endl;
        std::cout << "  Position: (" << x << ", " << y << ")" << std::endl;
        std::cout << "  Width:  " << width << std::endl;
        std::cout << "  Height: " << height << std::endl;
        std::cout << "  Area:   " << GetBoundingBoxArea() << std::endl;
        std::cout << "  Text:   " << (text ? text : "(null)") << std::endl;
    }