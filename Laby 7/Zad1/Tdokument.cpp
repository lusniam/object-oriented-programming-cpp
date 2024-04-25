#include "Tdokument.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tdokument::Tdokument(){
    nr="";
    nazwa="";
    data.d=1;
    data.m=1;
    data.r=1900;
}

void Tdokument::wczytaj(){
    cout<<"Podaj numer faktury: ";
    getline(cin,nr);
    cout<<"Podaj nazwe faktury: ";
    getline(cin,nazwa);
    cout<<"Podaj date wystawienia faktury: ";
    cin>>data.d>>data.m>>data.r;
    string w;
    getline(cin,w);
}

void Tdokument::wyswietl(){
    cout<<nazwa<<" nr "<<nr;
    cout<<setw(66-nazwa.length()-nr.length())<<" ";
    cout<<right<<setfill('0');
    cout<<setw(2)<<data.d<<".";
    cout<<setw(2)<<data.m<<".";
    cout<<setw(4)<<data.r<<endl;
    cout<<setfill(' ');
}