#ifndef T_OSOBA3
#define T_OSOBA3
#include <string>

class Tosoba3{
    private:
        std::string nazwisko;
    public:
        //Tosoba3(std::string naz);
        //Tosoba3(std::string * naz);
        //Tosoba3(std::string & naz);
        Tosoba3(const std::string & naz);
        void getNazwisko();
};
#endif