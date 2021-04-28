#pragma once

#include "Element.h"
#include "File.h"

class Dir final : public Element
{
public:
    /** Konstruktor przypisujacy nazwe directory
     * @param nazwa folderu
     */
    Dir(std::string name) : Element(name), data({})
    {
        this->isDir = true;
    }

    /** Destruktor
     * usuwa rowniez foldery podrzedne
     */
    ~Dir()
    {
        std::cout << "Destruktor Dir: " << this->getName() << std::endl;
        for(auto &it : this->data)
            delete it;
        this->data.clear();
    }

    /** Przeciazenie operatora +=
     * @param element dodawany do folderu
     * @return ten folder z dodanym elementem
     */
    Dir &operator+=(Element *el)
    {
        this->data.push_back(el);
        return *this;
    }

    /** Przecizaenie operatora -=
     * @param nazwa elementu usuwanego
     * @return ten sam folder bez elementu
     */
    Dir &operator-=(const std::string &name)
    {
        for(auto &it: this->data)
            if(it->getName() == name)
            {
                std::swap(it, this->data.back());
                break;
            }
        delete this->data.back();
        this->data.pop_back();
        return *this;
    }

    /** Kopiowanie drzewa folderow
     * @param kopiowany element
     */
    void copy(Element *el)
    {
        Dir *temp_dir, *no;
        File *temp_file, *yes;
        if(el->isDir == true)
        {
            temp_dir = new Dir(el->getName());
            no = dynamic_cast<Dir *>(el);
            for(const auto &it : no->getData())
                temp_dir->copy(it);
            this->data.push_back(temp_dir);
        }
        else
        {
            yes = dynamic_cast<File *>(el);
            temp_file = new File(yes->getName(), yes->getSize());
            this->data.push_back(temp_file);
        }
    }

    /** Dostep do dowolnego elementu w folderze
     * @param nazwa elementu
     * @return element konkretnego typu
     */
    Element *get(const std::string &name) const
    {
        Element *result = nullptr;
        for(auto &it : this->data)
        {
            if(it->getName() == name)
            {
                result = it;
                break;
            }
        }
        if(result->isDir == true)
            return dynamic_cast<Dir *>(result);
        else
            return dynamic_cast<File *>(result);
    }

    /** Dostep do folderu podrzednego
     * @param nazwa folderu
     * @return wskaznik na wybrany folder lub nullptr
     */
    Dir *getDir(const std::string &name) const
    {
        Element *result = nullptr;
        for(auto &it : this->data)
        {
            if(it->getName() == name)
            {
                result = it;
                break;
            }
        }
        if(result->isDir == true)
            return dynamic_cast<Dir *>(result);
        else
            return nullptr;
    }

    const std::vector<Element *> &getData() const
    {
        return this->data;
    }

    /** Przeciazenie operatora <<
     * @param strumien do ktorego wypisywany jest folder
     * @param folder do wypisania
     * @return strumien wypelniony zawartoscia folderu
     *
     * Funkcja jest rekurencyjna (wypisuje elementy podrzedne)
     */
    friend std::ostream &operator<<(std::ostream &stream, const Dir &dir);

private:
    std::vector<Element *> data;
};

std::ostream &operator<<(std::ostream &stream, const Dir &dir)
{
    static int depth;
    std::string spaces;
    for(int i = 0; i <= depth; i++)
        spaces += "  ";
    stream << dir.getName() << " (dir)" << std::endl;
    for(auto &it : dir.data)
    {
        if(it->isDir == true)
        {
            depth++;
            operator<<(stream << spaces, *(dynamic_cast<Dir *>(it)));
        }
        else
            operator<<(stream << spaces, *(dynamic_cast<File *>(it)));
    }
    depth = 0;
    return stream;
}