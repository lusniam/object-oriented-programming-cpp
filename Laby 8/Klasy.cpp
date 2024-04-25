#include "Klasy.h"

string Tdomownik::kod="";

Tdomownik::Tdomownik(){
    nazwa="";
    sekret="";
}

void Tdomownik::setkod(string k){
    kod=k;
}

string Tdomownik::getkod(){
    return kod;
}

void Tdomownik::wczytaj(){
    cout<<"Podaj imie: ";
    getline(cin,nazwa);
    cout<<"Podaj sekret: ";
    getline(cin,sekret);
}

void Tdomownik::wyswietl(){
    cout<<nazwa<<": "<<sekret;
}

ostream & operator<<(ostream & os, const Tdomownik & d){
    os<<"Moje imie to: "<<d.nazwa<<", moj sekret to: "<<d.sekret<<", kod do mojego domu to: "<<d.getkod();
    return os;
}

Tsasiad::Tsasiad(string n){
    nazwa=n;
}

void Tsasiad::info(Tdomownik *wsk){
    cout<<"Ja sasiad "<<this->nazwa<<" znam sekret domownika ";
    wsk->wyswietl();
    cout<<" i kod do ich domu: "<<wsk->kod<<endl;
}