#pragma once

class File : public Element
{
public:
    /** Konstruktor przypisujacy nazwe i rozmiar pliku
     * @param nazwa pliku
     * @param rozmiar pliku (domyslnie 0)
     */
    File(std::string name, unsigned size = 0) : Element(name), size(size)
    {
        this->isDir = false;
    }

    /** Destruktor 
     */
    ~File()
    {
        std::cout << "--Destruktor File: " << this->getName() << std::endl;
    }

    /** Dostep do rozmiaru pliku
     * @return rozmiar pliku
     */
    const unsigned getSize() const { return this->size; }

    /** Przeciazenie operatora <<
     * @param strumien do ktorego wypisywany jest plik
     * @param plik do wypisania
     * @return strumien wypelniony informacjami o pliku
     */
    friend std::ostream &operator<<(std::ostream &stream, const File &file);

private:
    unsigned size;
};

std::ostream &operator<<(std::ostream &stream, const File &file)
{
    stream << file.getName() << " (" << file.getSize() << ")" << std::endl;
    return stream;
}