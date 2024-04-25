#include "Ifigura.h"
#include <iostream>

using namespace std;

Ifigura::Ifigura(){
    cout<<"Konstruktor domyslny klasy Ifigura"<<endl;
}

Ifigura::Ifigura(string n){
    cout<<"Konstruktor z parametrami klasy Ifigura"<<endl;
    nazwa=n;
}

Ifigura::~Ifigura(){
    cout<<"Destruktor klasy Ifigura"<<endl;
}

void Ifigura::info(){
    cout<<nazwa;
}

void Ifigura::rysuj(){
    cout<<"Rysuje ";
    info();
    cout<<endl;
}

void Ifigura::wyswietl(){
    rysuj();
    cout<<"Pole = "<<pole()<<endl;
    cout<<"Obwod = "<<obwod()<<endl;
}