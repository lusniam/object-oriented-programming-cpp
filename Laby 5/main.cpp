#include "Tstudent.cpp"

using namespace std;

int main(){
    Tstudent student;
    student.wyswietl();
    student.Tosoba::wyswietl();
    Tstudent student2("jan","kowalski","umcs",3);
    student2.wyswietl();

    return EXIT_SUCCESS;
}