#include "Tklient.h"
#include <iostream>
#include <iomanip>

Tklient::Tklient(){
    NIP="";
    imie="";
    nazwisko="";
}

void Tklient::wczytaj(){
    cout<<"Podaj imie klienta: ";
    getline(cin,imie);
    cout<<"Podaj nazwisko klienta: ";
    getline(cin,nazwisko);
    cout<<"Podaj NIP klienta: ";
    getline(cin,NIP);
}

void Tklient::wyswietl(){
    cout<<imie<<" "<<nazwisko<<endl;
    cout<<NIP<<endl;
}