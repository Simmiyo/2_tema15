#include "Clasa_Vector.h"

template <class X>
int Vector<X>::lungime()
{
    return n;
}

template <class X>
Vector<X>::Vector(int nr)
{
    n = 0;
    maxim = nr;
    try
    {
        elem = new X[maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in constructorul de initializare."<<exp.what();
    }
}

template <class X>
Vector<X>::~Vector()
{
    delete []elem;
    n = 0;
}

template <class X>
Vector<X>::Vector(const Vector<X> &v)
{
    n = v.n;
    maxim = v.maxim;
    try
    {
        elem = new X[maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in copy-constructor."<<exp.what();
    }
    for(int i=0;i<n;i++)
        elem[i] = v.elem[i];
}

template <class X>
void Vector<X>::rsize()
{
    X *vec,*aux;
    try
    {
        vec = new X[2 * maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in rsize."<<exp.what();
    }
    for(int i=0;i<n;i++)
        vec[i] = elem[i];
    aux = elem;
    elem = vec;
    vec = aux;
    maxim = 2 * maxim;
    delete []vec;
}

template <class X>
void Vector<X>::adaugare(X c)
{
    if(n + 1 == maxim)
        (*this).rsize();
    elem[n] = c;
    n++;
}

template <class X>
void Vector<X>::stergere(int poz)
{
    if(poz > -1 && poz < n)
    {
        for(int i=poz;i<n-1;i++)
        {
            elem[i] = elem[i + 1];
        }
        n--;
    }
}

template <class X>
void Vector<X>::Stergere(int poz1,int poz2)
{
    if(poz2 == -1 || poz2 >= n)
        poz2 = n - 1;
    if(poz1 <= -1)
        poz1 = 0;
    if(poz1 < n && poz2 > -1)
        for(int i=poz1;i<=poz2;i++)
            (*this).stergere(poz1);
}

template <class X>
bool Vector<X>::operator==(const Vector<X> &v)
{
    if(n != v.n)
        return 0;
    for(int i=0;i<n;i++)
        if(elem[i] != v.elem[i])
            return 0;
    return 1;
}

template <class X>
Vector<X> Vector<X>::operator=(const Vector<X> &v)
{
    delete []elem;
    n = v.n;
    maxim = v.maxim;
    try
    {
        elem = new X[maxim];
    }
    catch(std::bad_alloc &exp)
    {
        std::cout<<"Eroare in operato r=."<<exp.what();
    }
    for(int i=0;i<n;i++)
        elem[i] = v.elem[i];
    return *this;
}

template <class X>
std::istream & operator>>(std::istream &intrare,Vector<X> &v)
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

template <class X>
std::ostream & operator<<(std::ostream &iesire,const Vector<X> &v)
{
    for(int i=0;i<v.n;i++)
        iesire<<v.elem[i];
    return iesire;
}

template <class X>
void Vector<X>::rverse()
{
    X aux;
    for(int i=0;i<=(n-1)/2;i++)
    {
        aux = elem[i];
        elem[i] = elem[n-1-i];
        elem[n-1-i] = aux;
    }
}
