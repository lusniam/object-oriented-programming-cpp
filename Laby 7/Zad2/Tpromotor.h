#ifndef T_PROMOTOR
#define T_PROMOTOR
#include <string>

class Tpromotor{
    protected:
        std::string imie;
        std::string nazwisko;
    public:
        Tpromotor();
        void wczytaj();
        std::string zwrocNazwe();
};

#endif