#include "Tskrzypce.h"

Tskrzypce::Tskrzypce(){
    cout<<"Konstruktor domyslny klasy Tskrzypce"<<endl;
    nazwa="skrzypce";
}

Tskrzypce::Tskrzypce(string n){
    cout<<"Konstruktor z parametrami klasy Tskrzypce"<<endl;
    nazwa=n;
}

Tskrzypce::~Tskrzypce(){
    cout<<"Destruktor domyslny klasy Tskrzypce"<<endl;
}

string Tskrzypce::dzwiek(){
    return "la la la laa";
}