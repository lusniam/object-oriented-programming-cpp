#include "Tprostokat2.h"

using namespace std;

Tprostokat2::Tprostokat2(){
    cout<<"Konstruktor domyslny klasy Tprostokat2"<<endl;
    nazwa="kwadrat";
    a=0;
    b=0;
}

Tprostokat2::Tprostokat2(string n,float ap,float bp){
    cout<<"Konstruktor z parametrami klasy Tprostokat2"<<endl;
    nazwa=n;
    a=ap;
    b=bp;
}

Tprostokat2::~Tprostokat2(){
    cout<<"Destruktor klasy Tprostokat2"<<endl;
}

float Tprostokat2::pole(){
    return a*b;
}

float Tprostokat2::obwod(){
    return 2*(a+b);
}