#include "Tsamochod.h"
#include <iostream>

using namespace std;

Tsamochod::Tsamochod(){
    nrRej="";
    marka="";
    model="";
    cena=0;
    stanL=0;
}

Tsamochod::Tsamochod(const std::string & nr,const std::string & mar,const std::string & mod,const int & c,const int & stl){
    this->nrRej=nr;
    this->marka=mar;
    this->model=mod;
    this->cena=c;
    this->stanL=stl;
}

Tsamochod::Tsamochod(Tsamochod & ref){
    nrRej=ref.nrRej;
    marka=ref.marka;
    model=ref.model;
    cena=ref.cena;
    stanL=ref.stanL;
}

Tsamochod::~Tsamochod(){
    cout<<"Dekonstruktor klasy Tsamochod"<<endl;
}
        
void Tsamochod::wprowadzDane(){
    cout<<"Podaj numer rejestracyjny: ";
    cin>>nrRej;
    cout<<"Podaj marke: ";
    cin>>marka;
    cout<<"Podaj model: ";
    cin>>model;
    cout<<"Podaj cene: ";
    cin>>cena;
    cout<<"Podaj stan licznika: ";
    cin>>stanL;
}

void Tsamochod::wyswietlDane(){
    cout<<"Podano dane dla samochodu "<<marka<<" "<<model<<" o numerach rejestracyjnych "<<nrRej<<endl;
    cout<<"Jego koszt to "<<cena<<" zl"<<endl;
    cout<<"Ma przejechane "<<stanL<<" km"<<endl;
}
void Tsamochod::zwiekszStanL(int km){
    stanL+=km;
}