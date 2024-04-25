#include "Tstudent.h"
#include <iostream>

Tstudent::Tstudent():Tosoba(){
    cout<<"Konstruktor domyslny klasy Tstudent"<<endl;
    uczelnia="pl";
    liczbaOcen=1;
    oceny=new float [1];
    oceny[0]=2;
}

Tstudent::Tstudent(string im, string naz, string u, int lo):Tosoba(im,naz){
    cout<<"Konstruktor z parametrami klasy tstudent"<<endl;
    uczelnia=u;
    liczbaOcen=lo;
    oceny=new float [liczbaOcen];
    wczytajoceny();
}

Tstudent::~Tstudent(){
    cout<<"Destruktor klasy Tstudent"<<endl;
    delete [] oceny;
}

void Tstudent::wczytaj(){
    Tosoba::wczytaj();
    cout<<"Podaj uczelnie: ";
    cin>>uczelnia;
    cout<<"Podaj liczbe ocen: ";
    cin>>liczbaOcen;
    delete [] oceny;
    oceny=new float[liczbaOcen];
    wczytajoceny();
}

void Tstudent::wyswietl(){
    Tosoba::wyswietl();
    cout<<"Uczelnia: "<<uczelnia<<endl;
    cout<<"Srednia ocen: "<<srednia()<<endl;
    cout<<"Student ";
    if (czyZaliczyl()){
        cout<<"zaliczyl semestr"<<endl;
    }
    else{
        cout<<"nie zaliczyl semestru"<<endl;
    }
}

float Tstudent::srednia(){
    if (liczbaOcen==0){return 0;}
    float suma=0;
    for(int i=0;i<liczbaOcen;i++){
        suma+=oceny[i];
    }
    return suma/liczbaOcen;
}

bool Tstudent::czyZaliczyl(){
    for(int i=0;i<liczbaOcen;i++){
        if(oceny[i]<3.0){
            return false;
        }
    }
    return true;
}

void Tstudent::wczytajoceny(){
    for(int i=0;i<liczbaOcen;i++){
        cout<<"Podaj ocene: ";
        cin>>oceny[i];
    }
}