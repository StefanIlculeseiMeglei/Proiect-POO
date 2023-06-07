#ifndef MATRICE_H
#define MATRICE_H
#include <termios.h>
#include <iostream>
#include <string.h>
#include <array>
#include <fstream>
using namespace std;
/// serializare se face la nivelul clasei matrice, modificand constructorul si destructorul
class matrice
{
    static array<char,10> mat;
    string numeFisier = "save.txt";
    // mat[0] determina daca s-a citit din fisier sau nu
    public:
        matrice();
        virtual ~matrice();
        char & operator[](int);
        char operator()(int);
        char getValoare(int);
        void setValoareFix(int,char);
        int setValoare(int,char);
        int isFull(); /// matricea este plina
        int getSerializare();
        void reset();
};

#endif // MATRICE_H
