#ifndef T_EGZAMINDYPLOMOWY
#define T_EGZAMINDYPLOMOWY

class TegzaminDyplomowy{
    private:
        int liczbaS;
        Tstudent** student;
    public:
        TegzaminDyplomowy(int ls, Tstudent** st);
        void wczytaj();
        void wyswietl();
};
#endif