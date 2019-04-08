#include <iostream>
#include <fstream>
#include "Clasa_Vector.h"
#include "Clasa_Nr_natural.h"
#include "Clasa_Nr_intreg.h"

using namespace std;

template <class clasa> void Swap(clasa &a,clasa &b)
{
    clasa aux;
    aux = a;
    a = b;
    b = aux;
}

template <class clasa> void Sort(clasa *v,int n)
{
    int i,j = 0,minpoz;
    clasa Min;
    for(j=0;j<n-1;j++)
    {
        Min = v[j];
        minpoz = j;
        for(i=j;i<n;i++)
        {
            if(Min >= v[i])
            {
                Min = v[i];
                minpoz = i;
            }
        }
        Swap(v[j],v[minpoz]);
    }
}

int main()
{
    ifstream f("numere.in");
    Nr_natural *vec[10];
    int i,n,t;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>t;
        if(!t)
            vec[i] = new Nr_intreg;
        else
            vec[i] = new Nr_natural;
    }
    for(i=0;i<n;i++)
    {
        f>>(*vec[i]);
        cout<<*vec[i]<<" ";
    }
    cout<<endl;
    Nr_intreg x,y,v[10];
    cin>>x>>y;
    cout<<x*y<<endl;
    cout<<x-y<<endl;
    cout<<x+y<<endl;
    Swap(x,y);
    cout<<x<<" "<<y<<endl;
    Nr_natural v1[10];
    for(i=0;i<n;i++)
    {
        f>>v1[i];
    }
    Sort(v1,n);
    for(i=0;i<n;i++)
    {
        cout<<v1[i]<<" ";
    }
    f.close();
    return 0;
}
