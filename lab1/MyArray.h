#pragma once

#include <iostream>

class MyArray
{
public:
    /** konstruktor domyslny
     */
    MyArray();
    /** konstruktor z okresleniem rozmiaru tablicy
     * @param rozmiar tablicy
     */
    MyArray(const int size);
    /** konstruktor kopiujacy
     * @param kopiowana tablica
     */
    MyArray(const MyArray &copy);
    /** konstruktor przenoszacy
     * @param zrodlo przenoszonej tablicy
     */
    MyArray(MyArray &&source);
    /** destruktor
     */
    ~MyArray();

    /** wypisywanie zawartosci tablicy
     * @param prefix do wypisania
     */
    void print(std::string text) const;
    /** dlugosc tablicy
     * @return rozmiat tablicy
     */
    int size() const;

    /** przeladowanie operatora dajace dostep do oryginalnej tablicy
     * @param indeks elementu tablicy
     * @return oryginal elementu tablicy
     */
    int &operator[] (unsigned index);
    /** przeladowanie operatora pozwalajace wypisac oryginalna tablice
     * @param indeks elementu tablicy
     * @return wartosc elementu w tym indeksie
     */
    const int operator[] (unsigned index) const;
    /** przeladowanie operatora wypisania
     * @param stream do ktorego wypisywana jest zawartosc
     * @param obiekt do wypisania
     * @return stream z zawartoscia wypisywana
     */
    friend std::ostream &operator<<(std::ostream &str, const MyArray &target);
    /** przeladowanie operatora inkrementacji
     */
    void operator++();
    /** przeladowanie operatora przypisania
     * @param obiekt przypisywany
     * @return obiekt przypisany
     */
    const MyArray &operator=(const MyArray &input);

protected:


private:
    int *ar;
    unsigned length;
};