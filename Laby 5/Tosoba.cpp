#include "Tosoba.h"
#include <iostream>

Tosoba::Tosoba(){
    cout<<"Konstruktor domyslny klasy tosoba"<<endl;
    imie="maciej";
    nazwisko="lusnia";
}

Tosoba::Tosoba(string im, string naz){
    cout<<"Konstruktor z parametrami klasy tosoba"<<endl;
    imie=im;
    nazwisko=naz;
}

Tosoba::~Tosoba(){
    cout<<"Destruktor klasy tosoba"<<endl;
}

void Tosoba::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
}

void Tosoba::wyswietl(){
    cout<<imie<<" "<<nazwisko<<endl;
}