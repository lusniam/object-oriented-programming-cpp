#include "TosobaS.h"
#include <iostream>
#include <cstring>

using namespace std;

TosobaS::TosobaS(){
    cout<<"Utworzenie obiektu klasy TosobaS"<<endl;
    nazwisko="";
    imie="";
    wiek=0;
    liczbaObiektow++;
}

TosobaS::TosobaS(string naz, string im, int w){
    cout<<"Utworzenie obiektu klasy TosobaS z parametrami"<<endl;
    nazwisko=naz;
    imie=im;
    wiek=w;
    liczbaObiektow++;
}

TosobaS::TosobaS(TosobaS & ref){
    nazwisko=ref.nazwisko;
    imie=ref.imie;
    wiek=ref.wiek;
    liczbaObiektow++;
}

void TosobaS::podajDane(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj wiek: ";
    cin>>wiek;
}

void TosobaS::wyswietl(){
    cout<<imie<<' '<<nazwisko<<", lat "<<wiek<<endl;
}

TosobaS::~TosobaS(){
    cout<<"Usuniecie obiektu klasy TosobaS"<<endl;
    liczbaObiektow--;
}

int TosobaS::ile(){
    return liczbaObiektow;
}

string TosobaS::getKraj(){
    return kraj;
}