#include "Tdata.h"

Tdata::Tdata(){
    //std::cout<<"Konstruktor domyslny klasy Tdata"<<std::endl;
    this->d=5;
    this->m=7;
    this->r=2003;
}

Tdata::~Tdata(){
    //std::cout<<"Destruktor klasy Tdata"<<std::endl;
}

void Tdata::wczytaj(){
    std::cout<<"Podaj date(dzien, miesiac, rok):"<<std::endl;
    std::cin>>d>>m>>r;
}

int Tdata::getR(){return r;}

void Tdata::wyswietl(){
    std::cout<<"Podana data: "<<d<<'.'<<m<<'.'<<r<<"\nRok "<<getR()<<std::endl;
}