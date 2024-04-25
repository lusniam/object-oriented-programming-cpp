#include "Ttrojkat.h"
#include <iostream>
#include <cmath>

using namespace std;

Ttrojkat::Ttrojkat(){
    a=0;
    b=0;
    c=0;
    h=0;
}

void Ttrojkat::wczytaj(){
    cout<<"Podaj dlugosc boku a: ";
    cin>>a;
    cout<<"Podaj dlugosc boku b (0, jesli nieznana): ";
    cin>>b;
    if(b==0){
        cout<<"Podaj dlugosc wysokosci h: ";
        cin>>h;
    }
    else{
        cout<<"Podaj dlugosc boku c: ";
        cin>>c;
    }
}

float Ttrojkat::pole(int a,int b,int c){
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c)); 
}

float Ttrojkat::pole(int a,int h){
    return a*h/2;
}

void Ttrojkat::wyswietl(){
    cout<<"Pole tego trojkata wynosi ";
    if(b==0)
        cout<<pole(a,h)<<endl;
    else
        cout<<pole(a,b,c)<<endl;
}