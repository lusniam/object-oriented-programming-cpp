#ifndef T_TIME
#define T_TIME

#include <iostream>
#include <string>

using namespace std;

class Ttime{
    public:
        int godz;
        int min;
        Ttime(int g, int m);
        ~Ttime();
        Ttime operator+(Ttime b);
        Ttime operator-(Ttime b);
        friend ostream & operator<<(ostream & os, const Ttime & d);
};

#endif