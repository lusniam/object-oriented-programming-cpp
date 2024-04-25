#include "Tosoba2.h"
#include <iostream>

using namespace std;

Tosoba2::Tosoba2(){
    imie="";
    nazwisko="";
    dataUr={0,0,0};
}

Tosoba2::Tosoba2(const string & naz,const string & im,const Tdata & d){
    this->nazwisko=naz;
    this->imie=im;
    this->dataUr=d;
}

void Tosoba2::wczytaj(){
    cout<<"Podaj nazwisko i imie: ";
    cin>>nazwisko>>imie;
    cout<<"Podaj motto:";
    cin.ignore();
    getline(cin,motto);
    cout<<"Podaj date urodzenia(dzien, miesiac, rok)";
    int d,m,r;
    cin>>d>>m>>r;
    dataUr={d,m,r};
}

void Tosoba2::wyswietl(){
    cout<<"Osoba nazywa sie "<<imie<<nazwisko<<endl;
    cout<<"Jej motto to \""<<motto<<"\""<<endl;
    cout<<"Jej data urodzenia to "<<dataUr.getR()<<endl;
}

string Tosoba2::GetNazwiskoImie(){return nazwisko+" "+imie;}

int Tosoba2::roznicaWieku(Tosoba2 & partner){return abs(dataUr.getR()-partner.dataUr.getR());}

string Tosoba2::dluzszeNazwisko(Tosoba2 & partner){
    if(nazwisko.length()>partner.nazwisko.length()) return nazwisko;
    else return partner.nazwisko;
}