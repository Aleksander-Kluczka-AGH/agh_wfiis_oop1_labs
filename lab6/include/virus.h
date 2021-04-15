#pragma once

#include "rna.h"

class Virus
{
public:
	/** Konstruktor nazywajacy wirusa
	 * @param nazwa wirusa
	 */
    explicit Virus(std::string name);

    /** Konstruktor nazywajacy i wypelniajacy informacje o wirusie
	 * @param nazwa wirusa
	 * @param wektor nukleotypow RNA
	 */

    Virus(std::string name, std::vector<Nukleotyp> chain);

    /** Konstruktor kopiujacy
     * @param kopiowany obiekt
     */
    Virus(Virus &copy);

    /** Konstruktor przenoszacy
     * @param przenoszony obiekt
     */
    Virus(Virus &&source);

    /** Destruktor wirtualny
     */
    virtual ~Virus();

    /** Dostep do nazwy obiektu
     * @return string z nazwa obiektu
     */
    std::string get_name() const;

    /** Dostep do skladowego obiektu typu RNA
     * @return wskaznik do skladowego obiektu
     */
    const RNA *get_RNA() const;

    /** Dostep do wieku wirusa
     * @return wiek wirusa
     */
    const unsigned get_age() const;

    /** Ustawienie wektora nukleotypow RNA
     * @param nowy wektor nukleotypow
     */
    void set_RNA(std::vector<Nukleotyp> chain);

    /** Przeladowanie operatora kopiowania =
     * @param kopiowany obiekt po prawej stronie znaku
     * @return referencja obiektu wypelnionego danymi z kopii
     */
    const Virus &operator=(Virus &copy);

    /** Przeladowanie operatora przenoszenia =
     * @param przenoszony obiekt po prawej stronie znaku
     * @return referencja obiektu przeniesionego
     */
    const Virus &operator=(Virus &&source);

protected:
	/** nazwa wirusa
	 */
    std::string name;

    /** lancuch RNA wirusa
     */
    RNA *rna;

    /** wiek wirusa
     */
    unsigned age;
};