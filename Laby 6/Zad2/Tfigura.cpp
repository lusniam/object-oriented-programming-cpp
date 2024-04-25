#include "Tfigura.h"
#include <iostream>

using namespace std;

Tfigura::Tfigura(){
    cout<<"Konstruktor domyslny klasy Tfigura"<<endl;
}

Tfigura::Tfigura(string n){
    cout<<"Konstruktor z parametrami klasy Tfigura"<<endl;
    nazwa=n;
}

Tfigura::~Tfigura(){
    cout<<"Destruktor klasy Tfigura"<<endl;
}

void Tfigura::info(){
    cout<<nazwa;
}

void Tfigura::rysuj(){
    cout<<"Rysuje ";
    info();
    cout<<endl;
}

float Tfigura::pole(){
    return 0;
}

float Tfigura::obwod(){
    return 0;
}

void Tfigura::wyswietl(){
    rysuj();
    cout<<"Pole = "<<pole()<<endl;
    cout<<"Obwod = "<<obwod()<<endl;
}