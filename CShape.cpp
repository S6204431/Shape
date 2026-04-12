/*! \file CShape.h
    \brief Implementation of the class Shape's functions
	\author Alessandro Passaggio
*/

#include "CShape.h"
#include<iostream>
#include<cstring>    
#include<new>        
#include<cmath>


    Shape::Shape()
    {
        text = nullptr;
        Init();
    }


    Shape::Shape(float px, float py, float w, float h)
    {
        text = nullptr;
        Init();

        SetPosition(px,py);

        SetWidth(w);
        SetHeight(h);
    }

    Shape::Shape(const Shape &r)
    {
        text = nullptr;
        Init(r);
    }

    Shape::~Shape()
    {
        Reset();
    }



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

    bool Shape::operator==(const Shape &r)
    {
        return x == r.x && y == r.y && height == r.height && width == r.width && strcmp(text, r.text);
    }



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


    void Shape::SetPosition(float px, float py)
    {
        if(px <= .0)
        {
            cout << "The minimum value for x position is 0";
            x = .0;
        }
        else
        {
            x = px;
        }

        if(py <= .0)
        {
            cout << "The minimum value for y position is 0";
            y = .0;
        }
        else
        {
            y = py;
        }
    }

    void Shape::SetHeight(float h)
    {
        if(h <= .0)
        {
            cout << "The minimum value for height is 0";
            height = .0;
        }
        else
        {
            height = h;
        }
    }

    void Shape::SetWidth(float w)
    {
        if(w <= .0)
        {
            cout << "The minimum value for height is 0";
            width = .0;
        }
        else
        {
           width = w;
        }
    }

    void Shape::SetDim(float w, float h)
    {
        SetWidth(w);
        SetHeight(h);
    }

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

    void Shape::GetPosition(float &px, float &py)
    {
        px = GetX();
        py = GetY();
    }

    void Shape::GetDim(float &w, float &h)
    {
        h = GetHeight();
        w = GetWidth();
    }

    float Shape::GetX()
    {
        return x;
    }

    float Shape::GetY()
    {
        return y;
    }

    float Shape::GetHeight()
    {
        return height;
    }

    float Shape::GetWidth()
    {
        return width;
    }

    float Shape::GetArea()
    {
        return width*height;
    }

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