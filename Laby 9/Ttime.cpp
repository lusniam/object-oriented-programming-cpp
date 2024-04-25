#include "Ttime.h"

Ttime::Ttime(int g, int m){
    godz=g;
    min=m;
}

Ttime::~Ttime(){
    //cout<<"Destruktor Ttime"<<endl;
}

Ttime Ttime::operator+(Ttime b){
    int suma_min=this->min+this->godz*60+b.min+b.godz*60;
    Ttime suma(suma_min/60,suma_min%60);
    return suma;
}

Ttime Ttime::operator-(Ttime b){
    int roznica_min=this->min+this->godz*60-b.min-b.godz*60;
    Ttime roznica(roznica_min/60,roznica_min%60);
    return roznica;
}

ostream & operator<<(ostream & os, const Ttime & d){
    os<<d.godz<<" godz "<<d.min<<" min";
    return os;
}
