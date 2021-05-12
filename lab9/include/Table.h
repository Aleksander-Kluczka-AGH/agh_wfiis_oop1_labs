#pragma once

#include "Data.h"

class Table
{
public:
    /** Przeciazenie operatora +=
     * @param element dodawany do tabeli
     */
    void operator+=(const Data &data);

    /** Wypisywanie zawartosci tabeli */
    void print() const;

    /** Sortowanie zawartosci tabeli po kolumnach
     * @param indeks kolumny
     * @return tabela po posortowaniu
     */
    Table sort(unsigned column);

    /** Sortowanie zawartosci tabeli wg komparatora
     * @param wskaznik do funkcji bedacej komparatorem
     * @return tabela po posortowaniu
     */
    Table &sortBy(std::function<bool(const Data &, const Data &)> sorter);

private:
    /** Wektor obiektow danych przechowujacych zbiory wartosci*/
    std::vector<Data> database;
};

bool compareCol(const Data& d1, const Data& d2, int column);