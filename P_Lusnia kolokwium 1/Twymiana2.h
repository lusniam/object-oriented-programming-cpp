#ifndef T_WYMIANA2
#define T_WYMIANA2
#include "Twymiana.cpp"

class Twymiana2:public Twymiana{ //dziedziczenie
    private:
        bool stalyKl;
    public:
        Twymiana2(Tcennik* cen);
        void wczytaj();
        void wyswietlKoszt(); //przeslanianie
};

#endif