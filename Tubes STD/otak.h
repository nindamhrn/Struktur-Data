#ifndef OTAK_H_INCLUDED
#define OTAK_H_INCLUDED
#define Info(A) A->Info
#define Next(A) A->Next
#define Prev(A) A->Prev
#define Bottom(A) A->Bottom
#define Top(A) A->Top
#define First(A) A.First
#define Last(A) A.Last

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

typedef struct dataJ *adrJ;
typedef struct dataP *adrP;
typedef struct dataR *adrR;
typedef struct dataH *adrH;

///Pendfinisian
struct Juri
{
    string user;
    string pass;
    string namaJ;
};

struct Peserta
{
    string namaP;
    int nomorP;
    int total = 0;
};

struct Relasi
{
    int nilai;
};

struct History
{
    string NamaJ,NamaP;
    int Nilai;
};

///Juri
struct dataJ
{
    Juri Info;
    adrJ Next;
};
struct ListJ
{
    adrJ First;
};

///Relasi
struct dataR
{
    adrJ Top;
    adrP Bottom;
    adrR Next;
    adrR Prev;
    Relasi Info;
};
struct ListR
{
    adrR Last;
    adrR First;
};

///Peserta
struct dataP
{
    adrP Next;
    Peserta Info;
};
struct ListP
{
    adrP First;
};

///History
struct dataH
{
    adrH Next;
    History Info;
};
struct ListH
{
    adrH First;
};

void createList(ListJ &LJ,ListP &LP,ListR &LR,ListH &LH);
void menu(ListJ &J,ListP &P,ListR &R,ListH &H);
void InputHistory(ListH &LH,ListR LR);
void TampilHistory(ListH LH);
bool loginAdmin();
void MenuAdmin(ListJ &J,ListP &P,ListR &R, ListH &H);
void MenuJuri(adrJ LJ, ListH H, ListP &P, ListR &R);
void menuLogin(ListJ &J,ListP &P,ListR &R, ListH &H);


#endif // OTAK_H_INCLUDED
