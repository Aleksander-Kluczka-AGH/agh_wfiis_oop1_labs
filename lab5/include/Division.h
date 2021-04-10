#pragma once

#include "Operation.h"

class Division : public Operation
{
public:
	/** Konstruktor dla dzielenia liczb
	 * @param licznik ulamka
	 * @param mianownik ulamka
	 */
    Division(double one, double two): Operation(one, two)
    { }

    double eval() const override
    {
        return (double)this->data[0]/this->data[1];
    }

    void print() const override
    {
        std::cout << this->data[0] << " / " << this->data[1];
    }   
};