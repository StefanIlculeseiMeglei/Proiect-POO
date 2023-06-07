#include "afisare.h"

afisare::afisare()
{
}

afisare::~afisare()
{
}
void afisare::wait()
{
    cout << "\t\t....press any key to continue" << endl;
    getchar();
}
void afisare::afisareRezultat(int jucator,int status)
{
    if(status==1) /// a castigat cineva
    {

        if(jucator==1)
            cout << "Jucatorul a castigat!" << endl;
        else
            cout << "Computerul a castigat!" << endl;
    }
    else
        cout << "Egalitate!" << endl;
}
void afisare::print(matrice mat)
{
    system("clear");
cout << "\n\n\t X  si  0 \n\n";

cout << "Jucator (X)  -  Computer (O)" << endl << endl;
cout << endl;

cout << "     |     |     " << endl;
cout << "  " << mat(1) << "  |  " << mat(2) << "  |  " << mat(3) << endl;

cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;

cout << "  " << mat(4) << "  |  " << mat(5) << "  |  " << mat(6) << endl;

cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;

cout << "  " << mat(7) << "  |  " << mat(8) << "  |  " << mat(9) << endl;

cout << "     |     |     " << endl << endl;
}
