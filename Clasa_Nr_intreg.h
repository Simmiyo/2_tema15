#ifndef CLASA_NR_INTREG_H_INCLUDED
#define CLASA_NR_INTREG_H_INCLUDED
#include <iostream>
#include "Clasa_Nr_natural.h"
#pragma once

class Nr_intreg : public Nr_natural
{
    protected:
    char semn;
    public:
    Nr_intreg() {semn = '+';}
    ~Nr_intreg() {semn = '+';}
    Nr_intreg(const Nr_intreg &ni) : Nr_natural(ni) {semn = ni.semn;};
    bool operator==(const Nr_intreg &);
    Nr_intreg operator=(const Nr_intreg &);
    void citire(std::istream &);
    void scriere(std::ostream &) const;
    Nr_intreg operator+(Nr_intreg &);
    bool operator>=(const Nr_intreg &);
    Nr_intreg operator-(Nr_intreg &);
    Nr_intreg operator*(Nr_intreg &);
};


#endif // CLASA_NR_INTREG_H_INCLUDED
