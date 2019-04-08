#ifndef CLASA_NR_NATURAL_H_INCLUDED
#define CLASA_NR_NATURAL_H_INCLUDED
#include <iostream>
#include "Clasa_Vector.h"


class Nr_natural
{
    protected:
    int nr_cifre;
    Vector cif;
    public:
    Nr_natural();
    Nr_natural(const Nr_natural &);
    virtual ~Nr_natural();
    bool operator==(const Nr_natural &);
    Nr_natural operator=(const Nr_natural &);
    virtual void citire(std::istream &);
    friend std::istream &operator>>(std::istream &,Nr_natural &);
    virtual void scriere(std::ostream &) const ;
    friend std::ostream &operator<<(std::ostream &,const Nr_natural &);
    Nr_natural operator+(Nr_natural &);
    bool operator>=(const Nr_natural &);
    Nr_natural operator-(Nr_natural &);
    Nr_natural operator*(Nr_natural &);
};

#endif // CLASA_NR_NATURAL_H_INCLUDED
