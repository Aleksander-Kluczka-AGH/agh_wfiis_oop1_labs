#pragma once

#include "ClosedShape.h"
#include "Traits.h"

/** Klasa reprezentujaca okrag
 */
class Circle : public Drawable, public Transformable, public ClosedShape
{
public:
    /** Konstruktor domyslny
     */
    Circle() = default;

    /** Konstruktor ustawiajacy polozenie i promien okregu
     * @param polozenie
     * @param promien
     */
    Circle(const Point center, double radius)
    : 
    Drawable(),
    Transformable(),
    ClosedShape(),
    radius(radius)
    {
        this->position.setX(center.getX());
        this->position.setY(center.getY());
    }

    /** Destruktor
     */
    ~Circle() = default;

    double length() const override
    {
        return 2 * 3.1415 * this->radius;
    }

    double area() const override
    {
        return 3.1415 * this->radius * this->radius;
    }

    void shift(const double x, const double y) override
    {
        this->position.setX(this->position.getX() + x);
        this->position.setY(this->position.getY() + y);
    }

    void draw() const override
    {
        std::cout << "Rysujemy kolo o srodku " 
                <<  this->position << " i promieniu " 
                << this->radius << std::endl;
    }

private:
    double radius;
};

/** Klasa reprezentujaca odcinek miedzy punktami
 */
class Section : public Drawable, public Transformable, public Shape
{
public:
    /** Konstruktor domyslny
     */
    Section() = default;

    /** Konstruktor ustawiajacy polozenie poczatku i konca odcinka
     */
    Section(const Point &p1, const Point &p2)
    :
    Drawable(),
    Transformable(),
    Shape(),
    end(Point(p2.getX(), p2.getY()))
    {
        this->setPoint(p1);
    }

    /** Destruktor
     */
    ~Section() = default;

    /** Dostep do pierwszego punktu odcinka
     * @return punkt poczatkowy
     */
    const Point &getStart() const
    { 
        return this->position; 
    }

    /** Dostep do drugiego punktu odcinka
     * @return punkt koncowy
     */
    const Point &getEnd() const 
    { 
        return this->end; 
    }

    double length() const override
    {
        return this->position.distance(this->end);
    }

    void shift(const double x, const double y) override
    {
        this->setPoint(this->position.getX() + x, this->position.getY() + y);
        this->end.setX(this->end.getX() + x);
        this->end.setY(this->end.getY() + y);
    }

    void draw() const override
    {
        std::cout << "Rysujemy odcinek od " 
                << this->position << " do "
                << this->end << std::endl;
    }

private:
    Point end;
};

/** Klasa reprezentuajca deltoid
 */
class Deltoid :public Drawable, public Transformable, public ClosedShape
{
public:
    /** Konstruktor domyslny
     */
    Deltoid() = default;

    /** Konstruktor okreslajacy przekatne deltoidu
     */
    Deltoid(const Section &d1, const Section &d2)
    :
    Drawable(),
    Transformable(),
    ClosedShape()
    {
        this->diagonal1 = Section(d1.getStart(), d1.getEnd());
        this->diagonal2 = Section(d2.getStart(), d2.getEnd());
    }

    /** Konstruktor okreslajacy cztery wierzcholki deltoidu
     */
    Deltoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
    :
    Drawable(),
    Transformable(),
    ClosedShape()
    {
        this->diagonal1 = Section(p1, p3);
        this->diagonal2 = Section(p2, p4);
    }

    /** Destruktor
     */
    ~Deltoid() = default;

    double length() const override
    {
        double sum = 0.0;
        sum += this->diagonal1.getStart().distance(this->diagonal2.getStart());
        sum += this->diagonal1.getStart().distance(this->diagonal2.getEnd());
        sum += this->diagonal1.getEnd().distance(this->diagonal2.getStart());
        sum += this->diagonal1.getEnd().distance(this->diagonal2.getEnd());
        return sum;
    }

    double area() const override
    {
        return (this->diagonal1.length() * this->diagonal2.length() / 2.0);
    }

    void shift(const double x, const double y) override
    {
        this->diagonal1.shift(x, y);
        this->diagonal2.shift(x, y);
    }

    void draw() const override
    {
        std::cout << "Rysujemy deltoid o wierzcholkach: "
             << this->diagonal1.getStart() << ", "
             << this->diagonal2.getStart() << ", "
             << this->diagonal1.getEnd() << ", "
             << this->diagonal2.getEnd() << std::endl;
    }

private:
    Section diagonal1;
    Section diagonal2;
};