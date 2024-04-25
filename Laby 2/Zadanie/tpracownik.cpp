#include "tpracownik.h"
#include <iostream>

using namespace std;    
//2 zdefiniuj metody zadeklarowane w klasie
void Tpracownik::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj stawke za godzine: ";
    cin>>stawka;
    cout<<"Podaj liczbe godzin: ";
    cin>>LiczbaGodzin;
    string data;
    cout<<"Podaj date zatrudnienia: (dzien, miesiac, rok, oddzielone enterem)"<<endl;
    cin>>DataZatrudnienia.dzien>>DataZatrudnienia.miesiac>>DataZatrudnienia.rok;
}
float Tpracownik::placa(){
    return stawka*LiczbaGodzin;
}
void Tpracownik::wyswietl(){
    cout<<"Pracownik: "<<imie<<" "<<nazwisko<<endl;
    cout<<"Zatrudniony "<<DataZatrudnienia.dzien<<'.'
    <<DataZatrudnienia.miesiac<<'.'<<DataZatrudnienia.rok<<endl;
    cout<<"Za "<<LiczbaGodzin<<" godzin pracy o stawce "<<stawka
    <<"zl otrzyma "<<placa()<<" zl"<<endl;
}