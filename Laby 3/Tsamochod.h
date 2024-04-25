#ifndef T_SAMOCHOD
#define T_SAMOCHOD
#include <string>

class Tsamochod{
    private:
        std::string nrRej;
        std::string marka;
        std::string model;
        int cena;
        int stanL;
    public:
        Tsamochod();
        Tsamochod(const std::string & nrRej,const std::string & marka,const std::string & model,const int & cena,const int & stanL);
        Tsamochod(Tsamochod & ref);
        ~Tsamochod();
        
        void wprowadzDane();
        void wyswietlDane();
        void zwiekszStanL(int km);
};
#endif