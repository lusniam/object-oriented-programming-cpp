#include "Tfaktura.h"

Tfaktura::Tfaktura(int n, Tklient* k){
    liczbaT=n;
    towary = new Ttowar [liczbaT];
    klient=k;
}

Tfaktura::~Tfaktura(){
    delete [] towary;
}

void Tfaktura::wczytaj(){
    Tdokument::wczytaj();
    for(int i=0;i<liczbaT;i++){
        towary[i].wczytaj();
    }
}

void Tfaktura::wyswietl(){
    Tdokument::wyswietl();
    cout<<endl<<"Dane klienta:"<<endl;
    klient->wyswietl();
    cout<<endl<<"Lista towarów:"<<endl;
    for(int i=0;i<liczbaT;i++){
        towary[i].wyswietl();
    }
    cout<<"Suma:"<<right<<setw(75)<<setprecision(2)<<suma()<<endl<<endl;
}

float Tfaktura::suma(){
    float wynik=0;
    for(int i=0;i<liczbaT;i++){
        wynik+=towary[i].oblicz();
    }
    return wynik;
}