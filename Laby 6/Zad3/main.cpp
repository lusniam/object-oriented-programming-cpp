#include "Ifigura.cpp"
#include "Tkolo2.cpp"
#include "Tprostokat2.cpp"
#include "Tkwadrat2.cpp"

int main(){
    cout<<"Praca na obiektach:\n\n";
    Tkolo2 kol1("kolo1",3);
    kol1.wyswietl();
    Tprostokat2 pr1("prostokat1",4,3);
    pr1.wyswietl();
    Tkwadrat2 kw1("kwadrat1",6);
    kw1.wyswietl();

    cout<<"\n\nPraca na wskaznikach:\n\n";
    Ifigura* wsk;
    wsk=&kol1;
    wsk->wyswietl();
    wsk=&pr1;
    wsk->wyswietl();
    wsk=&kw1;
    wsk->wyswietl();

    cout<<endl;
    return EXIT_SUCCESS;
}