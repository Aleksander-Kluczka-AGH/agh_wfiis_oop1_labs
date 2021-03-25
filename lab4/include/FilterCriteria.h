#pragma once

/** Lista przechowujaca filtrujace funktory
 */
class FilterCriteria
{
    public:
    /** Konstruktor domyslny
     */
    FilterCriteria() : funs({}) {}

    /** Destruktor
     */
    ~FilterCriteria()
    {
        if(!this->funs.empty())
            this->funs.clear();
    }

    /** Dodawanie do listy funktora
     * @param funktor filtrujacy typu bool(int)
     */
    inline void add(std::function<bool(int)> val)
    {
        this->funs.push_back(val);
    }

    /** Dlugosc listy
     * @return dlugosc listy funktorow
     */
    inline const int size() const
    {
        return this->funs.size();
    }

    /** Dostep do elementu listy
     * @param indeks listy
     * @return funktor pod indeksem index
     */
    inline std::function<bool(int)> get(int index) const
    {
        index = index % this->funs.size();
        return this->funs[index];
    }

    private:
    /** Wektor funktorow filtrujacych typu bool(int)
     */
    std::vector<std::function<bool(int)>> funs;
};
