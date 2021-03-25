#pragma once

#include <iostream>
#include <vector>
#include <functional>

/** Klasa przechowujaca wartosci, ktore beda filtrowane
 *
 */
class List
{
    public:
    /** Konstruktor domyslny
     */
    List();
    /** Destruktor
     */
    ~List();

    /** Dodawanie elementu val do listy
     * @param dodawany element
     */
    void insert(int val);

    /** Wypisywanie zawartosci listy
     * @param ewentualny prefix przed wyswietlaniem zawartosci
     */
    void print(std::string prefix = "") const;

    /** Filtrowanie zawartosci listy
     * @param funktor, ktory zawiera warunek filtrowania
     * @return nowa lista zawierajaca tylko przefiltrowane wartosci
     */
    List filter(std::function<bool(int)> ftr) const;

    /** Przeladowanie operatora nawiasow kwadratowych
     * Pozwala na uzywanie skladni list[index] zeby uzyskac dostep do
     * elementow listy.
     *
     * @param indeks wartosci, ktora ma zostac zwrocona
     * @return referencja do zwracanej wartosci, aby dalo sie na niej wykonywac operacje arytmetyczne
     */
    int &operator[](unsigned index);

    private:
    /** wektor wartosci listy
     */
    std::vector<int> data;
};