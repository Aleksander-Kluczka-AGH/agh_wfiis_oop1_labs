#pragma once

#include <iostream>

/** Lista tablic dynamicznych
*/
class MyArray
{
    public:
    /** Konstruktor
     * @param wielkosc tablicy do zaalokowania
     */
    explicit MyArray(int size = 0);

    /** Konstruktor kopiujacy
     * @param obiekt kopiowany
     */
    MyArray(const MyArray &copy);

    /** Konstruktor przenoszacy
     * @param obiekt zrodlowy, ktory bedzie przenoszony
     */
    MyArray(MyArray &&source);

    /** Destruktor
    */
    ~MyArray();

    /** Funkcja zaprzyjazniona przeladowania operatora wypisywania do strumienia
     * @param strumien docelowy
     * @param wypisywany do strumienia obiekt
     * @return wypelniony informacjami strumien
     */
    friend std::ostream &operator<<(std::ostream &stream, const MyArray &target);

    /** Przeladowanie operatora [] do nadpisania i odczytania
     * @param indeks wartosci, ktora bedzie zwracana
     * @return referencja do wartosci pod podanym indeksem
     */
    int &operator[](int index);

    /** Przeladowanie operatora [] do odczytania
     * @param indeks wartosci, ktora bedzie zwracana
     * @return wartosc pod podanym indeksem
     */
    int operator[](int index) const;

    /** Przeladowanie operatora ++ postinkrementacji
     * @param tymczasowy argument
     * @return kopia obiektu sprzed inkrementacji
     */
    const MyArray operator++(int);

    /** Przeladowanie operatora -- predekrementacji
     * @return referencja obiektu po dekrementacji
     */
    const MyArray &operator--();

    /** Przeladowanie operatora += do kopiowania
     * @param kopia obiektu dolaczanego do obecnego
     * @return referencja do uzupelnionego obiektu
     *
     * Ta metoda dolacza wskaznik dolaczanego obiektu do obecnego,
     * dzieki czemu obie tablice zachowuja autonomicznosc
     * (osobne rozmiary, zaalokowane pamieci, wskazniki na nastepne tablice).
     */
    MyArray &operator+=(MyArray &right);

    /** Przeladowanie operatora += do przenoszenia wartosci
     * @param obiekt przenoszony do obecnego
     * @return referencja do uzupelnionego obiektu
     *
     * Ta metoda dolacza elementy dodawanej tablicy na koniec obecnej,
     * laczac dwa obiekty w jeden, o zsumowanej dlugosci i wspolnych wartosciach.
     */
    MyArray &operator+=(MyArray &&right);

    /** Przeladowanie operatora przypisania z kopiowaniem
     * @param oryginal kopiowanego obiektu
     * @return skopiowany obiekt w nowej zmiennej
     */
    MyArray &operator=(MyArray &right);

    /** Wielkosc tablicy (tylko dla tego obiektu, nie wliczono dlugosci nastepnych \
        elementow listy
     * @return dlugosc tablicy
     */
    const int size() const;

    /** Dostep do nastepnego elementu listy
     * @return wskaznik do nastepnej tablicy (jesli istnieje, w przeciwnym wypadku nullptr)
     */
    MyArray &getNext();

    /** Wypisywanie zawartosci tablicy tego obiektu, a takze nastepnych elementow listy
     * @param prefix do wypisania przed zawartoscia listy
     */
    void print(const std::string &prefix) const;

    private:
    /** Dlugosc tablicy
    */
    int len;

    /** Dynamiczna tablica wartosci typu integer
     */
    int *tab;

    /** Wskaznik na nastepna tablice w liscie
     */
    MyArray *next;
};