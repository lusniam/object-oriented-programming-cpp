#include "tstudent.h"
#include "iostream"

using namespace std;

void Tstudent::wczytaj(){
    cout<<"Podaj imie studenta: ";
    cin>>imie;
    cout<<"Podaj nazwisko studenta: ";
    cin>>nazwisko;
    cout<<"Podaj pierwsza ocene: ";
    cin>>oceny[0];
    cout<<"Podaj druga ocene: ";
    cin>>oceny[1];
    cout<<"Podaj trzecia ocene: ";
    cin>>oceny[2];
}
float Tstudent::srednia(){
    return (oceny[0]+oceny[1]+oceny[2])/3;
}
void Tstudent::wyswietl(){
    cout<<imie<<' '<<nazwisko<<" ma srednia "<<srednia()<<" z trzech egzaminow"<<endl;
}