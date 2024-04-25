#include "Tkolo.h"
#include <cmath>

using namespace std;

Tkolo::Tkolo(){
    cout<<"Konstruktor domyslny klasy Tkolo"<<endl;
    nazwa="kolo";
    r=0;
}

Tkolo::Tkolo(string n,float rp){
    cout<<"Konstruktor z parametrami klasy Tkolo"<<endl;
    nazwa=n;
    r=rp;
}

Tkolo::~Tkolo(){
    cout<<"Destruktor klasy Tkolo"<<endl;
}

float Tkolo::pole(){
    return M_PI*pow(r,2);
}

float Tkolo::obwod(){
    return 2*M_PI*r;
}