#include "../include/Division.h"

Division::Division(double one, double two)
:
Operation()
{
    this->data = new double[2];
    this->size = 2;
    this->data[0] = one;
    this->data[1] = two;
}

void Division::print() const
{
    std::cout << this->data[0] << " / " << this->data[1];
}

double Division::eval() const
{
    return (double)this->data[0]/this->data[1];
}