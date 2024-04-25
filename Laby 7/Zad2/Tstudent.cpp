#include "Tstudent.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tstudent::Tstudent(){
    imie="";
    nazwisko="";
    srednia=0;
    egzamin=0;
    praca=0;
}

void Tstudent::wczytaj(){
    Tpromotor::wczytaj();
    cout<<"Podaj srednia ocen z dziekanatu: ";
    cin>>srednia;
}

void Tstudent::wyswietl(){
    cout<<fixed<<setprecision(1);
    cout<<right<<setw(20)<<zwrocNazwe();
    cout<<": Srednia ocen="<<srednia;
    cout<<", ocena z egzaminu="<<egzamin;
    cout<<", ocena z pracy="<<praca;
    cout<<",\tocena koncowa="<<ocenaKoncowa()<<endl;
}

void Tstudent::wpiszEgzamin(float eg){    egzamin=eg;    }

float Tstudent::zwrocEgzamin(){    return egzamin;    }

void Tstudent::wpiszPraca(float pr){    praca=pr;    }

float Tstudent::zwrocPraca(){    return praca;    }

float Tstudent::ocenaKoncowa(){    return (2*srednia+egzamin+praca)/4;    }