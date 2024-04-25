#include "Tcennik.h"
#include <iostream>

using namespace std;

Tcennik::Tcennik(){
    n=1;
    ceny=new float[n];
    ceny[0]=1;
}

Tcennik::~Tcennik(){
    delete ceny;
}

void Tcennik::wczytaj(){
    delete ceny;
    cout<<"Podaj liczbe pozycji w cenniku: ";
    cin>>n;
    ceny=new float[n];
    for(int i=0;i<n;i++){
        cout<<"Podaj cene pozycji "<<i+1<<": ";
        cin>>ceny[i];
    }
}

void Tcennik::wyswietl(){
    cout<<"Cennik:"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<": "<<ceny[i]<<endl;
    }
}

float Tcennik::zwrocKoszt(int poz){
    return ceny[poz];
}