#pragma once

#include "Operation.h"

class Exponentiation : public Operation
{
public:
	/** Konstruktor dla potegowania liczby
	 * @param podstawa potegi
	 * @param wykladnik potegi
	 */
    Exponentiation(double one, double two) : Operation(one, two)
    { }

    double eval() const override
    {
        return pow(this->data[0], this->data[1]);
    }

    void print() const override
    {
        std::cout << this->data[0] << " ^ " << this->data[1];
    }
};