/*! \file CRombo.h
    \brief Declaration of the class Rombo
    \author Alessandro Passaggio
*/

#ifndef ROMBO_H
#define ROMBO_H

#include "CShape.h"


/// @class Rombo
/// @brief to manage an object with the shape of a rombo
class Rombo : public Shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    Rombo();
    Rombo(float px, float py, float w, float h);
    Rombo(const Rombo &r);

    ~Rombo();
    /// @}

    /// @name OPERATORS
    /// @{
    Rombo& operator=(const Rombo &r);
    bool operator==(const Rombo &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const Rombo &r);
    void Reset();
    /// @}

    /// @name GETTERS
    /// @{
	float Get1Diagonal();
	float Get2Diagonal();
    float GetSide();
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    virtual void Dump();
    /// @}
};

#endif