#include "../include/Table.h"

void Table::operator+=(const Data &data)
{
    this->database.push_back(data);
    return;
}

void Table::print() const
{
    std::for_each(this->database.begin(), this->database.end(),
            [](const Data &data){ data.print(); });
    std::cout << std::endl;
    return;
}

Table Table::sort(unsigned column)
{
    unsigned minCount = 999u;
    for(auto &data : this->database)
        minCount = (minCount < data.getValues().size()) \
        ? minCount : data.getValues().size();
    
    if(column > minCount-1u)
    {
        std::cout << "Indkes " << column << " nieprawidlowy!" << std::endl;
    }
    else
    {
        std::sort(this->database.begin(), this->database.end(),
        [&column](const Data &one, const Data &two)
        {
            return (one.getValues()[column] < two.getValues()[column]);
        });
    }
    return *this;
}

Table Table::sortBy(bool (*function)(const Data &, const Data &))
{
    std::sort(this->database.begin(), this->database.end(), function);
    return *this;
}