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
    for(unsigned it = 0; it < size; it++)
        this->ar[it] = 0;
}

MyArray::MyArray(const MyArray &copy)
:
length(copy.length)
{
    if(nullptr != this->ar)
        this->pop();
    this->ar = new int[this->length];
    for(unsigned it = 0u; it < copy.size(); it++)
    {
        this->ar[it] = copy.ar[it];
    }
}

MyArray::MyArray(MyArray &&source)
{
    if(nullptr != this->ar)
        this->pop();
    this->ar = std::__exchange(source.ar, nullptr);
    this->length = std::move(source.length);
}

MyArray::~MyArray()
{
    if(this->ar != nullptr)
    {
        for(unsigned it = 0; it < this->length; it++)
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
    for(unsigned it = 0; it < this->length; it++)
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
    return this->ar[index];
}

int MyArray::operator[] (unsigned index) const //tylko do pomocy w pop()
{
    return this->ar[index];
}

std::ostream &operator<<(std::ostream &str, const MyArray &target)
{
    str << "op<< [ ";
    for(unsigned it = 0; it < target.size(); it++)
    {
        str <<target[it] << " ";
    }
    str << "]" << std::endl;
    return str;
}

void MyArray::operator++()
{
    for(unsigned it = 0; it < this->length; it++)
    {
        this->ar[it]++;
    }
}

MyArray MyArray::operator=(const MyArray &copy) const
{
    MyArray result(copy);
    return result;
}

MyArray &MyArray::operator=(MyArray &&source)
{
    this->pop();
    this->ar = std::__exchange(source.ar, nullptr);
    this->length = std::move(source.length);
    return *this;
}

void MyArray::pop()
{
    if(nullptr != this->ar)
    {
        for(unsigned it = 0; it < this->length; it++)
        {
            this->ar[it] = 0;
        }
        delete[] this->ar;
    }
    this->length = 0u;
}