#pragma once

/** Funktor zwracajacy prawde lub falsz
*/
class DivisibleBy
{
    public:
    /** Konstruktor
     * @param mianownik rownania filtrujacego
     */
    DivisibleBy(int mian) : mian(mian) {}

    /** Destruktor
     */
    ~DivisibleBy() {}

    /** Przeladowanie operatora (), zeby plynnie stosowac funktor jako filtr
     * @param licznik w licznik%mianownik == 0
     * @return prawda lub falsz w zaleznosci od wyniku dzialania
     */
    inline bool operator()(int licznik) const
    {
        return licznik % this->mian == 0;
    }
    private:
    int mian;
};

class LowerThan
{
    public:
    /** Konstruktor
     * @param prawa strona nierownosci
     */
    LowerThan(int right) : right(right) {}

    /** Destruktor
     */
    ~LowerThan() {}

    /** Przeladowanie operatora (), zeby plynnie stosowac funktor jako filtr
     * @param lewa strona rownania left < right
     * @return prawda lub falsz w zaleznosci od wyniku dzialania
     */
    inline bool operator()(int left) const
    {
        return left < right;
    }
    private:
    int right;
};