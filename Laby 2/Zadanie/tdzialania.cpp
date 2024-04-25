#include "tdzialania.h"
#include <iostream>
#include <cmath>

void Tdzialania::podajDane(){
    std::cout<<"Podaj dwie liczby calkowite:\n";
    std::cin>>a>>b;
}

int Tdzialania::suma(){
    return a+b;
}

int Tdzialania::roznica(){
    return a-b;
}

int Tdzialania::iloczyn(){
    return a*b;
}

float Tdzialania::iloraz(){
    return (float)a/b;
}

long double Tdzialania::potega(){
    return pow(a,b);
}

void Tdzialania::wyswietl(){
    std::cout<<"Podane liczby:\n"
    <<"a = "<<a<<"\nb = "<<b<<"\na + b = "<<suma()
    <<"\na - b = "<<roznica()<<"\na * b = "<<iloczyn()
    <<"\na / b = "<<iloraz()<<"\na ^ b = "<<potega()<<"\n";
}