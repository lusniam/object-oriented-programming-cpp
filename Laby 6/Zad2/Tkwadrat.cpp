#include "Tkwadrat.h"
#include <cmath>

using namespace std;

Tkwadrat::Tkwadrat(){
    cout<<"Konstruktor domyslny klasy Tkwadrat"<<endl;
    nazwa="kwadrat";
    a=0;
    b=0;
}

Tkwadrat::Tkwadrat(string n,float ap){
    cout<<"Konstruktor z parametrami klasy Tkwadrat"<<endl;
    nazwa=n;
    a=ap;
}

Tkwadrat::~Tkwadrat(){
    cout<<"Destruktor klasy Tkwadrat"<<endl;
}

float Tkwadrat::pole(){
    return pow(a,2);
}

float Tkwadrat::obwod(){
    return 4*a;
}