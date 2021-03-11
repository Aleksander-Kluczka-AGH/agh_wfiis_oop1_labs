#include "../include/ComplexNumber.h"

ComplexNumber::ComplexNumber(double re, double im)
:
re(re),
im(im)
{

}

ComplexNumber::~ComplexNumber()
{

}

const ComplexNumber &ComplexNumber::operator=(const ComplexNumber &other)
{
    if(this == &other)
    {}
    else
    {
        this->re = other.re;
        this->im = other.im;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const ComplexNumber &target)
{
    stream << target.re << " + " << target.im << "i";
    return stream;
}

ComplexNumber::operator double() const
{
    return this->re;
}

const ComplexNumber ComplexNumber::operator+(const ComplexNumber &second) const
{
    ComplexNumber temp(this->re+second.re, this->im+second.im);
    return temp;
}

const ComplexNumber ComplexNumber::operator-(const ComplexNumber &second) const
{
    ComplexNumber temp(this->re-second.re, this->im-second.im);
    return temp;
}

ComplexNumber operator+(double num, const ComplexNumber &target)
{
    ComplexNumber temp(target.re + num, target.im);
    return temp;
}

const ComplexNumber ComplexNumber::operator*(const ComplexNumber &second) const
{
    ComplexNumber temp(
        this->re*second.re - this->im*second.im, 
        this->re*second.im + this->im*second.re);
        return temp;
}

const ComplexNumber &ComplexNumber::operator*=(double factor)
{
    this->re *= factor;
    this->im *= factor;
    return *this;
}

const ComplexNumber &ComplexNumber::operator++(int)
{
    this->re += 1.0;
    return *this;
}

const ComplexNumber &ComplexNumber::operator++()
{
    this->re += 1.0;
    return *this;
}

// const ComplexNumber &operator++(ComplexNumber &target)
// {
//     target.re += 1.0;
//     return target;
// }

bool ComplexNumber::operator<(const ComplexNumber &second) const
{
    return sqrt(this->re*this->re + this->im*this->im) < sqrt(second.re*second.re + second.im*second.im);
}

double &ComplexNumber::operator[](unsigned index)
{
    if(index > 1u or index < 0u)
    {
        std::cout << "Dopuszczalne indeksy to 0 (RE) oraz 1 (IM)" << std::endl;
        std::terminate();
    }

    if(index == 0u)
        return this->re;
    if(index == 1u)
        return this->im;
}