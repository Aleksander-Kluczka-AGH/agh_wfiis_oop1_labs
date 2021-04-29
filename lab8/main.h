#pragma once

#include "include/Figures.h"

void draw(Drawable *drawable)
{
    drawable->draw();
}

/*
Hierarchia klas w tym programie

Point - niezalezna klasa uzywana m.in. jako skladnik Shape;
Drawable, Transformable - klasy reprezentujace cechy figur;
Shape, ClosedShape - klasy abstrakcyjne zaprojektowane tak, aby po nich dziedziczyc;
Section, Circle, Deltoid - klasy dziedziczace po klasach 
                           abstrakcyjnych oraz po klasach cech;

Section dziedziczy po Shape, nie po ClosedShape, poniewaz
    odcinek nie jest figura zamknieta.

                 Shape    {Drawable, Transformable}
                 /   \               /
                /     \     ,-------/
               /       \   /       /
      ClosedShape     Section     /
              \                  /
               \                /
                \              /
                {Circle, Deltoid}