#include "Tzespolona.h"

Tzespolona::~Tzespolona(){

}

Tzespolona Tzespolona::operator+(Tzespolona b){
    Tzespolona suma(0,0);
    suma.rzeczywista=this->rzeczywista+b.rzeczywista;
    suma.urojona=this->urojona +b.urojona;
    return suma;
}