#include "../include/MyArray.h"

MyArray::MyArray(int size)
:
len(size),
tab(new int[size]),
next(nullptr)
{
    for(int i=0; i<this->len; i++)
        this->tab[i] = 0;
}

MyArray::MyArray(const MyArray &copy)
:
len(copy.len),
next(copy.next)
{
    if(this->len > 0)
        this->tab = new int[copy.len];
    std::copy(copy.tab, copy.tab+copy.len, this->tab);
}

MyArray::MyArray(MyArray &&source)
:
len(std::__exchange(source.len, 0)),
tab(std::__exchange(source.tab, nullptr)),
next(std::__exchange(source.next, nullptr))
{

}

MyArray::~MyArray()
{
    delete[] this->tab;
}

std::ostream &operator<<(std::ostream &stream, const MyArray &target)
{
    if(target.len <= 0)
        return stream;
    stream << "[ " << target.tab[0];
    for(int i = 1; i < target.len; i++)
        stream << ", " << target.tab[i];
    stream << " ]";
    return stream;
}

int &MyArray::operator[](int index)
{
    if(index > this->len)
        return (*this->next)[index - this->len];
    else
        return this->tab[index];
}

int MyArray::operator[](int index) const
{
    if(index > this->len)
        return (*this->next)[index - this->len];
    else
        return this->tab[index];
}

const MyArray MyArray::operator++(int)
{
    if(this->tab != nullptr)
    {
         MyArray temp(*this);
        for(int i = 0; i<this->len; i++)
            this->tab[i]++;
        return temp;
    }
    else
        std::terminate();
}

const MyArray &MyArray::operator--()
{
    if(this->tab != nullptr)
    {
        for(int i = 0; i<this->len; i++)
            this->tab[i]--;
        return *this;
    }
    else 
        std::terminate();
}

MyArray &MyArray::operator+=(MyArray &right)
{
    MyArray *ptr = this;
    while(ptr->next != nullptr)
        ptr = ptr->next;
    ptr->next = &right;
    return *this;
}

MyArray &MyArray::operator+=(MyArray &&right)
{
    int *temp = new int[this->len+right.len];
    for(int i=0; i<this->len; i++)
        temp[i] = this->tab[i];
    for(int i=this->len; i<this->len+right.len; i++)
        temp[i] = right[i-this->len];
    delete[] this->tab;
    this->tab = temp;
    this->len += right.len;
    return *this;
}

MyArray &MyArray::operator=(MyArray &right)
{
    if(&right == this)
        return *this;
    if(this->tab != nullptr)
        delete[] this->tab;

    this->len = right.len;
    this->tab = new int[this->len];
    std::copy(right.tab, right.tab+right.len, this->tab);
    this->next = right.next;
    return *this;
}

const int MyArray::size() const
{
    return this->len;
}

MyArray &MyArray::getNext()
{
    return *this->next;
}

void MyArray::print(const std::string &prefix) const
{
    std::cout << prefix << *this << " ";
    const MyArray* temp = this;
    while (temp->next != nullptr)
    {
        std::cout<<*(temp->next)<<" ";
        temp = temp->next;
    } 
}