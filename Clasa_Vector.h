#ifndef CLASA_VECTOR_H_INCLUDED
#define CLASA_VECTOR_H_INCLUDED
#pragma once
#include <iostream>
#include <exception>

class Nr_natural;
class Nr_intreg;

template <class X>
class Vector
{
    protected:
    X *elem;
    int maxim;
    int n;

    public:
    Vector<X>(int nr = 100);
    ~Vector<X>();
    Vector<X>(const Vector<X> &);
    void rsize();
    void adaugare(X );
    void stergere(int);
    void Stergere(int poz1 = 0,int poz2 = -1);
    bool operator==(const Vector<X> &);
    Vector<X> operator=(const Vector<X> &);
    template <typename T>
    friend std::istream & operator>>(std::istream &,Vector<T> &);
    template <typename T>
    friend std::ostream & operator<<(std::ostream &,const Vector<T> &);
    int lungime();
    void rverse();
    friend Nr_natural;
    friend std::istream &operator>>(std::istream &,Nr_natural &);
    friend std::ostream &operator<<(std::ostream &,const Nr_natural &);
    friend Nr_intreg;
};


#endif // CLASA_VECTOR_H_INCLUDED
