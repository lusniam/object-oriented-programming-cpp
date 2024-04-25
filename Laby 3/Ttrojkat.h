#ifndef T_TROJKAT
#define T_TROJKAT

class Ttrojkat{
    private:
        int a,b,c,h;
    public:
        Ttrojkat();
        void wczytaj();
        float pole(int a,int b,int c);
        float pole(int a,int h);
        void wyswietl();
};

#endif