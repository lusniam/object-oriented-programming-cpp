#ifndef TPRACOWNIK_H
#define TPRACOWNIK_H

//1 zadeklaruj klase o odpowiednich polach i metodach
struct Tdata{
    int dzien;
    int miesiac;
    int rok;
};

class Tpracownik{
private:
    char imie[20];
    char nazwisko[20];
    float stawka;
    int LiczbaGodzin;
    Tdata DataZatrudnienia;
public:
    void wczytaj();
    float placa();
    void wyswietl();
};
#endif //TPRACOWNIK_H