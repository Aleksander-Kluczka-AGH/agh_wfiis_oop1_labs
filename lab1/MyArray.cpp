#include "MyArray.h"

MyArray::MyArray()
:
ar(nullptr),
length(0u)
{

}

MyArray::MyArray(const int size)
:
ar(new int[size]),
length(size)
{
    for(unsigned it = 0u; it < size; it++)
        this->ar[it] = 0;
}

MyArray::MyArray(const MyArray &copy)
:
length(copy.length)
{
    this->ar = new int[this->length];
    std::copy(copy.ar, copy.ar+copy.length, this->ar);
}

MyArray::MyArray(MyArray &&source)
:
ar(std::__exchange(source.ar, nullptr)),
length(std::move(source.length))
{

}

MyArray::~MyArray()
{
    if(this->ar != nullptr)
    {
        for(unsigned it = 0u; it < this->length; it++)
            this->ar[it] = 0;
        
        delete[] this->ar;
    }
    this->length = 0u;
    std::cout << "Usuwam tablice" << std::endl;
}

void MyArray::print(std::string text) const
{
    if(this->length < 1u or nullptr == this->ar)
    {
        std::cout << text << " = [ ]" << std::endl;
        return;
    }

    std::cout << text << " = [ ";
    for(unsigned it = 0u; it < this->length; it++)
    {
        std::cout << this->ar[it] << " ";
    }
    std::cout << "]" << std::endl;
}

int MyArray::size() const
{
    return this->length;
}

int &MyArray::operator[] (unsigned index)
{
    if(this->ar != nullptr)
        return this->ar[index];
    else
    {
        std::terminate();
    }
}

const int MyArray::operator[] (unsigned index) const //tylko do pomocy w pop()
{
    if(this->ar != nullptr)
        return this->ar[index];
    else
    {
        std::terminate();
    }
}

std::ostream &operator<<(std::ostream &str, const MyArray &target)
{
    str << "\b\b\b\b\b\bop<< [ ";
    for(unsigned it = 0u; it < target.size(); it++)
    {
        str <<target[it] << " ";
    }
    str << "]" << std::endl;
    return str;
}

void MyArray::operator++()
{
    if(nullptr == this->ar)
    {
        std::cout << "Tablica pusta, nie ma czego inkrementowac!" << std::endl;
        std::terminate();
    }
    for(unsigned it = 0u; it < this->length; it++)
    {
        this->ar[it]++;
    }
}

const MyArray &MyArray::operator=(const MyArray &input)
{
    if(this == &input)
        return *this;
    else
    {
        delete[] this->ar;
        this->length = input.length;
        this->ar = new int[this->length];
        std::copy(input.ar, input.ar+input.length, this->ar);
        return *this;
    }
}