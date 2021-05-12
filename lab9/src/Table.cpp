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
        std::cout << "Indeks " << column << " nieprawidlowy!" << std::endl;
    }
    else
    {
        auto sorter = std::bind(compareCol, 
                            std::placeholders::_1, 
                            std::placeholders::_2, 
                            column);
        std::sort(this->database.begin(), this->database.end(), sorter);
    }
    return *this;
}

Table &Table::sortBy(std::function<bool(const Data &, const Data &)> sorter)
{
    std::sort(this->database.begin(), this->database.end(), sorter);
    return *this;
}

bool compareCol(const Data& d1, const Data& d2, int column)
{
    return d1.getValues()[column] < d2.getValues()[column];
}