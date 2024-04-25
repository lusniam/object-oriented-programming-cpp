#ifndef T_PRACADYPLOMOWA
#define T_PRACADYPLOMOWA

class TpracaDyplomowa{
    private:
        int liczbaS;
        Tstudent** student;
        Tpromotor* promotor;
    public:
        TpracaDyplomowa(int ls,Tpromotor* pr,Tstudent** st);
        void wczytaj();
        void wyswietl();
};

#endif