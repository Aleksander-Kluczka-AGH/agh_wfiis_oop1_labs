#include "../include/Operation.h"

Operation::Operation(double one, double two)
:
data(new double[2]),
size(2) 
{
    this->data[0] = one;
    this->data[1] = two;
}

Operation::Operation(const double *arr, const int size)
:
data(new double[size]),
size(size)
{
    std::copy(arr, arr+size, this->data);
}

Operation::~Operation()
{
    if(this->data != nullptr)
        delete[] this->data;
}

void operator>>=(const std::string &text, const Operation &operation)
{
    std::cout << text << " ";
    operation.print();
    std::cout << " " << text << std::endl;
}