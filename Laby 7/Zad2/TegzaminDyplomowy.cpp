#include "TegzaminDyplomowy.h"

TegzaminDyplomowy::TegzaminDyplomowy(int ls, Tstudent** st){
    liczbaS=ls;
    student=st;
}

void TegzaminDyplomowy::wczytaj(){
    for(int i=0;i<liczbaS;i++){
        cout<<"Podaj ocene z egzamninu studenta "<<student[i]->zwrocNazwe()<<": ";
        float oc;
        cin>>oc;
        student[i]->wpiszEgzamin(oc);
    }
}

void TegzaminDyplomowy::wyswietl(){
    cout<<"Lista ocen z egzaminu:"<<endl;
    for(int i=0;i<liczbaS;i++){
        cout<<student[i]->zwrocNazwe()<<": "<<student[i]->zwrocEgzamin()<<endl;
    }
}