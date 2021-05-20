#pragma once

class Car
{
public:
    /** Konstruktor bezargumentowy
     * skladnik name jest inicjalizowany jako pusty
     */
    Car() : name({}) { }

    /** Konstruktor przypisujacy nazwe auta
     * @param nazwa auta
     */
    Car(std::string name) : name(name) { }

    /** Wypisywanie nazwy auta
     */
    void print() const
    {
        std::cout << "Car: " << this->name << std::endl;
    }

    /** Konwersja do typu boolean potrzebna do warunku w Factory::manufacture<T>()
     * @return false jesli nazwa pusta, w przeciwnym wypadku true
     */
    operator bool()
    {
        if(this->name.empty())
            return false;
        else
            return true;
    }

private:
    /** nazwa auta
     */
    std::string name;
};