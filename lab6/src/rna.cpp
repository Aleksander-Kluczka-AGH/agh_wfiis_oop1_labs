#include "../include/rna.h"

std::ostream& operator<<(std::ostream& out, const RNA & seq_)
{
    for(auto &it : seq_.chain)
        out << (char)it << " ";
    out << std::endl;
    return out;
}

RNA & RNA::mutate ()
{
    Nukleotyp first = this->chain.front();
    this->chain.erase(this->chain.begin());
    this->chain.push_back(first);
    return *this;
}