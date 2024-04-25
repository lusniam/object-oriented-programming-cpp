#include "Tkolo2.h"
#include <cmath>

using namespace std;

Tkolo2::Tkolo2(){
    cout<<"Konstruktor domyslny klasy Tkolo2"<<endl;
    nazwa="kolo";
    r=0;
}

Tkolo2::Tkolo2(string n,float rp){
    cout<<"Konstruktor z parametrami klasy Tkolo2"<<endl;
    nazwa=n;
    r=rp;
}

Tkolo2::~Tkolo2(){
    cout<<"Destruktor klasy Tkolo2"<<endl;
}

float Tkolo2::pole(){
    return M_PI*pow(r,2);
}

float Tkolo2::obwod(){
    return 2*M_PI*r;
}