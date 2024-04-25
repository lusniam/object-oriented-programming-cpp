#ifndef T_DATA
#define T_DATA
#include <iostream>

class Tdata{
    private:
        int d;
        int m;
        int r;
    public:
        Tdata();
        Tdata(int dd,int mm,int rr):d(dd),m(mm),r(rr){
            //std::cout<<"Konstruktor z lista klasy Tdata"<<std::endl;
        };
        ~Tdata();

        void wczytaj();
        void wyswietl();
        int getR();
};
#endif