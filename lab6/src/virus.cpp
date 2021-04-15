#include "../include/virus.h"

Virus::Virus(std::string name)
:
name(name),
rna(new RNA({})),
age(0u)
{

}

Virus::Virus(std::string name, std::vector<Nukleotyp> chain)
:
name(name),
rna(new RNA(chain)),
age(0u)
{

}

Virus::Virus(Virus &copy)
:
name(copy.name),
rna(new RNA(copy.rna->get_RNA())),
age(0u)
{
    copy.age++;
}

Virus::Virus(Virus &&source)
:
name(std::__exchange(source.name, {})),
rna(std::__exchange(source.rna, nullptr)),
age(0u)
{
    this->rna->mutate();
}

Virus::~Virus()
{
    if(this->rna)
        delete this->rna;
}

std::string Virus::get_name() const
{
    return this->name;
}

const RNA *Virus::get_RNA() const
{
    return this->rna;
}

const unsigned Virus::get_age() const
{
    return this->age;
}

void Virus::set_RNA(std::vector<Nukleotyp> chain)
{
    if(this->rna)
        delete this->rna;
    this->rna = new RNA(chain);
}

const Virus &Virus::operator=(Virus &copy)
{
    if(this->rna)
        delete this->rna;
    
    this->name = copy.name;
    this->rna = new RNA(copy.rna->get_RNA());
    this->age = 0u;

    copy.age++;
    return *this;
}

const Virus &Virus::operator=(Virus &&source)
{
    if(this->rna)
        delete this->rna;

    this->name = std::__exchange(source.name, {});
    this->rna = std::__exchange(source.rna, nullptr);
    this->age = 0u;

    return *this;
}