#include "Tosoba3.h"
#include <iostream>

using namespace std;

/*Tosoba3::Tosoba3(string naz){
    cout<<"Adres parametru naz: "<<&naz<<endl;
    nazwisko=naz;
}*/

/*Tosoba3::Tosoba3(string* naz){
    cout<<"Adres parametru naz: "<<naz<<endl;
    nazwisko=*naz;
}*/

/*Tosoba3::Tosoba3(string & naz){
    cout<<"Adres parametru naz: "<<naz<<endl;
    nazwisko=naz;
}*/

Tosoba3::Tosoba3(const string & naz){
    cout<<"Adres parametru naz: "<<&naz<<endl;
    nazwisko=naz;
    naz="kowalski";
}

void Tosoba3::getNazwisko(){
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
}