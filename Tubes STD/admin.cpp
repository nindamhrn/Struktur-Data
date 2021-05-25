#include "otak.h"
#include "admin.h"

/// PUNYA PESERTA
void inLastP(ListP &LP, string NamaP)
{
    adrP x = new dataP;
    adrP q;
    Info(x).namaP = NamaP;
    if (First(LP) == NULL)
    {
        First(LP) = x;
        Info(x).nomorP = 1;
        x->Next = NULL;
    }
    else
    {
        q = LP.First;
        while (Next(q)!=NULL)
        {
            q = q->Next;
        }
        q->Next = x;
        Info(x).nomorP = Info(q).nomorP + 1;
        x->Next = NULL;
    }
}
void viewDataP(ListP LP,ListR LR)
{
    adrP x;
    adrR y;
    x = LP.First;
    adrR Max;

   /* if (LR.First != NULL)
    {
        sorting(LP);
    }*/

    if (x != NULL)
    {
        while (x!=NULL)
        {
            cout<<Info(x).nomorP<<"."<<"Nama Peserta  : "<<Info(x).namaP<<endl;
            y = LR.First;
            if (y!= NULL)
            {
                do
                {
                    if (Bottom(y)== x)
                    {
                        cout<<"Nilai Peserta : "<<y->Info.nilai<<endl;
                        cout<<"Juri Penilai  : "<<Info(Top(y)).namaJ<<endl;
                    }
                y = y->Next;
                }while (y != LR.Last);

            }
            cout<<"TOTAL NILAI : "<<Total(LR,x);
            x = x->Next;
        }
    }
    getch();

}
adrP searchP(ListP LP,string Nama)
{
    adrP x;
    if (First(LP) != NULL)
    {
        x = First(LP);
        while ((x!=NULL) && (Info(x).namaP != Nama))
        {
            x = x->Next;
        }
        if (Info(x).namaP == Nama)
        {
            return x;
        }
        else
        {
            return NULL;
        }
    }
}
void deleteP(ListP &LP,ListR &LR,string Nama)
{
    adrP S,E,F;
    adrR A,N;

    F = searchP(LP,Nama);
    A = LR.First;
    if (A != NULL)
    {

        bool c = false;

        do
        {
            c = false;

            if (A->Bottom == F)
            {


                if (LR.First == LR.Last)
                {
                    A->Bottom = NULL;
                    A->Top = NULL;
                    LR.First = NULL;
                    LR.Last = NULL;
                    delete A;
                    A = NULL;
                }
                else
                {
                    A->Bottom = NULL;
                    A->Top = NULL;

                    N = A->Prev;
                    N->Next = A->Next;
                    Prev(A->Next) = N;

                    if(A == LR.First){
                        LR.First = A->Next;
                    }
                    if(A==LR.Last){
                        LR.Last = A->Prev;
                    }

                    A->Next = NULL;
                    A->Prev = NULL;

                    delete A;
                    A = LR.First;
                    c = true;
                }

            }else{

                A = A->Next;
            }

        }while ( (LR.First != NULL && A != LR.First) || c);
    }


    if (LP.First != NULL)
    {


        if (Info(First(LP)).namaP == Nama)
        {
            S = First(LP);
            First(LP) = S->Next;
            S->Next = NULL;

            delete S;
            E = First(LP);
        }
        else
        {
            S = First(LP);
            while ((Next(S)!=NULL) && (Info(S).namaP != Nama))
            {
                E = S;
                S = Next(S);

            }
            if (Info(S).namaP == Nama)
            {

                if (S->Next == NULL)
                {

                    E->Next = NULL;
                    delete S;
                }
                else
                {

                    E->Next = S->Next;
                    S->Next = NULL;
                    delete S;
                }
                E = E -> Next;
            }



        }
        if(E != NULL){

            do
            {

                Info(E).nomorP = Info(E).nomorP - 1;
                E = E->Next;

            }while (E != NULL);
        }



    }
}

void updateP(ListR &LR,ListP &LP)
{
    adrP B;
    adrR A = LR.First;
    int newscore;
    string nama,jawab;

    do
    {
        cout<<"Nama peserta yang akan di update : ";cin>>nama;
        B = searchP(LP,nama);
        if (B!=NULL)
        {
            do
            {
                A=A->Next;
            } while(A!=LR.Last && A->Bottom != B);

            if (A->Bottom ==  B)
            {
                cout<<"Input Nilai Yang Baru : ";cin>>newscore;
                A->Info.nilai = newscore;
            }
        }
        cout<<"Edit Lagi ? Y/N ";cin>>jawab;
    }while (jawab == "Y" || jawab =="y");

}


///  PUNYA JURI  ///

adrJ Alo(string uname,string pasw,string Nama)
{
    adrJ X = new dataJ;

    Info(X).user = uname;
    Info(X).pass = pasw;
    Info(X).namaJ = Nama;
    X->Next = NULL;
    return X;
}

void input(ListJ &LJ, adrJ X)
{
    adrJ Y,Z;
    if (First(LJ) == NULL)
    {
        First(LJ) = X;
    }
    else
    {
        Y = First(LJ);
        while ((Y->Next != NULL) && (X->Info.namaJ > Y->Info.namaJ))
        {
            Z = Y;
            Y = Y->Next;
        }
        if (X->Info.namaJ <= Y->Info.namaJ)
        {
            if ( Y == First(LJ))
            {
                X->Next = First(LJ);
                First(LJ) = X;
            }
            else
            {
                X->Next = Y;
                Z->Next = X;
            }
        }
        else
        {
            Y->Next = X;
            X->Next = NULL;
        }
    }
}

bool cekUser(ListJ LJ,string uname)
{
    adrJ X;

    if (LJ.First != NULL)
    {
        X = LJ.First;
        while ((X->Next != NULL) && (Info(X).user != uname))
        {
            X = X->Next;
        }
        if (Info(X).user == uname)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void viewDataJ(ListJ LJ)
{
    adrJ x;
    x = LJ.First;
    if (x == NULL)
    {
        cout<<"KOSONG\n";
    }
    else
    {
        while (x!=NULL)
        {

            cout<<"Nama Juri : "<<x->Info.namaJ<<endl;
            cout<<"Username  : "<<x->Info.user<<endl;
            cout<<"Password  : "<<x->Info.pass<<endl;
            cout<<endl;
            x = x->Next;
        }
    }

}

void deleteJ(ListJ &LJ,ListR &LR,string Nama)
{
    adrJ S,E,F;
    adrR A,N;

    F = searchJ(LJ,Nama);
    A = LR.First;

    if (A != NULL)
    {

        bool c = false;

        do
        {
            c = false;

            if (A->Top == F)
            {


                if (LR.First == LR.Last)
                {
                    A->Bottom = NULL;
                    A->Top = NULL;
                    LR.First = NULL;
                    LR.Last = NULL;
                    delete A;
                    A = NULL;
                }
                else
                {
                    A->Bottom = NULL;
                    A->Top = NULL;

                    N = A->Prev;
                    N->Next = A->Next;
                    Prev(A->Next) = N;

                    if(A == LR.First)
                    {
                        LR.First = A->Next;
                    }
                    if(A==LR.Last)
                    {
                        LR.Last = A->Prev;
                    }

                    A->Next = NULL;
                    A->Prev = NULL;

                    delete A;
                    A = LR.First;
                    c = true;
                }

            }
            else
            {
                A = A->Next;
            }

        }while ( (LR.First != NULL && A != LR.First) || c);
    }

    if (First(LJ) != NULL)
    {
        if (Info(First(LJ)).namaJ == Nama)
        {
            S = First(LJ);
            First(LJ) = S->Next;
            S->Next = NULL;
            delete S;
        }
        else
        {
            S = First(LJ);
            while ((Next(S)!=NULL) && (Info(S).namaJ != Nama))
            {
                E = S;
                S = Next(S);
            }
            if (Info(S).namaJ == Nama)
            {
                if (S->Next == NULL)
                {
                    E->Next = NULL;
                    delete E;
                }
                else
                {
                    E->Next = S->Next;
                    S->Next = NULL;
                    delete S;
                }
            }
        }
    }
}

adrJ searchJ(ListJ LJ,string Nama)
{
    adrJ A;

    if (LJ.First != NULL)
    {
        A = LJ.First;
        while ((A->Next != NULL) && (A->Info.namaJ != Nama))
        {
            A = A->Next;
        }
        if (A->Info.namaJ == Nama)
        {
            return A;
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

void updateJ(ListJ &LJ,string Nama)
{
    adrJ A;
    string usr,name,pass;

    A = searchJ(LJ,Nama);
    if (A != NULL)
    {
        cout<<" Input User : "; cin>>usr;
        cout<<" Input Nama : "; cin>>name;
        cout<<" Input Password : "; cin>>pass;
        A->Info.namaJ = name;
        A->Info.user = usr;
        A->Info.pass = pass;
    }
}

int Total(ListR LR, adrP &A)
{
    adrR B;

    B= LR.First;

        do
        {
            if (Info(Bottom(B)).namaP == A->Info.namaP)
            {
                A->Info.total = A->Info.total + B->Info.nilai;
            }
            B= B->Next;
        }while(B!=LR.Last);
    return A->Info.total;
}

void sorting(ListP &LP)
{
    adrP Max,Temp,A,B;

    A = LP.First;
    do
    {
        B = LP.First->Next;
        do
        {
            if (A->Info.total<=B->Info.total)
            {
                Temp = A;
                A = B;
                B = A;
            }
            B = B->Next;
        }while (B->Next != NULL);
        A = A->Next;
    }while(A->Next!= NULL);
}
