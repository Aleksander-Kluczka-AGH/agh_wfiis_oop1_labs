#pragma once

#include <iostream>
#include <utility>
#include <vector>

/** Wypisywanie czy istenieje element w Assoc
 * @param odpowiedz z Assoc czy istenieje
 * @return sformatowana odpowiedz
 */
const std::string print(const bool exists);

/** Szablon przeciazenia operatora * dla typu DATA
 * @param wartosc typu DATA
 * @param wspolczynnik mnozenia
 * @return wymnozona wartosc typu DATA
 */
template<typename DATA>
DATA operator*(const DATA &value, const int factor);

/** Szablon przeciazenia operatora * dla typu DATA
 * Dziala tak samo jak ten wyzj, tylko ze dla odwroconej kolejnosci danych
 */
template<typename DATA>
DATA operator*(const int factor, const DATA &value);

/** Szablon klasy reprezentujacej tablice asocjacyjna
 * @tparam klucz (indeks) elementu
 * @tparam wartosc pod kluczem
 */
template <typename KEY, typename DATA>
class Assoc
{
public:
    /** Konstruktor domyslny (bez argumentow)
     */
    Assoc();

    /** Umieszczenie elementu w tablicy asocjacyjnej
     * @param klucz (indeks)
     * @param wartosc pod kluczem
     */
    void insert(const KEY &key, const DATA value);

    /** Wypisywanie zawartosci calej tablicy
     * @param prefiks do wypisania przed kazdym elementem
     */
    void print(const std::string &prefix);

    /** Sprawdzenie, czy dany klucz juz zostal umieszczony w tablicy
     */
    const bool contains(const KEY &key) const;

    /** Przeciazenie operatora nawiasow [ ]
     * @param klucz (indeks) tablicy
     * @return referencja wartosci pod kluczem (indeksem)
     *
     * Pozwala na modyfikacje elementu pod kluczem.
     */
    DATA &operator[](const KEY &key);

    /** Przeciazenie operatora nawiasow [ ]
     * @param klucz (indeks) tablicy
     * @return wartosc pod kluczem (indeksem)
     *
     * Nie pozwala na modyfikacje, ale mozna wypisac zwracana wartosc.
     */
    const DATA operator[](const KEY &key) const;

private:
    /** Wektor par danych (klucz, wartosc), ktora przechowuje dane tablicy asocjacyjnej
     */
    std::vector<std::pair<KEY, DATA>> data;
};

template<typename KEY, typename DATA>
Assoc<KEY,DATA>::Assoc()
:
data({})
{ }

template<typename KEY, typename DATA>
void Assoc<KEY,DATA>::insert(const KEY &key, const DATA value)
{
    (*this)[key] = value;
}

template<typename KEY, typename DATA>
void Assoc<KEY,DATA>::print(const std::string &prefix)
{
    for(auto &it : this->data)
    {
        std::cout << "--- " << prefix << " --- " 
            << "klucz: " << it.first << " "
            << "wartosc: " << it.second << std::endl;
    }
}

template<typename KEY, typename DATA>
const bool Assoc<KEY,DATA>::contains(const KEY &key) const
{
    for(auto &it : this->data)
    {
        if(it.first == key)
        {
            return true;
            break;
        }
    }
    return false;
}

template<typename KEY, typename DATA>
DATA &Assoc<KEY,DATA>::operator[](const KEY &key)
{
    bool exists = false;
    unsigned index = 0;
    for(auto &it : this->data)
    {
        if(it.first == key)
        {
            exists = true;
            break;
        }
        index++;
    }

    if(exists)
    {
        return this->data[index].second;
    }
    else
    {
        DATA temp = DATA();
        this->data.push_back(std::make_pair(key, temp));
        return this->data.back().second;
    }
}

template<typename KEY, typename DATA>
const DATA Assoc<KEY,DATA>::operator[](const KEY &key) const
{
    bool exists = false;
    unsigned index = 0;
    for(auto &it : this->data)
    {
        if(it.first == key)
        {
            exists = true;
            break;
        }
        index++;
    }

    if(exists)
    {
        return this->data[index].second;
    }
    else
    {
       DATA temp = DATA();
       return temp;
    }
}

template<typename DATA>
DATA operator*(const DATA &value, const int factor)
{
    DATA result = value;
    for(int i = 0; i < factor - 1; i++)
    {
        result += value;
    }
    return result;
}

template<typename DATA>
DATA operator*(const int factor, const DATA &value)
{
    return value * factor;
}

const std::string print(const bool exists)
{
    if(!exists)
        return "Nie znaleziono";
    else
        return "Znaleziono";
}