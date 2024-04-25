#ifndef TZESPOLONA_H
#define TZESPOLONA_H
#include <iostream>

using namespace std;
class Tzespolona{
    public:
        Tzespolona(double rz, double ur): rzeczywista(rz),urojona(ur){ };
        ~Tzespolona();
        Tzespolona operator+(Tzespolona b);
        friend ostream & operator<<(ostream & os, const Tzespolona & z);
        double rzeczywista;
        double urojona;
};

#endif