#include "Twymiana.h"
#include <iostream>
#include <iomanip>

using namespace std;

Twymiana::Twymiana(){}

Twymiana::Twymiana(Tcennik* cen){
    data.d=1;
    data.m=1;
    data.r=1900;
    godz.m=0;
    godz.h=0;
    nrPojazdu="";
    opisWymiany="";
    cennik=cen;
    pozCennika=1;
}

void Twymiana::wczytaj(){
    cout<<"Podaj date wymiany:\nDzien: ";
    cin>>data.d;
    cout<<"Miesiac: ";
    cin>>data.m;
    cout<<"Rok: ";
    cin>>data.r;
    cout<<"Podaj godzine wymiany:\nGodzina: ";
    cin>>godz.h;
    cout<<"Minuty: ";
    cin>>godz.m;
    cout<<"Podaj numer rejestracyjny pojazdu: ";
    cin>>nrPojazdu;
    cout<<"Podaj opis wymiany: ";
    getline(cin,opisWymiany);
    getline(cin,opisWymiany);
    cout<<"Podaj pozycje uslugi w cenniku: ";
    cin>>pozCennika;
    pozCennika--;
}

void Twymiana::wyswietl(){
    cout<<"Dnia "<<data.d<<"."<<data.m<<"."<<data.r<<endl;
    cout<<"O godzinie "<<godz.h<<":"<<godz.m<<endl;
    cout<<"W samochodzie o numerze rejestracyjnym "<<nrPojazdu<<endl;
    cout<<opisWymiany<<endl;
    wyswietlKoszt();
}

void Twymiana::wyswietlKoszt(){
    cout<<"Koszt podanej uslugi w cenniku ma pozycje "<<pozCennika+1<<endl;
    cout<<"Nalezy sie kwota "<<cennik->zwrocKoszt(pozCennika)<<" zl"<<endl;
}