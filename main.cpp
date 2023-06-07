#include <termios.h>
#include "matrice.h"
#include "afisare.h"
#include "joc.h"
using namespace std;
int meniu()
{
    int op;
    system("clear"); /// clear pt linux CLS pt windows
    cout << "Jocul X si Zero" << endl;
    cout << "1) Info" << endl;
    cout << "2) Start joc" << endl;
    cout << "3) Schimba dificultatea" << endl;
    cout << "4) Arata punctajul" << endl;
    cout << "5) Reseteaza scor" << endl;
    cout << "6) Iesire aplicatie" << endl;
    cout << "Alegeti o optine:";
    cin >> op;
    getchar();
    return op;
}
int main()
{
    const string numeFisierInfo = "info.txt";
    ifstream f;
    string s;
    matrice mat;
    afisare B;
    joc Game;
    int op;
    do
    {
        op=meniu();
        switch(op)
        {
        case 1:
            system("clear");
            f.open(numeFisierInfo);
            while(getline(f,s))
                cout << s << endl;
            f.close();
            B.wait();
            break;
        case 2:
            Game.start(mat);
            mat.reset();
            getchar();
            break;
        case 3:
            cout << "Dificultati: 1-Usor, 2-Normal, 3-Dificil" << endl;
            cout << "Alegeti una:";
            cin >> op;
            getchar();
            if(op==1)
                Game.setDificultate("usor");
            else
                if(op==2)
                    Game.setDificultate("normal");
            else
                if(op==3)
                   Game.setDificultate("dificil");
            else
                cout << "Optiune gresita!" << endl;
            B.wait();
            break;
        case 4:
            cout << "Punctajul este " << Game.getPuncte() << " puncte." << endl;
            B.wait();
            break;
        case 5:
            cout << "Punctajul a fost resetat." << endl;
            Game.reseteazaPuncte();
            B.wait();
            break;
        case 6:
            return 0;
        default:
            cout << "Optiune gresita!" << endl;
            B.wait();
            break;
        }
    }while(1);
    return 0;
}
