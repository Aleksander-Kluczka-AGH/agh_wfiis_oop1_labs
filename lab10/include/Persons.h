#pragma once

#include <iostream>

#include "Person.h"

class Woman : public Person
{
public:
	/**
	 * @brief Konstruktor
	 *
	 * @param imie kobiety
	 * @param czy potrzebne strzyzenie
	 * @param czy potrzebny makijaz
	 */
    explicit Woman(std::string name, bool haircut = true, bool makeup = true)
    :
    Person(name, true, haircut),
    _makeup(!makeup)
    {}

    /**
     * @brief Destruktor
     */
    ~Woman()
    {
        this->print();
        std::cout << " idzie na zakupy" << std::endl;
    }

    /**
     * @brief Wypisywanie statusu gotowego/niegotowego
     */
    void print() const override
    {
        std::cout << this->_name << " ";
        if(!this->_haircut)
            std::cout << "obcieta ";
        else 
            std::cout << "nieobcieta ";

        std::cout << "i ";

        if(this->_makeup)
            std::cout << "umalowana";
        else
            std::cout << "nieumalowana";
    }

    /**
     * @brief Sprawdzenie czy wszystkie czynnosci zostaly wykonane
     * @return true jesli gotowy/a, false jesli nie
     */
    bool done() const override
    {
        return ((!this->_haircut) && this->_makeup);
    }

    /**
     * @brief Zrobienie makijazu
     */
    void makeup() override
    {
        this->_makeup = true;
    }

    /**
     * @brief Metoda ta jest tutaj tylko po to, zeby Woman moglo dziedziczyc po Person
     */
    void shave() override {}

private:
	/**
	 * Czy potrzebny makeup
	 */
    bool _makeup;

};

class Man : public Person
{
public:
	/**
	 * @brief Konstruktor
	 *
	 * @param name imie mezczyzny
	 * @param haircut czy potrzebne strzyzenie
	 * @param beard czy potrzebne golenie
	 */
    explicit Man(std::string name, bool haircut = true, bool beard = true)
    :
    Person(name, false, haircut),
    shaved(!beard)
    {}

    /**
     * @brief Destruktor
     */
    ~Man()
    {
        this->print();
        std::cout << " idzie na piwko" << std::endl;
    }

    /**
     * @brief Wypisywanie statusu gotowy/niegotowy
     */
    void print() const override
    {
        std::cout << this->_name << " ";
        if(!this->_haircut)
            std::cout << "obciety ";
        else 
            std::cout << "nieobciety ";

        std::cout << "i ";

        if(this->shaved)
            std::cout << "ogolony";
        else
            std::cout << "nieogolony";
    }

    /**
     * @brief Sprawdzenie czy klient jest gotowy
     *
     * @return true jesli ogolony i ostrzyzony, w przeciwnym wypadku false
     */
    bool done() const override
    {
        return ((!this->_haircut) && this->shaved);
    }

    /**
     * @brief Golenie klienta
     */
    void shave() override
    {
        this->shaved = true;
    }

    /**
     * @brief Metoda ta zdefiniowana zostala tylko w celach kompatybilnosci
     *  z dziedziczeniem po klasie Person
     */
    void makeup() override {}

private:
	/**
	 * Czy potrzebne golenie
	 */
    bool shaved;
};