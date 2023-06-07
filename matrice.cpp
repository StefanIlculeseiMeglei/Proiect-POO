#include "matrice.h"
array<char,10> matrice::mat={'0','1','2','3','4','5','6','7','8','9'};
matrice::matrice()
{
    reset();
    ifstream f; /// fisirul text cu matricea
    f.open(numeFisier);
    if(f) /// daca am putut deschide fisierul atunci preluam matricea din fisier
    {
        string s;
        for(int i=0;i<3;i++)
        {
            getline(f,s);
            mat[3*i+1]=s[0];
            mat[3*i+2]=s[1];
            mat[3*i+3]=s[2];
        }
    }
    f.close();
}

matrice::~matrice()
{




    ofstream g(numeFisier);
    for(int i=0;i<=2;i++)
        g << mat[3*i+1] << mat[3*i+2] << mat[3*i+3] << endl;
    g.close();
}
int matrice::isFull()
{
    string s="123456789"; /// caractere care semnalizeaza ca board-ul nu este plin
    for(int i=1;i<=9;i++) /// trece prin matrice
        for(int j=0;j<9;j++)
            if(s[j]==mat[i])
                return 0;
    return 1;
}
void matrice::reset()
{
    char c='1';
    mat[0]='o';
    for(int i=1;i<10;i++)
        mat[i]=c++;
}
char matrice::getValoare(int _pozitie)
{
    return mat[_pozitie];
}

char & matrice::operator[](int i)
{
    return mat[i];
}
char matrice::operator()(int i)
{
    return mat[i];
}
void matrice::setValoareFix(int pozitie,char simbol)
{
    mat[pozitie]=simbol;
}
int matrice::setValoare(int pozitie,char simbol)
{
    int validarePozitie=0;
    for(int i=1;i<=9;i++) /// pozitia aleasa este pe board
        if(pozitie==i && mat[i]==('0'+i)) /// pozitia nu a fost deja folosita
        {
            mat[i]=simbol;
            validarePozitie=1;
            break;
        }
    return validarePozitie;
}
