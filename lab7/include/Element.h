#pragma once

#include <iostream>
#include <vector>

/** Klasa reprezentujaca element drzewa folderow
 */
class Element
{
public:
    /** Konstruktor podstawowy ustawiajacy nazwe elementu
     * @param nazwa elemetu
     */
    Element(std::string name = {}) : name(name) {}

    /** Destruktor wirtualny
     */
    virtual ~Element() {}

    /** Dostep do nazwy elementu z zewnatrz
     * @return nazwa elementu
     */
    const std::string &getName() const { return this->name; }

    bool isDir;

protected:
    std::string name;
};