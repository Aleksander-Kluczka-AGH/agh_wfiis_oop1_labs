#pragma once

#include "Data.h"

class Sum
{
public:
    /** Konstruktor ustawiajacy skladnik na 0*/
    Sum() : s(0.0) {}
    
    /** Przeciazenie operatora nawiasow ()
     * @param wartosc, ktora zostanie dodana do sumy
     */
    void operator() (double plus)
    {
        this->s += plus;
    }

    /** Zwrocenie wartosci sumy*/
    const double value() const
    {
        return this->s;
    }

private:
    /** Suma*/
    double s;
};

/** Funkcja sumujaca wszystkie wartosci z Data
 * @param stala referencja do obiektu typu Data
 * @return obiekt Sum ze zliczona suma wartosci
 */
const Sum sumData(const Data &data)
{
    Sum sum;
    sum(std::accumulate(data.values.begin(), 
    					data.values.end(),
    					0.0));
    return sum;
}