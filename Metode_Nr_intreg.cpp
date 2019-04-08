#include "Clasa_Nr_intreg.h"

bool Nr_intreg::operator==(const Nr_intreg &ni)
{
    if(semn =! ni.semn)
        return 0;
    else return this->Nr_natural::operator==(ni);
}

Nr_intreg Nr_intreg::operator=(const Nr_intreg &ni)
{
    semn = ni.semn;
    this->Nr_natural::operator=(ni);
    return *this;
}

void Nr_intreg::citire(std::istream &intrare)
{
    cif.Stergere();
    std::string sir;
    nr_cifre = 0;
    intrare>>sir;
    int s;
    if(sir[0] >= '0' && sir[0] <= '9')
    {
        semn = '+';
        s = 0;
    }
    else
    {
        semn = '-';
        s = 1;
    }
    for(int i=s;i<sir.length();i++)
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

void Nr_intreg::scriere(std::ostream &iesire) const
{
    if(semn == '-')
        iesire<<semn;
    Nr_natural::scriere(iesire);
}


Nr_intreg Nr_intreg::operator+(Nr_intreg &ni)
{
    Nr_intreg sum;
    if(semn == ni.semn)
    {
        sum.semn = semn;
        sum.Nr_natural::operator=(this->Nr_natural::operator+(ni));
    }
    else
    {
        if(this->Nr_natural::operator>=(ni))
            sum.semn = (*this).semn;
        else sum.semn = ni.semn;
        sum.Nr_natural::operator=(this->Nr_natural::operator-(ni));
    }
    if(sum.cif.elem[0] == 0)
        sum.semn = '+';
    return sum;
}

bool Nr_intreg::operator>=(const Nr_intreg &ni)
{
    if(this->semn == '+' && ni.semn == '-')
        return 1;
    if(this->semn == '-' && ni.semn == '+')
        return 0;
    if(this->semn == '+' && ni.semn == '+')
        return (this->Nr_natural::operator>=(ni));
    if(this->semn == '-' && ni.semn == '-')
        return !(this->Nr_natural::operator>=(ni));
}

Nr_intreg Nr_intreg::operator-(Nr_intreg &ni)
{
    Nr_intreg dif;
    if((*this).semn == ni.semn)
    {
        if(ni>=(*this))
            dif.semn = '-';
        else dif.semn = '+';
        dif.Nr_natural::operator=(this->Nr_natural::operator-(ni));
    }
    else
    {
        dif.semn = (*this).semn;
        dif.Nr_natural::operator=(this->Nr_natural::operator+(ni));
    }

    if(dif.cif.elem[0] == 0)
            dif.semn = '+';
    return dif;
}

Nr_intreg Nr_intreg::operator*(Nr_intreg &ni)
{
    Nr_intreg prod;
    if((*this).semn == ni.semn)
        prod.semn = '+';
    else prod.semn = '-';
    prod.Nr_natural::operator=(this->Nr_natural::operator*(ni));
    return prod;
}
