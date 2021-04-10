#pragma once

#include <iostream>
#include <cmath>

class Operation
{
public:
	/** Konstruktor dla dzialan o dwoch wyrazeniach
	 * @param pierwsza liczba w dzialaniu
	 * @param druga liczba
	 */
    Operation(double one, double two);

    /** Konstruktor dla dzialan na tablicy
     * @param tablica liczb podlegajacych obliczeniom
     * @param dlugosc tablicy
     */
    Operation(const double *arr, const int size);

    /** Destruktor wirtualny
     */
    virtual ~Operation();

    /** Abstrakcyjna metoda wyliczajaca wynik dzialania klas pochodnych
     * @return wynik dzialania
     */
    virtual double eval() const = 0;

    /** Abstrakcyjna metoda wypisujaca dzialanie
     */
    virtual void print() const = 0;

    /** Przeciazenie operatora >>= do sformatowanego wypisywania dzialania na ekran
     * @param prefiks oraz sufiks w wypisaniu zawartosci
     * @param obiekt, ktory zostanie wypisany
     */
    friend void operator>>=(const std::string &text, const Operation &operation);

protected:
    double *data;
    int size;
};