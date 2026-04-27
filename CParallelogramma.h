/*! \file CParallelogramma.h
    \brief Declaration of the class Paral
    \author Alessandro Passaggio
*/

#ifndef Paral_H
#define Paral_H

#include "CShape.h"

/// @class Paral
/// @brief to manage an object with the shape of a Paral
class Paral : public Shape
{
protected:
    /// @name POINT TO IDENTIFY WHICH PARALLELOGRAM
    /// @{
    float offset;
    /// @}
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    Paral();
    Paral(float px, float py, float w, float h, float off);
    Paral(const Paral &p);

    ~Paral();
    /// @}

    /// @name OPERATORS
    /// @{
    Paral& operator=(const Paral &p);
    bool operator==(const Paral &p);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const Paral &p);
    void Reset();
    /// @}

    /// @name GETTERS / SETTERS
    /// @{
    void SetOffset(float off);
    float GetOffset();

	float GetVSize();
	float GetHSide();
    float GetLSide();
    
    float GetArea();
    float GetPerimeter();

    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    virtual void Dump();
    /// @}
};

#endif