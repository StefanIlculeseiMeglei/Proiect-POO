#ifndef AFISARE_H
#define AFISARE_H
#include <termios.h>
#include <iostream>
#include "matrice.h"

class afisare
{
    public:
        afisare();
        virtual ~afisare();
        void wait();
        void print(matrice);
        void afisareRezultat(int jucator,int status);
};

#endif // AFISARE_H
