#include "Twymiana2.cpp"

int main(){
    Tcennik* cennik=new Tcennik;
    cennik->wczytaj();
    Twymiana sam1(cennik);
    sam1.wczytaj();
    Twymiana sam2(cennik);
    sam2.wczytaj();
    cout<<endl;
    cennik->wyswietl();
    cout<<endl;
    sam1.wyswietl();
    cout<<endl;
    sam2.wyswietl();
    cout<<endl;
    Twymiana2 sam3(cennik); //obiekt
    sam3.wczytaj();
    sam3.wyswietl();
    return 0;
}