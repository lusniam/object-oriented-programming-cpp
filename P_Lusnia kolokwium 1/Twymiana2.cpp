#include "Twymiana2.h"

Twymiana2::Twymiana2(Tcennik* cen){
    data.d=1;
    data.m=1;
    data.r=1900;
    godz.m=0;
    godz.h=0;
    nrPojazdu="";
    opisWymiany="";
    cennik=cen;
    pozCennika=1;
    stalyKl=0;
}

void Twymiana2::wczytaj(){
    Twymiana::wczytaj();
    cout<<"Czy klient jest ma karte stalego klienta? (1-tak, 0-nie): ";
    cin>>stalyKl;
}

void Twymiana2::wyswietlKoszt(){
    cout<<"Podany klient ";
    if(stalyKl){
        cout<<"posiada karte stalego klienta"<<endl;
        cout<<"Koszt podanej uslugi w cenniku ma pozycje "<<pozCennika+1<<endl;
        cout<<"Nalezy sie kwota "<<cennik->zwrocKoszt(pozCennika)*0.9<<" zl"<<endl;
    }
    else{
        cout<<"nie posiada karty stalego klienta"<<endl;
        Twymiana:wyswietlKoszt();
    }
}