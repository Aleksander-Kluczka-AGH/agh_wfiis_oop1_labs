#include "../include/Data.h"

Data::Data(const std::string &name, std::vector<double> values)
:
name(name),
values(values)
{ }

Data::~Data()
{
    this->values.clear();
}

void Data::print() const
{
    std::cout << std::setw(6) << this->name << " ";
    for(auto &it : this->values)
        std::cout << std::setw(6) << it;
    std::cout << std::endl;
    return;
}

std::vector<double> Data::getValues() const
{
    return this->values;
}