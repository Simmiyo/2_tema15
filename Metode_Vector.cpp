#include "Clasa_Vector.h"


int Vector::lungime()
{
    return n;
}

Vector::Vector(int nr)
{
    n = 0;
    maxim = nr;
    try
    {
        cifra = new int[maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in constructorul de initializare."<<exp.what();
    }
}

Vector::~Vector()
{
    delete []cifra;
    n = 0;
}

Vector::Vector(const Vector &v)
{
    n = v.n;
    maxim = v.maxim;
    try
    {
        cifra = new int[maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in copy-constructor."<<exp.what();
    }
    for(int i=0;i<n;i++)
        cifra[i] = v.cifra[i];
}

void Vector::rsize()
{
    int *vec,*aux;
    try
    {
        vec = new int[2 * maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in rsize."<<exp.what();
    }
    for(int i=0;i<n;i++)
        vec[i] = cifra[i];
    aux = cifra;
    cifra = vec;
    vec = aux;
    maxim = 2 * maxim;
    delete []vec;
}

void Vector::adaugare(int c)
{
    if(n + 1 == maxim)
        (*this).rsize();
    cifra[n] = c;
    n++;
}

void Vector::stergere(int poz)
{
    if(poz > -1 && poz < n)
    {
        for(int i=poz;i<n-1;i++)
        {
            cifra[i] = cifra[i + 1];
        }
        n--;
    }
}

void Vector::Stergere(int poz1,int poz2)
{
    if(poz2 == -1 || poz2 >= n)
        poz2 = n - 1;
    if(poz1 <= -1)
        poz1 = 0;
    if(poz1 < n && poz2 > -1)
        for(int i=poz1;i<=poz2;i++)
            (*this).stergere(poz1);
}

bool Vector::operator==(const Vector &v)
{
    if(n != v.n)
        return 0;
    for(int i=0;i<n;i++)
        if(cifra[i] != v.cifra[i])
            return 0;
    return 1;
}

Vector Vector::operator=(const Vector &v)
{
    delete []cifra;
    n = v.n;
    maxim = v.maxim;
    try
    {
        cifra = new int[maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in operato r=."<<exp.what();
    }
    for(int i=0;i<n;i++)
        cifra[i] = v.cifra[i];
    return *this;
}

std::istream & operator>>(std::istream &intrare,Vector &v)
{
    int nr;
    intrare>>nr;
    int x;
    for(int i=0;i<nr;i++)
    {
        intrare>>x;
        v.adaugare(x);
    }
    return intrare;
}

std::ostream & operator<<(std::ostream &iesire,const Vector &v)
{
    for(int i=0;i<v.n;i++)
        iesire<<v.cifra[i];
    return iesire;
}

void Vector::rverse()
{
    int aux;
    for(int i=0;i<=(n-1)/2;i++)
    {
        aux = cifra[i];
        cifra[i] = cifra[n-1-i];
        cifra[n-1-i] = aux;
    }
}
