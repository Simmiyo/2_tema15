#include "Clasa_Nr_natural.h"
#include <string>

Nr_natural::Nr_natural()
{
    nr_cifre = 1;
    cif.adaugare(0);
}

Nr_natural::~Nr_natural()
{
    nr_cifre = 0;
}

Nr_natural::Nr_natural(const Nr_natural &nn)
{
    nr_cifre = nn.nr_cifre;
    cif = nn.cif;
}

bool Nr_natural::operator==(const Nr_natural &nn)
{
    if(nr_cifre != nn.nr_cifre)
        return 0;
    return (cif == nn.cif);
}

Nr_natural Nr_natural::operator=(const Nr_natural &nn)
{
    nr_cifre = nn.nr_cifre;
    cif = nn.cif;
    return *this;
}

void Nr_natural::citire(std::istream &intrare)
{
    cif.Stergere();
    std::string sir;
    nr_cifre = 0;
    intrare>>sir;
    for(int i=0;i<sir.length();i++)
    {
        try
        {
            if((sir[i] - '0' <= 9) && (sir[i] - '0' >= 0))
            {
                cif.adaugare(sir[i]-'0');
                nr_cifre++;
            }
            else throw 10;
        }
        catch(int i)
        {
            std::cout<<"Eroare "<<i<<" la citire. Introduceti alt numar: "<<std::endl;
            this->citire(intrare);
        }
    }
}

std::istream & operator>>(std::istream &intrare,Nr_natural &nn)
{
    nn.citire(intrare);
    return intrare;
}

void Nr_natural::scriere(std::ostream &iesire) const
{
    iesire<<cif;
}

std::ostream & operator<<(std::ostream &iesire,const Nr_natural &nn)
{
    nn.scriere(iesire);
    return iesire;
}

Nr_natural Nr_natural::operator+(Nr_natural &nn)
{
    Nr_natural sum;
    sum.cif.Stergere();
    unsigned short int i = 0;
    int k1 = nr_cifre -1, k2 = nn.nr_cifre -1;
    while(k1 > -1 && k2 > -1)
    {
        sum.cif.adaugare((cif.cifra[k1] + nn.cif.cifra[k2] + i) % 10);
        i = (cif.cifra[k1] + nn.cif.cifra[k2] + i) / 10;
        k1--;
        k2--;
    }
    if(k1 == -1 && k2 == -1)
    {
        if(i > 0)
            sum.cif.adaugare(i);
    }
    else
    {
        int *p = cif.cifra;
        if(k1 == -1)
        {
            k1 = k2;
            p = nn.cif.cifra;
        }
        while(k1 > -1)
        {
            sum.cif.adaugare((p[k1] + i) % 10);
            i = (p[k1] + i) / 10;
            k1--;
        }
        if(i > 0)
            sum.cif.adaugare(i);
    }
    sum.cif.rverse();
    sum.nr_cifre = sum.cif.n;
    return sum;
}

bool Nr_natural::operator>=(const Nr_natural &nn)
{
    if(nr_cifre < nn.nr_cifre)
        return 0;
    else if(nr_cifre > nn.nr_cifre)
            return 1;
         else
         {
            for(int i=0;i<nr_cifre;i++)
                if(cif.cifra[i] < nn.cif.cifra[i])
                    return 0;
                else if(cif.cifra[i] > nn.cif.cifra[i])
                        return 1;
         }
    return 1;
}

Nr_natural Nr_natural::operator-(Nr_natural &nn)
{
    Nr_natural dif, *mare, *mic;
    dif.cif.Stergere();
    int k1, k2;
    short unsigned int i = 0;
    if(*this >= nn)
    {
        k1 = nr_cifre - 1;
        k2 = nn.nr_cifre - 1;
        mare = this;
        mic = &nn;
    }
    else
    {
        k2 = nr_cifre - 1;
        k1 = nn.nr_cifre - 1;
        mic = this;
        mare = &nn;
    }
    while(k2 > -1)
    {
        dif.cif.adaugare((10 + mare->cif.cifra[k1] - mic->cif.cifra[k2] - i) % 10);
        if(mare->cif.cifra[k1] >= mic->cif.cifra[k2])
            i = 0;
        else i = 1;
        k1--;
        k2--;
    }
    while(k1 > -1)
    {
        dif.cif.adaugare((10 +mare->cif.cifra[k1] - i) % 10);
        if(mare->cif.cifra[k1] - i < 0)
            i = 1;
        else i = 0;
        k1--;
    }
    while(dif.cif.cifra[dif.cif.n-1] == 0 && dif.cif.n > 1)
        dif.cif.stergere(dif.cif.n - 1);
    dif.cif.rverse();
    dif.nr_cifre = dif.cif.n;
    return dif;
}

Nr_natural Nr_natural::operator*(Nr_natural &nn)
{
    Nr_natural prod, *mare, *mic, termen;
    prod.cif.Stergere();
    termen.cif.Stergere();
    int k1, k2, j, k;
    short unsigned int i = 0, contor = 0;
    if(*this >= nn)
    {
        k1 = nr_cifre - 1;
        k2 = nn.nr_cifre - 1;
        mare = this;
        mic = &nn;
    }
    else
    {
        k2 = nr_cifre - 1;
        k1 = nn.nr_cifre - 1;
        mic = this;
        mare = &nn;
    }
    for(k=k2;k>=0;k--)
    {
        i = 0;
        for(j=k1;j>=0;j--)
        {
            termen.cif.adaugare((mic->cif.cifra[k] * mare->cif.cifra[j] + i) % 10);
            i = (mic->cif.cifra[k] * mare->cif.cifra[j] + i) / 10;
        }
        if(i != 0)
            termen.cif.adaugare(i);
        termen.cif.rverse();
        for(j=1;j<=contor;j++)
            termen.cif.adaugare(0);
        termen.nr_cifre = termen.cif.n;
        contor++;
        prod = prod + termen;
        prod.nr_cifre = prod.cif.n;
        termen.cif.Stergere();
    }
    while(prod.cif.cifra[0] == 0 && prod.cif.n > 1)
        prod.cif.stergere(0);
    return prod;
}
