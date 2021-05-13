#pragma once

#include "Persons.h"

#include <memory>
#include <algorithm>
#include <vector>
#include <map>

class VectorQ
{
public:
	/**
	 * @brief Dodawanie osob do poczekalni
	 * @param wskaznik na dodawana osobe
	 */
    void add(std::unique_ptr<Person> pers)
    {
        this->people.push_back(std::move(pers));
    }

    /**
     * @brief Wypisywanie osob w poczekalni
     * @param tekst wypisywany przed wylistowaniem
     */
    void print(const std::string &prefix) const
    {
        std::cout << prefix << std::endl;
        for(auto &it : this->people)
        {
            it->print();
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Dostep do kontenera kobiet w poczekalni
     * @return wektor wskaznikow
     */
    std::vector<Woman*> getWomen()
    {
        std::vector<Woman *> result;
        for(auto &it : this->people)
        {
            if(it->is_woman())
                result.emplace_back(static_cast<Woman *>(it.get()));
        }
        // std::reverse(result.begin(), result.end());
        return result;
    }

    /**
     * @brief Wypisanie liczby wystapien kazdego imienia
     */
    void countNames() const
    {
        std::map<std::string, unsigned> names;
        for(auto &it : this->people)
        {
            if(names.find(it->name()) != names.end())
                names[it->name()]++;
            else
                names[it->name()] = 1;
        }

        for(auto &m : names)
            std::cout << m.first << " : " << m.second << std::endl;
    }

    /**
     * @brief Obcinanie klienta o imieniu client
     * @param imie klienta - jesli puste, brana jest pierwsza osoba z kolejki
     */
    void haircut(const std::string &client = {})
    {
        if(client.empty())
        {
            auto pers = this->people.begin();
            if(pers != this->people.end())
            {
                (*pers)->haircut();
                if((*pers)->done())
                    this->people.erase(pers);
            }
        }
        else
        {
            auto pers = std::find_if(this->people.begin(), this->people.end(), 
            [&client](std::unique_ptr<Person> &per)
            {
                return client == per->name();
            });

            if(pers != this->people.end())
            {
                (*pers)->haircut();
                if((*pers)->done())
                    this->people.erase(pers);
            }
        }
    }

    /**
     * @brief Golenie mezczyzn o imieniu client
     * @param imie klienta - jesli puste, brana jest pierwsza osoba z kolejki
     */
    void shave(const std::string &client = {})
    {
        if(client.empty())
        {
            auto pers = this->people.begin();
            if(pers != this->people.end())
            {
                (*pers)->shave();
                if((*pers)->done())
                    this->people.erase(pers);
            }
        }
        else
        {
            auto pers = std::find_if(this->people.begin(), this->people.end(), 
            [&client](std::unique_ptr<Person> &per)
            {
                return client == per->name();
            });

            if(pers != this->people.end())
            {
                (*pers)->shave();
                if((*pers)->done())
                    this->people.erase(pers);
            }
        }
    }


private:
	/**
	 * Wektor wskaznikow na osoby w poczekalni
	 */
    std::vector<std::unique_ptr<Person>> people;
};