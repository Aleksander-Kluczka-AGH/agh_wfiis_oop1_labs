#pragma once

#include "virus.h"

class AnimalVirus : public Virus
{
public:
	/** Konstruktor domyslny
	 */
    AnimalVirus();

    /** Konstruktor wypelniajacy i nazywajacy obiekt
     * @param nazwa wirusa
     * @param nazwa zwierzecia-nosiciela
     * @param wektor nukleotypow RNA
     */
    AnimalVirus(std::string name, std::string host, std::vector<Nukleotyp> chain);

    /** Konstruktor kopiujacy
     * @param obiekt kopiowany
     * @return nowy skopiowany obiekt
     */
    AnimalVirus(const AnimalVirus &copy);

    /** Konstruktor przenoszacy
     * @param obiekt przenoszony
     * @return przeniesiony obiekt
     */
    AnimalVirus(AnimalVirus &&source);

    /** Dostep do nazwy zwierzecia-nosiciela
     * @return string z nazwa zwierzecia
     */
    std::string get_animal_host() const;

    /** Przeladowanie operatora kopiowania =
     * @param kopiowany obiekt
     * @return referencja nowego obiektu skopiowanego
     */
    const AnimalVirus &operator=(AnimalVirus &copy);

    /** Przeladowanie operatora przenoszenia =
     * @param przenoszony obiekt
     * @return referencja przeniesionego obiektu
     */
    const AnimalVirus &operator=(AnimalVirus &&source);

private:
	/** nazwa zwierzecia-nosiciela
	 */
    std::string host;
};