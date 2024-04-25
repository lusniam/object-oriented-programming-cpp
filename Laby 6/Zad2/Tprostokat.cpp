#include "Tprostokat.h"

using namespace std;

Tprostokat::Tprostokat(){
    cout<<"Konstruktor domyslny klasy Tprostokat"<<endl;
    nazwa="kwadrat";
    a=0;
    b=0;
}

Tprostokat::Tprostokat(string n,float ap,float bp){
    cout<<"Konstruktor z parametrami klasy Tprostokat"<<endl;
    nazwa=n;
    a=ap;
    b=bp;
}

Tprostokat::~Tprostokat(){
    cout<<"Destruktor klasy Tprostokat"<<endl;
}

float Tprostokat::pole(){
    return a*b;
}

float Tprostokat::obwod(){
    return 2*(a+b);
}