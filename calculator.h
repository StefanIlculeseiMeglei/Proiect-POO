#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <termios.h>
#include <iostream>
#include "matrice.h"
class calculator
{
    private:
        const char simbol ='O';
        const char simbolPlayer= 'X';
        array<int,10> matValoare;
        void genereazaMatVal(matrice mat);
        int aboutToLose(matrice mat);
    public:
        calculator();
        int alegereEazy(matrice mat);
        int alegereNormal(matrice mat);
        int alegereHard(matrice mat);
};
#endif // CALCULATOR_H
