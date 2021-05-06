#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

class Sum;

class Data
{
public:
    /** Konstruktor ustawiajacy nazwe i zbior wartosci
     * @param nazwa obiektu
     * @param wektor wartosci obiektu
     */
    Data(const std::string &name, std::vector<double> values);

    /** Destruktor czyszczacy wektor wartosci*/
    ~Data(); 

    /** Wypisywanie zawartosci obiektu*/
    void print() const;

    /** Dostep do wektora wartosci 
     * @return wektor typu std::vector<double> z wartosciami
     */
    std::vector<double> getValues() const;
    friend const Sum sumData(const Data &data);


private:
    /** Nazwa obiektu*/
    std::string name;

    /** Wektor wartosci obiektu*/
    std::vector<double> values;
};