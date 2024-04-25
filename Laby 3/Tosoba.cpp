#include "Tosoba.h"
#include <iostream>
#include <string.h>

using namespace std;

Tosoba::Tosoba(){
    cout<<"Konstruktor domyslny klasy Tosoba"<<endl;
    imie="maciej";
    strcpy(nazwisko,"lusnia");
    data.d=5;
    data.m=7;
    data.r=2003;
}

Tosoba::Tosoba(const string & im,const char* naz,Tdata dat){
    cout<<"Konstruktor z parametrami klasy Tosoba"<<endl;
    imie=im;
    strcpy(nazwisko,naz);
    data=dat;
}

Tosoba::~Tosoba(){
    cout<<"Dekonstruktor klasy Tosoba"<<endl;
}

void Tosoba::wczytaj(){
    cout<<"podaj imie: ";
    cin>>imie;
    cout<<"podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"podaj dzien: ";
    cin>>data.d;
    cout<<"podaj miesiac: ";
    cin>>data.m;
    cout<<"podaj rok: ";
    cin>>data.r;
}

void Tosoba::info(int rok){
    cout<<"ta osoba to ";
    int wiek=rok-data.r;
    if (wiek>=50) cout<<"osoba 50+"<<endl;
    else if (wiek>=30) cout<<"osoba 30+"<<endl;
    else if (wiek>=18) cout<<"osoba pelnoletnia"<<endl;
    else cout<<"osoba 50+"<<endl;
}

void Tosoba::info(){
    cout<<"ta osoba miala 18 lat w roku "<<data.r+18<<endl;
}

void Tosoba::wyswietl(int rok){
    cout<<imie<<" "<<nazwisko<<" "<<rok-data.r<<endl;
}

void Tosoba::wyswietl(){
    cout<<imie<<" "<<nazwisko<<" "<<data.d<<" "<<data.m<<" "<<data.r<<endl;
}