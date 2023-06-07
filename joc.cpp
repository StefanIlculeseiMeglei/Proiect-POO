#include "joc.h"

joc::joc()
{
    ifstream f;
    f.open(numeFisierPuncte);
    if(f)
        f >> puncte;
    else
        puncte = 0;
    DIFICULTATE=1; /// normal
}
joc::~joc()
{
    ofstream g("puncte.txt");
    g << puncte;
    //dtor
}
int joc::getPuncte()
{
    return puncte;
}
void joc::reseteazaPuncte()
{
    puncte=0;
}
int joc::verificaCastig(matrice mat)
{
    if (mat(1) == mat(2) && mat(2) == mat(3))

return 1;
else if (mat(4) == mat(5) && mat(5) == mat(6))

return 1;
else if (mat(7) == mat(8) && mat(8) == mat(9))

return 1;
else if (mat(1) == mat(4) && mat(4) == mat(7))

return 1;
else if (mat(2) == mat(5) && mat(5) == mat(8))

return 1;
else if (mat(3) == mat(6) && mat(6) == mat(9))

return 1;
else if (mat(1) == mat(5) && mat(5) == mat(9))

return 1;
else if (mat(3) == mat(5) && mat(5) == mat(7))

return 1;
else if (mat(1) != '1' && mat(2) != '2' && mat(3) != '3'
&& mat(4) != '4' && mat(5) != '5' && mat(6) != '6'
&& mat(7) != '7' && mat(8) != '8' && mat(9) != '9')
return 0;
else
return -1;
}
void joc::updatePuncte(int jucator,int status)
{
    if(status==1) /// a castigat cineva
    {
        if(jucator==OM)
            puncte+=VALOAREA_CASTIG*(DIFICULTATE+1);
        else
            puncte-=VALOAREA_CASTIG*(3-DIFICULTATE);
    }

}
void joc::setDificultate(string x)
{
    /// 0-usor, 1- normal, 2-dificil
    if(x.compare("usor")==0)
        DIFICULTATE=0;
    else
        if(x.compare("normal")==0)
            DIFICULTATE=1;
        else
            if(x.compare("dificil")==0)
                DIFICULTATE=2;
}
void joc::start(matrice mat)
{
    int jucator;
    int pozitie;
    int validare;
    char simbol;
    jucator = OM;
    int i;
    if(mat.isFull())
    	mat.reset();
    do
    {
        if(jucator==OM)
        {
            validare=1;
            simbol='X';
            do{
                A.print(mat);
                if(validare==0)
                    cout << "Pozitie incorecta" << endl;
                cout << "Introdu pozitia:";
                scanf("%d",&pozitie);
                validare=mat.setValoare(pozitie,simbol);
            }while(validare!=1);
            mat.setValoare(pozitie,simbol);
            jucator=CALCULATOR;
        }
        else
        {
            simbol='O';
            if(DIFICULTATE==0)
                pozitie=calc.alegereEazy(mat);
            else
                if(DIFICULTATE==1)
                    pozitie=calc.alegereNormal(mat);
            else
                    pozitie=calc.alegereHard(mat);
            mat.setValoareFix(pozitie,simbol);
            jucator=OM;
        }
        A.print(mat);
        i=verificaCastig(mat);
    }while(i==-1);
    /// dupa punerea ultimului simbol jucatorul a fost schimbat inca o data, deci valoarea
    /// variabilei jucator trebuie schimbata
    if(jucator==OM)
        jucator=CALCULATOR;
    else
        jucator=OM;


    A.print(mat);
    A.afisareRezultat(jucator,i); /// jucatorul si statusul jocului:castig/egalitate
    updatePuncte(jucator,i);
    getchar();

}
