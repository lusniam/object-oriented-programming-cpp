#include "Tpromotor.cpp"
#include <string>
#ifndef T_STUDENT
#define T_STUDENT

class Tstudent:public Tpromotor{
    private:
        float srednia;
        float egzamin;
        float praca;
    public:
        Tstudent();
        void wczytaj();
        void wyswietl();
        void wpiszEgzamin(float eg);
        float zwrocEgzamin();
        void wpiszPraca(float pr);
        float zwrocPraca();
        float ocenaKoncowa();
};

#endif