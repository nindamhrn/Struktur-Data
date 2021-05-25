#include "juri.h"
#include "otak.h"

adrJ loginJuri(ListJ LJ)
{
    adrJ A;
    string user,pass;
    bool kondisi;

    if (LJ.First != NULL)
    {
        A = LJ.First;
        do
        {
            cout<<"Username : "; cin>>user;
            cout<<"Password : "; cin>>pass;

            while ((A->Next!= NULL) && (A->Info.user != user) && (A->Info.pass != pass))
            {
                A = A->Next;
            }

            if ((A->Info.user == user)&&(A->Info.pass == pass))
            {
                kondisi = true;
            }
            else
            {
                kondisi = false;
            }
        }while (kondisi != true);

        return A;
    }
}

adrR searchNilai(ListR LR,int nilai)
{
    adrR R;

    if (LR.First != NULL)
    {
        R = LR.First;
        while ((R != NULL) && (R->Info.nilai != nilai))
        {
            R = R->Next;
        }
        if (R->Info.nilai == nilai)
        {
            return R;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
void menilai(ListR &LR, adrJ J, ListP &LP){

    int nilai;
    string namap;
    adrP P;
    adrR Q;
    adrR R = new dataR;


    cout<<"Peserta yang akan dinilai : "; cin >> namap;
    P = searchP(LP,namap);
    cout<<"Input Nilai Peserta : "; cin>>nilai;


    R->Info.nilai = nilai;
    R->Bottom = P;
    R->Top = J;
    if(First(LR)!= NULL)
    {
        Q = LR.First;
        while((Q != LR.First) && (Q->Top != J) && (Q->Bottom != P))
        {
            Q = Q->Next;
        }
        if ((Q->Top == J) && (Q->Bottom == P))
        {
            cout<<"SUDAH PERNAH DINILAI\n";
        }
        else
        {
            R->Next = LR.First;
            R->Prev = LR.Last;
            LR.First->Prev = R;
            LR.Last->Next = R;
        }
    }

    if(LR.First == NULL)
    {
        R->Next = R;
        R->Prev = R;
    }

    LR.First = R;
    LR.Last = R->Prev;

}
