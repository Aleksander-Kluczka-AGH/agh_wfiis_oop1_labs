#pragma once

#include <iostream>
#include <cmath>

class ComplexNumber
{
    public:
    /** konstruktor domyslny
     * @param czesc rzeczywista
     * @param czesc urojona
     */
    explicit ComplexNumber(double re=0.0, double im=0.0);

    /** destruktor domyslny
     */
    ~ComplexNumber();

    /** operator =
     * @param obiekt po prawej stronie znaku =
     */
    const ComplexNumber &operator=(const ComplexNumber &other);
    /** operator <<
     * @param stream output
     * @param obiekt wypisywany
     */
    friend std::ostream &operator<<(std::ostream &stream, const ComplexNumber &target);
    /** konwersja obiekt-double
     */
    operator double() const;

    /** operator +
     * @param obiekt po prawej stronie znaku +
     */
    const ComplexNumber operator+(const ComplexNumber &second) const;
    
    /** operator +
     * @param liczba przed +
     * @param obiekt po prawej stronie znaku +
     */
    friend ComplexNumber operator+(double num, const ComplexNumber &target);
    /** operator -
     * @param obiekt po prawej stronie znaku -
     */
    const ComplexNumber operator-(const ComplexNumber &second) const;
    /** operator *
     * @param obiekt po prawej stronie znaku *
     */
    const ComplexNumber operator*(const ComplexNumber &second) const;
    const ComplexNumber &operator*=(double factor);
    const ComplexNumber &operator++(int);
    const ComplexNumber &operator++();
    //friend const ComplexNumber &operator++(ComplexNumber &target);
    bool operator< (const ComplexNumber &second) const;
    double &operator[](unsigned index);

    protected:

    private:
    double re;
    double im;
};