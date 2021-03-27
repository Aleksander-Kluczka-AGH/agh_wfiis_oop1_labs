#include "../include/List.h"

void List::insert(int val)
{
    this->data.push_back(val);
}

void List::print(std::string prefix) const
{
    std::cout << prefix << " [ ";
    for(auto &i : this->data)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

int &List::operator[](unsigned index)
{
    index = index % this->data.size();
    return this->data[index];
}

List List::filter(std::function<bool(int)> ftr) const
{
    List result;
    for(auto &i : this->data)
        if(ftr(i))
            result.insert(i);
    return result;
}