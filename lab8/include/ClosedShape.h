#pragma once

#include <iostream>
#include <cmath>

/** Klasa reprezentujaca punkt w ukladzie wspolrzednych
 */
class Point
{
public:
    /** Konstruktor domyslny
     */
    Point() = default;

    /** Konstruktor dwuargumentowy
     * @param wsporzedna x
     * @param wsporzedna y
     */
    Point(const double x, const double y) : x(x), y(y) {}

    /** Destruktor
     */
    virtual ~Point() = default;

    /** Dostep do skladowej x
     * @return wpsolrzedna x punktu
     */
    const double &getX() const
    { 
        return this->x; 
    }

    /** Dostep do skladowej y
     * @return wpsolrzedna y punktu
     */
    const double &getY() const
    { 
        return this->y; 
    }

    /** Ustawienie skladowej x
     * @param nowa wartosc x
     */
    void setX(const double x) 
    { 
        this->x = x; 
    }

    /** Ustawienie skladowej y
     * @param nowa wartosc y
     */
    void setY(const double y) 
    { 
        this->y = y; 
    }

    /** Obliczenie dystansu wzorem pitagorasa
     * @param drugi punkt, od ktorego liczymy odleglosc
     * @return odleglosc miedzy punktami
     */
    double distance(const Point &point) const
    {
        return sqrt( pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
    }

    /** Funkcja zaprzyjazniona pozwalajaca na wypisanie obiektu
     * @param strumien do ktorego zapisywane sa informacje o obiekcie
     * @param wypisywane obiekt
     * @return strumien z informacjami
     */
    friend std::ostream &operator<< (const std::ostream &stream, const Point &point);

private:
    double x;
    double y;
};

std::ostream &operator<< (std::ostream &stream, const Point &point)
{
    return stream << "(" << point.getX() << ", " << point.getY() << ")";
}

/** Klasa reprezentujaca dowolny ksztalt
 */
class Shape
{
public:
    /** Wirtualna metoda zwracajaca dlugosc (czyli obwod lub odleglosc)
     */
    virtual double length() const = 0;

    /** Ustawienie pozycji ksztaltu
     * @param nowa pozycja ksztaltu
     */
    virtual void setPoint(const Point &point)
    {
        this->position.setX(point.getX());
        this->position.setY(point.getY());
    }

protected:
    Point position;
};

/** Klasa reprezentujaca ksztalt zamkniety (np. figure geometryczna)
 */
class ClosedShape : public Shape
{
public:
    /** Metoda wirtualna zwracajaca pole ksztaltu
     */
    virtual double area() const = 0;
};