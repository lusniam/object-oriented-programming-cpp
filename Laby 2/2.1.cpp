#include <iostream>
#include <string>

using namespace std;
//1 zadeklaruj klase o odpowiednich polach i metodach
struct Tdata{
    int dzien;
    int miesiac;
    int rok;
};

class Tpracownik{
private:
    string imie;
    string nazwisko;
    float stawka;
    int LiczbaGodzin;
    Tdata DataZatrudnienia;
public:
    void wczytaj();
    float placa();
    void wyswietl();
};

void Tpracownik::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj stawke za godzine: ";
    cin>>stawka;
    cout<<"Podaj liczbe godzin: ";
    cin>>LiczbaGodzin;
    string data;
    cout<<"Podaj date zatrudnienia: (dzien, miesiac, rok, oddzielone enterem)"<<endl;
    cin>>DataZatrudnienia.dzien>>DataZatrudnienia.miesiac>>DataZatrudnienia.rok;
}
float Tpracownik::placa(){
    return stawka*LiczbaGodzin;
}

void Tpracownik::wyswietl(){
    cout<<"Pracownik: "<<imie<<" "<<nazwisko<<endl;
    cout<<"Zatrudniony "<<DataZatrudnienia.dzien<<'.'
    <<DataZatrudnienia.miesiac<<'.'<<DataZatrudnienia.rok<<endl;
    cout<<"Za "<<LiczbaGodzin<<" godzin pracy o stawce "<<stawka
    <<" otrzyma "<<placa()<<" zl"<<endl;
}
//2 zdefiniuj metody zadeklarowane w klasie
int main(){
    //3 zadeklaruj obiekt danej klasy
    Tpracownik pracownik1, pracownik2;

    //4 wykonaj metody dla danego obiektu
    pracownik1.wczytaj();
    pracownik2.wczytaj();
    pracownik1.wyswietl();
    pracownik2.wyswietl();
    system("pause");
    return EXIT_SUCCESS;
}