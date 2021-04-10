#pragma once

#include "Operation.h"

class SumOfElements : public Operation
{
public:
	/** Konstruktor dla sumowania tablicy
	 * @param tablica sumowanych liczb
	 * @param rozmiar tablicy
	 */
    SumOfElements(double *n, int size) : Operation(n, size)
    { }

    double eval() const override
    {
        double result = 0.0;
        for(auto i = 0; i < this->size; i++)
            result += this->data[i];
        return result;
    }

    void print() const override
    {
        if(this->size > 0)
        {
            std::cout << this->data[0];
            for(auto i = 1; i < this->size; i++)
                std::cout << " + " << this->data[i];
        }
    }

};