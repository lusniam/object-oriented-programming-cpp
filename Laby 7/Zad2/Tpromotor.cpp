#include "Tpromotor.h"

using namespace std;

Tpromotor::Tpromotor(){
    imie="";
    nazwisko="";
}

void Tpromotor::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
}

string Tpromotor::zwrocNazwe(){    return imie+" "+nazwisko;    }