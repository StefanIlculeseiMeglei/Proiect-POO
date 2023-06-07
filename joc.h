#ifndef JOC_H
#define JOC_H
#include <termios.h>
#include <iostream>
#include "afisare.h"
#include "calculator.h"
class joc
{
    private:
    const string numeFisierPuncte = "puncte.txt";
    const int VALOAREA_CASTIG = 100;
    const int CALCULATOR = 0;
    const int OM = 1;
    int DIFICULTATE;
    afisare A;
    calculator calc;
    int puncte;
    public:
        joc();
        virtual ~joc();
        void start(matrice);
        int getPuncte(void);
        void updatePuncte(int jucator,int status);
        void reseteazaPuncte();
        void setDificultate(string x);
        int  verificaCastig(matrice mat);
};

#endif // JOC_H
