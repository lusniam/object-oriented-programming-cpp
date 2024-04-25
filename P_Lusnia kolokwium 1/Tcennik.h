#ifndef T_CENNIK
#define T_CENNIK

class Tcennik{
    private:
        int n;
        float* ceny;
    public:
        Tcennik(); //konstruktor
        ~Tcennik(); //destruktor
        void wczytaj();
        void wyswietl();
        float zwrocKoszt(int poz);
};

#endif