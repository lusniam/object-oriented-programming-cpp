#include <iostream>
using namespace std;


int main()
{
    int c0=0;
    while(c0<=0){
      cout<<"Podaj liczbe c0: ";
      cin >> c0;
    }
    while(c0!=1){
         if(c0%2==0){
           c0/=2;
           cout<<"c0 jest parzyste, dziele przez 2, nowa wartosc to "<<c0<<endl;
         }
         else{
           c0*=3;
           c0++;
           cout<<"c0 jest nieparzyste, mnoze przez 3 i dodaje 1, nowa wartosc to: "<<c0<<endl;
         }
    }
    cout<<"Wartosc c0 jest rowna 1"<<endl;
    
    system("pause");
}