#define T_OSOBAS
#ifdef T_OSOBAS
#include <string>

class TosobaS{
    private:
        static int liczbaObiektow;//pole statyczne
        static std::string kraj;
    protected:
        std::string nazwisko, imie;
        int wiek;
    public:
        TosobaS();
        TosobaS(std::string nazwisko, std::string imie, int wiek);
        TosobaS(TosobaS & ref);
        void podajDane();
        void wyswietl();
        ~TosobaS();
        static int ile();//metoda statyczna
        static std::string getKraj();
};
//konieczna redefinicja statycznych pol z ewentualna inicjalizacja
int TosobaS::liczbaObiektow=0;
std::string TosobaS::kraj="Polska";
#endif