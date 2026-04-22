/*! \file CParal.h
    \brief Declaration of the class Paral
    \author Paolo Gastaldo
*/

#ifndef Paral_H
#define Paral_H

#include "CShape.h"

/// @class Paral
/// @brief to manage an object with the shape of a Paral
class Paral : public Shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    Paral();
    Paral(float px, float py, float w, float h);
    Paral(const Paral &r);

    ~Paral();
    /// @}

    /// @name OPERATORS
    /// @{
    Paral& operator=(const Paral &r);
    bool operator==(const Paral &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const Paral &r);
    void Reset();
    /// @}

    /// @name GETTERS
    /// @{
	float GetVSide();
	float GetHSide();
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    virtual void Dump();
    /// @}
};

#endif