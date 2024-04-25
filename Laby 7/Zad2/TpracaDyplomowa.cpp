#include "TpracaDyplomowa.h"

TpracaDyplomowa::TpracaDyplomowa(int ls,Tpromotor* pr,Tstudent** st){
    liczbaS=ls;
    promotor=pr;
    student=st;
}

void TpracaDyplomowa::wczytaj(){
    for(int i=0;i<liczbaS;i++){
        cout<<"Podaj ocene z pracy studenta "<<student[i]->zwrocNazwe()<<": ";
        float oc;
        cin>>oc;
        student[i]->wpiszPraca(oc);
    }
}

void TpracaDyplomowa::wyswietl(){
    cout<<"Lista ocen prac sprawdzonych przez promotora "<<promotor->zwrocNazwe()<<":"<<endl;
    for(int i=0;i<liczbaS;i++){
        cout<<student[i]->zwrocNazwe()<<": "<<student[i]->zwrocPraca()<<endl;
    }
}