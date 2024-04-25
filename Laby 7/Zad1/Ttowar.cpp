#include "Ttowar.h"

Ttowar::Ttowar(){
    kod="";
    nazwa="";
    ilosc=0;
    cena=0;
}
void Ttowar::wczytaj(){
    cout<<"Podaj kod towaru: ";
    getline(cin,kod);
    cout<<"Podaj nazwe towaru: ";
    getline(cin,nazwa);
    cout<<"Podaj ilosc towaru: ";
    cin>>ilosc;
    cout<<"Podaj cene towaru: ";
    cin>>cena;
    string w;
    getline(cin,w);
}

void Ttowar::wyswietl(){
    cout<<left;
    cout<<setw(20)<<nazwa;
    cout<<setw(10)<<kod;
    cout<<fixed<<setprecision(2)<<right;
    cout<<setw(15)<<ilosc;
    cout<<setw(15)<<cena;
    cout<<setw(20)<<oblicz();
    cout<<endl;
}

float Ttowar::oblicz(){    return ilosc*cena;    }