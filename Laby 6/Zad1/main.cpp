#include "Tinstrument.cpp"
#include "Ttrabka.cpp"
#include "Tskrzypce.cpp"

int main(){
    Tinstrument instr1;
    instr1.muzyka(2);
    Ttrabka tr1;
    tr1.muzyka(3);
    Tskrzypce skr1;
    skr1.muzyka(4);

    return EXIT_SUCCESS;
}