#include <iostream>
#include <string>

using namespace std;

struct pracownik{
    string imie;
    string nazwisko;
    float stawka;
    float godziny;
    string data_zat;
    float wyplata;
};

int main(){
    int n;
    cout<<"Podaj liczbe pracownikow: ";
    cin>>n;
    struct pracownik pracownicy[n];
    for(int i=0;i<n;i++){
        cout<<"\nPracownik "<<i+1<<endl;
        cout<<"Imie: ";
        cin>>pracownicy[i].imie;
        cout<<"Nazwisko: ";
        cin>>pracownicy[i].nazwisko;
        cout<<"Stawka za godzine: ";
        cin>>pracownicy[i].stawka;
        cout<<"Liczba godzin: ";
        cin>>pracownicy[i].godziny;
        cout<<"Data zatrudnienia: ";
        cin>>pracownicy[i].data_zat;
        pracownicy[i].wyplata=pracownicy[i].stawka*pracownicy[i].godziny;
    }

    cout<<"\nLista plac pracownikow:"<<endl;
    for(int i=0;i<n;i++)
        cout<<pracownicy[i].imie<<" "<<pracownicy[i].nazwisko<<": "<<pracownicy[i].wyplata<<" zl"<<endl;
    cout<<endl;
    system("pause");
    return 0;
}