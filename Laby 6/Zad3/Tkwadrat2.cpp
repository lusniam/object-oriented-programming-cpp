#include "Tkwadrat2.h"
#include <cmath>

using namespace std;

Tkwadrat2::Tkwadrat2(){
    cout<<"Konstruktor domyslny klasy Tkwadrat2"<<endl;
    nazwa="kwadrat";
    a=0;
    b=0;
}

Tkwadrat2::Tkwadrat2(string n,float ap){
    cout<<"Konstruktor z parametrami klasy Tkwadrat2"<<endl;
    nazwa=n;
    a=ap;
}

Tkwadrat2::~Tkwadrat2(){
    cout<<"Destruktor klasy Tkwadrat2"<<endl;
}

float Tkwadrat2::pole(){
    return pow(a,2);
}

float Tkwadrat2::obwod(){
    return 4*a;
}