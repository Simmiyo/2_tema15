#ifndef CLASA_VECTOR_H_INCLUDED
#define CLASA_VECTOR_H_INCLUDED
#pragma once
#include <iostream>
#include <exception>

class Nr_natural;
class Nr_intreg;

class Vector
{
    protected:
    int *cifra;
    int maxim;
    int n;

    public:
    Vector(int nr = 100);
    ~Vector();
    Vector(const Vector &);
    void rsize();
    void adaugare(int);
    void stergere(int);
    void Stergere(int poz1 = 0,int poz2 = -1);
    bool operator==(const Vector &);
    Vector operator=(const Vector &);
    friend std::istream & operator>>(std::istream &,Vector &);
    friend std::ostream & operator<<(std::ostream &,const Vector &);
    int lungime();
    void rverse();
    friend Nr_natural;
    friend std::istream &operator>>(std::istream &,Nr_natural &);
    friend std::ostream &operator<<(std::ostream &,const Nr_natural &);
    friend Nr_intreg;
};


#endif // CLASA_VECTOR_H_INCLUDED
