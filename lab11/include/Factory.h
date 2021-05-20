#pragma once

#include "Car.h"

class Factory
{
public:
    /** Szablon funkcji tworzaca prototyp danego typu zmiennych
     * @param wartosc tego typu zmiennych
     *
     * Funkcja ta wykorzystuje manufacture<T>() do tworzenia nowych danych
     */
    template<typename T>
    void prototype(const T &value)
    {
        manufacture<T>(&value);
    }

    /** Szablon funkcji wypisujacy zawartosc stworzonego prototypu
     * @param wskaznik do wartosci danego typu (domyslnie nullptr)
     *
     * Jesli parametr to nullptr, nastepuje tylko wypisywanie.
     *   A jesli dany typ zmiennych nie byl wczesniej prototypowany,
     *   funkcja ta o tym informuje.
     *
     * Jesli parametr to nie nullptr, wartosc typu danych (prototypu)
     *   zostaje nadpisana przekazanym argumentem.
     *
     * @warning wymaganiem dzialania tej funkcji jest mozliwosc logicznego
     *          sprawdzenia wartosci typu zmiennych. O ile dla typow
     *          jest to juz zaimplementowane, nowe typy zmiennych stworzonego
     *          z klas musza posiadac konwersje do typu boolean.
     */
    template<typename T>
    T &manufacture(const T *value = nullptr)
    {
        static T prot;
        if(value)
        {
            prot = *value;
        }
        else
        {
            if(!prot)
                std::cout << "No prototype for this type: ";
        }
        return prot;
    }

private:

};