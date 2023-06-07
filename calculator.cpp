#include "calculator.h"
int calculator::alegereEazy(matrice mat)
{
    int pozitie;
    pozitie=rand()%9;
    while(pozitie<1 || mat.getValoare(pozitie)=='X' || mat.getValoare(pozitie)=='O')
        pozitie=rand()%9;
    return pozitie;
}
int calculator::alegereNormal(matrice mat)
{
    int pozitie;
    pozitie=aboutToLose(mat);
    if(pozitie>0) /// 0 inseamna ca jucatorul nu poate castiga urmatoarea tura
        return pozitie;

    pozitie=rand()%9;
    while(pozitie<1 || mat.getValoare(pozitie)=='X' || mat.getValoare(pozitie)=='O')
        pozitie=rand()%9;
    return pozitie;
}
int calculator::alegereHard(matrice mat)
{
    int nrMax=0;
    int vMax=0;
    int pozitie;
    genereazaMatVal(mat);
    for(int i=1;i<10;i++)
    {
        if(matValoare[i]>vMax)
        {
           vMax=matValoare[i];
           nrMax=1;
        }
        else
            if(matValoare[i]==vMax)
                nrMax++;
    }

    if(vMax<1000) /// castigul nu este garantat
    {
        pozitie=aboutToLose(mat);
        if(pozitie>0) /// 0 inseamna ca jucatorul nu poate castiga urmatoarea tura
            return pozitie;

    }
    /// acum alegem o pozitie dintre cele cu valoare maxima
    pozitie=rand()%nrMax+1;
    nrMax=0;
    for(int i=1;i<10;i++)
        if(matValoare[i]==vMax)
        {
            nrMax++;
            if(nrMax==pozitie)
                return i;
        }
    return 0;
}
int calculator::aboutToLose(matrice mat)
{
    int i;
    for(i=1;i<10;i++)
    {
        if(mat[i]=='0'+i)
        {

            switch(i)
            {
            case 1:
                if(  (mat[2]==simbolPlayer && mat[3]==simbolPlayer)
                   ||(mat[5]==simbolPlayer && mat[9]==simbolPlayer)
                   ||(mat[4]==simbolPlayer && mat[7]==simbolPlayer))
                    return i;

                break;
            case 2:

                if(  (mat[1]==simbolPlayer && mat[3]==simbolPlayer)
                   ||(mat[5]==simbolPlayer && mat[8]==simbolPlayer))
                    return i;
                break;
            case 3:

                if(  (mat[1]==simbolPlayer && mat[2]==simbolPlayer)
                   ||(mat[6]==simbolPlayer && mat[9]==simbolPlayer)
                   ||(mat[5]==simbolPlayer && mat[7]==simbolPlayer))
                    return i;
                break;
            case 4:
                if(  (mat[1]==simbolPlayer && mat[7]==simbolPlayer)
                   ||(mat[5]==simbolPlayer && mat[6]==simbolPlayer))
                    return i;
                break;
            case 5:
                if(  (mat[2]==simbolPlayer && mat[8]==simbolPlayer)
                   ||(mat[4]==simbolPlayer && mat[6]==simbolPlayer)
                   ||(mat[1]==simbolPlayer && mat[9]==simbolPlayer)
                   ||(mat[3]==simbolPlayer && mat[7]==simbolPlayer))
                    return i;
                break;
            case 6:
                if(  (mat[3]==simbolPlayer && mat[9]==simbolPlayer)
                   ||(mat[4]==simbolPlayer && mat[5]==simbolPlayer))
                    return i;
                break;
            case 7:

                if(  (mat[1]==simbolPlayer && mat[4]==simbolPlayer)
                   ||(mat[8]==simbolPlayer && mat[9]==simbolPlayer)
                   ||(mat[5]==simbolPlayer && mat[3]==simbolPlayer))
                    return i;

                break;
            case 8:
                if(  (mat[7]==simbolPlayer && mat[9]==simbolPlayer)
                   ||(mat[2]==simbolPlayer && mat[5]==simbolPlayer))
                    return i;
                break;
            case 9:

                if(  (mat[1]==simbolPlayer && mat[5]==simbolPlayer)
                   ||(mat[3]==simbolPlayer && mat[6]==simbolPlayer)
                   ||(mat[7]==simbolPlayer && mat[8]==simbolPlayer))
                    return i;
                break;
            }
        }
    }
    return 0;
}
void calculator::genereazaMatVal(matrice mat)
{
    int valSimbol=60;
    int valLiber=20;
    matValoare={0,0,0,0,0,0,0,0,0,0};
    for(int i=1;i<10;i++)
    {
        if(mat[i]!='0'+i)
            matValoare[i]=0;
        else
        {
            switch(i)
            {
            case 1:
                if(  (mat[2]==simbol && mat[3]==simbol)
                   ||(mat[5]==simbol && mat[9]==simbol)
                   ||(mat[4]==simbol && mat[7]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[2]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[2]=='2')
                            matValoare[i]+=valLiber;

                    if(mat[3]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[3]=='3')
                            matValoare[i]+=valLiber;

                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;


                    if(mat[9]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[9]=='9')
                            matValoare[i]+=valLiber;


                    if(mat[4]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[4]=='4')
                            matValoare[i]+=valLiber;


                    if(mat[7]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[7]=='7')
                            matValoare[i]+=valLiber;


                }
                break;
            case 2:

                if(  (mat[1]==simbol && mat[3]==simbol)
                   ||(mat[5]==simbol && mat[8]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[1]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[1]=='1')
                            matValoare[i]+=valLiber;

                    if(mat[3]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[3]=='3')
                            matValoare[i]+=valLiber;

                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;


                    if(mat[8]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[8]=='8')
                            matValoare[i]+=valLiber;
                }


                break;
            case 3:

                if(  (mat[1]==simbol && mat[2]==simbol)
                   ||(mat[6]==simbol && mat[9]==simbol)
                   ||(mat[5]==simbol && mat[7]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[1]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[1]=='1')
                            matValoare[i]+=valLiber;

                    if(mat[2]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[2]=='2')
                            matValoare[i]+=valLiber;

                    if(mat[6]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[6]=='6')
                            matValoare[i]+=valLiber;


                    if(mat[9]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[9]=='9')
                            matValoare[i]+=valLiber;


                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;


                    if(mat[7]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[7]=='7')
                            matValoare[i]+=valLiber;
                }


                break;
            case 4:
                if(  (mat[1]==simbol && mat[7]==simbol)
                   ||(mat[5]==simbol && mat[6]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[1]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[1]=='1')
                            matValoare[i]+=valLiber;

                    if(mat[7]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[7]=='7')
                            matValoare[i]+=valLiber;

                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;


                    if(mat[6]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[6]=='6')
                            matValoare[i]+=valLiber;
                }
                break;
            case 5:
                if(  (mat[2]==simbol && mat[8]==simbol)
                   ||(mat[4]==simbol && mat[6]==simbol)
                   ||(mat[1]==simbol && mat[9]==simbol)
                   ||(mat[3]==simbol && mat[7]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[1]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[1]=='1')
                            matValoare[i]+=valLiber;

                    if(mat[2]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[2]=='2')
                            matValoare[i]+=valLiber;

                    if(mat[3]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[3]=='3')
                            matValoare[i]+=valLiber;

                    if(mat[4]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[4]=='4')
                            matValoare[i]+=valLiber;

                    if(mat[6]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[6]=='6')
                            matValoare[i]+=valLiber;

                    if(mat[7]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[7]=='7')
                            matValoare[i]+=valLiber;

                    if(mat[8]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[8]=='8')
                            matValoare[i]+=valLiber;

                    if(mat[9]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[9]=='9')
                            matValoare[i]+=valLiber;
                }
                break;
            case 6:
                if(  (mat[3]==simbol && mat[9]==simbol)
                   ||(mat[4]==simbol && mat[5]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[3]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[3]=='3')
                            matValoare[i]+=valLiber;

                    if(mat[9]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[9]=='9')
                            matValoare[i]+=valLiber;

                    if(mat[4]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[4]=='4')
                            matValoare[i]+=valLiber;


                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;
                }
                break;
            case 7:

                if(  (mat[1]==simbol && mat[4]==simbol)
                   ||(mat[8]==simbol && mat[9]==simbol)
                   ||(mat[5]==simbol && mat[3]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[1]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[1]=='1')
                            matValoare[i]+=valLiber;

                    if(mat[4]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[4]=='4')
                            matValoare[i]+=valLiber;

                    if(mat[8]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[8]=='8')
                            matValoare[i]+=valLiber;


                    if(mat[9]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[9]=='9')
                            matValoare[i]+=valLiber;


                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;


                    if(mat[3]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[3]=='3')
                            matValoare[i]+=valLiber;
                }

                break;
            case 8:
                if(  (mat[7]==simbol && mat[9]==simbol)
                   ||(mat[2]==simbol && mat[5]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[7]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[7]=='7')
                            matValoare[i]+=valLiber;

                    if(mat[9]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[9]=='9')
                            matValoare[i]+=valLiber;

                    if(mat[2]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[2]=='2')
                            matValoare[i]+=valLiber;


                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;
                }
                break;
            case 9:

                if(  (mat[1]==simbol && mat[5]==simbol)
                   ||(mat[3]==simbol && mat[6]==simbol)
                   ||(mat[7]==simbol && mat[8]==simbol))
                    matValoare[i]=1000; /// castiga daca alege pozitia
                else
                {
                    if(mat[1]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[1]=='1')
                            matValoare[i]+=valLiber;

                    if(mat[5]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[5]=='5')
                            matValoare[i]+=valLiber;

                    if(mat[3]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[3]=='3')
                            matValoare[i]+=valLiber;


                    if(mat[6]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[6]=='6')
                            matValoare[i]+=valLiber;


                    if(mat[7]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[7]=='7')
                            matValoare[i]+=valLiber;


                    if(mat[8]==simbol)
                        matValoare[i]+=valSimbol;
                    else
                        if(mat[8]=='8')
                            matValoare[i]+=valLiber;
                }

                break;
            }


        }

    }
}

calculator::calculator()
{
    matValoare={0,0,0,0,0,0,0,0,0,0};
}
