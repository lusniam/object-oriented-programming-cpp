#include "Tinstrument.h"
#include <iostream>

using namespace std;

Tinstrument::Tinstrument(){
    cout<<"Konstruktor domyslny klasy Tinstrument"<<endl;
    nazwa="nieznany";
}

Tinstrument::Tinstrument(string n){
    cout<<"Konstruktor z parametrami klasy Tinstrument"<<endl;
    nazwa=n;
}

Tinstrument::~Tinstrument(){
    cout<<"Destruktor domyslny klasy Tinstrument"<<endl;
}

string Tinstrument::dzwiek(){
    return "yyy";
}

void Tinstrument::muzyka(int n){
    cout<<"Gra instrument "<<nazwa<<": ";
    for(int i=0;i<n;i++)    cout<<dzwiek()<<" ";
    cout<<endl;
}