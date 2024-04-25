#include "Tfigura.cpp"
#include "Tkolo.cpp"
#include "Tprostokat.cpp"
#include "Tkwadrat.cpp"

int main(){
    Tfigura fig1;
    fig1.wyswietl();
    Tkolo kol1("kolo1",3);
    kol1.wyswietl();
    Tprostokat pr1("prostokat1",4,3);
    pr1.wyswietl();
    Tkwadrat kw1("kwadrat1",6);
    kw1.wyswietl();

    return EXIT_SUCCESS;
}