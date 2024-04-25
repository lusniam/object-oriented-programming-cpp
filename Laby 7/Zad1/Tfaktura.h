#include "Tdokument.cpp"
#include "Ttowar.cpp"
#include "Tklient.cpp"
#ifndef T_FAKTURA
#define T_FAKTURA

using namespace std;

class Tfaktura:public Tdokument{
    protected:
        Tklient* klient;
        Ttowar* towary;
        int liczbaT;
    public:
        Tfaktura(int n, Tklient* k);
        ~Tfaktura();
        void wczytaj();
        void wyswietl();
        float suma();
};

#endif