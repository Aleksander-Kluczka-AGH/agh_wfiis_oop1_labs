#pragma once

/** Klasa nadajaca ceche transformacji
 */
class Transformable
{
public:
    /** Przesuniecie celu o (x, y)
     * @param przesuniecie X
     * @param przesuniecie Y
     */
    virtual void shift(const double x, const double y) = 0;
};

/** Klasa nadajaca mozliwosc rysowania
 */
class Drawable
{
public:
    /** Obwod lub dlugosc obiektu wywolujacego
     * @return obwod / dlugosc
     */
    virtual double length() const = 0;

    /** Rysowanie obiektu wywoluajcego
     */
    virtual void draw() const = 0;
};