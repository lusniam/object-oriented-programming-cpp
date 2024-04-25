#include <string>
#ifndef T_DOKUMENT
#define T_DOKUMENT

struct Tdata{
    int d;
    int m;
    int r;
};

class Tdokument{
    protected:
        std::string nr;
        std::string nazwa;
        Tdata data;
    public:
        Tdokument();
        void wczytaj();
        void wyswietl();
};

#endif