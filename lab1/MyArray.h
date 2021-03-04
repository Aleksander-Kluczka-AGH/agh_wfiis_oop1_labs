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
    int operator[] (unsigned index) const;
    /** przeladowanie operatora wypisania
     * @param stream do ktorego wypisywana jest zawartosc
     * @param obiekt do wypisania
     * @return stream z zawartoscia wypisywana
     */
    friend std::ostream &operator<<(std::ostream &str, const MyArray &target);
    /** przeladowanie operatora inkrementacji
     */
    void operator++();
    /** przeladowanie operatora przypisania z kopiowaniem
     * @param kopiowana tablica
     * @return kopia podanej tablicy
     */
    MyArray operator=(const MyArray &copy) const;
    /** przeladowanie operatora przypisania z przenoszeniem
     * @param zrodlo z ktorego wykonywane jest przenoszenie
     * @return przeniesiony obiekt
     */
    MyArray &operator=(MyArray &&source);

protected:


private:
    /** pomocnicza metoda zwalniajaca pamiec oryginalnej tablicy
     */
    void pop();

    int *ar;
    unsigned length;
};