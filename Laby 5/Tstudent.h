#ifndef T_STUDENT
#define T_STUDENT
#include "Tosoba.cpp"

class Tstudent:public Tosoba{
    protected:
        string uczelnia;
        float* oceny;
        int liczbaOcen;
    public:
        Tstudent();
        Tstudent(string im, string naz, string u, int lo);
        ~Tstudent();
        void wczytaj();
        void wyswietl();
        float srednia();
        bool czyZaliczyl();
        void wczytajoceny();
};

#endif