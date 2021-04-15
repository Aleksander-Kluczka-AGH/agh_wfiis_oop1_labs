#include "../include/animalvirus.h"

AnimalVirus::AnimalVirus()
:
Virus({}),
host({})
{

}

AnimalVirus::AnimalVirus(std::string name, std::string host, std::vector<Nukleotyp> chain)
:
Virus(name, chain),
host(host)
{

}

AnimalVirus::AnimalVirus(const AnimalVirus &copy)
:
Virus(const_cast<AnimalVirus &>(copy)),
host(copy.host)
{

}

AnimalVirus::AnimalVirus(AnimalVirus &&source)
:
Virus(source),
host(std::__exchange(source.host, {}))
{

}

std::string AnimalVirus::get_animal_host() const
{
    return this->host;
}

const AnimalVirus &AnimalVirus::operator=(AnimalVirus &copy)
{
    Virus::operator=(copy);
    this->host = copy.host;
    return *this;
}

const AnimalVirus &AnimalVirus::operator=(AnimalVirus &&source)
{
    Virus::operator=(source);
    this->host = std::__exchange(source.host, {});
    this->rna->mutate();
    return *this;
}
