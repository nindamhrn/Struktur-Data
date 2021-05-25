#include "otak.h"
#include "admin.h"
#include "juri.h"


void createList(ListJ &LJ, ListP &LP, ListR &LR, ListH &LH)
{
    First(LP) = NULL;
    First(LH) = NULL;
    First(LJ) = NULL;
    First(LR) = NULL;
    Last(LR) = NULL;
}

bool loginAdmin()
{
    string user = "Admin";
    string pass = "1234567";
    string username,password;

    do
    {
        system("CLS");
        cout<<"USERNAME : ";cin>>username;
        cout<<"PASSWORD : ";cin>>password;
    }while(username != user && password != pass);
    if (username == user && password == pass)
    {
        return true;
    }
}

void menuLogin(ListJ &J,ListP &P,ListR &R, ListH &H)
{

    int opsi;
    adrJ LoJ;
    string usr,psw,name;
    string jawab;
    bool kondisi;

    do
    {
        system("CLS");
        cout<<"=============== MENU LOGIN ===============\n";
        cout<<"==========================================\n";
        cout<<"     1. Login Admin"<<endl;
        cout<<"     2. Login Juri"<<endl;
        cout<<"     3. View Rank\n";
        cout<<endl;
        cout<<"     0. Exit\n";
        cout<<"==========================================\n";
        cout<<"Pilih : ";cin>>opsi;
        if (opsi ==1)
        {
            kondisi = loginAdmin();
            if (kondisi == true)
            {
                MenuAdmin(J,P,R,H);
            }
        }
        else if (opsi == 2)
        {
            LoJ = loginJuri(J);
            if (LoJ != NULL)
            {
                MenuJuri(LoJ,H,P,R);
            }
        }
        else if (opsi == 3)
        {
            viewDataP(P,R);
        }
    }while (opsi!=0);

}

void MenuAdmin(ListJ &J,ListP &P,ListR &R, ListH &H)
{
    int pilih;
    adrJ E;
    string usr,psw,name;
    string jawab;
  do
  {
    system("CLS");
    cout<<"========================[X]========================\n";
    cout<<"                    MENU ADMIN\n";
    cout<<"========================[X]========================\n";
    cout<<"     1. Input Juri\n";
    cout<<"     2. Input Peserta\n";
    cout<<"     3. Update Juri\n";
    cout<<"     4. Update Peserta\n";
    cout<<"     5. Delete Juri\n";
    cout<<"     6. Delete Peserta\n";
    cout<<"     7. History Juri\n";
    cout<<"     8. View Juri\n";
    cout<<"     9. View Peserta\n";
    cout<<endl;
    cout<<"     0. Exit\n";
    cout<<"========================[X]========================\n";

        cout<<"Pilih Opsi : ";cin>>pilih;

        switch(pilih)
        {
        case 1:
            do
            {
                do
                {
                    system("CLS");
                    cout<<"Input Nama     : "; cin>>name;
                    cout<<"Input Username : "; cin>>usr;
                    cout<<"Input Password : "; cin>>psw;
                    cekUser(J,usr);
                        if (cekUser(J,usr) ==  true)
                        {
                            cout<<"USERNAME SUDAH ADA ! \n";
                            cout<<"press ENTER . . ."<<endl;
                            getch();
                        }
                }while (cekUser(J,usr)==true);

                E = Alo(usr,psw,name);
                input(J,E);

                cout<<"Input Lagi (Y/N): "; cin>>jawab;
            }while (jawab == "Y"||jawab == "y");
            break;

        case 2 :
            do
            {
                cout << "Input Nama : ";cin>>name;
                inLastP(P,name);
                cout<<endl;
                cout<<"Input Lagi ? Y/N "; cin>>jawab;
            }while (jawab =="Y" || jawab == "y");
            break;

        case 3 :
            do
            {
                cout<<"Nama Juri yang akan diupdate : ";cin>>name;
                updateJ(J,name);
                cout<<endl;
                cout<<"Update Lagi ? Y/N "; cin>>jawab;
            }while(jawab =="Y" || jawab == "y");
            break;

        case 4 :
            do
            {
                updateP(R,P);
                cout<<endl;
                cout<<"Update Lagi ? Y/N "; cin>>jawab;
            }while(jawab =="Y" || jawab == "y");
            break;

        case 5 :
            do
            {
                cout<<"Nama Juri yang akan dihapus : ";cin>>name;
                deleteJ(J,R,name);
                cout<<endl;
                cout<<"Delete Lagi ? Y/N"; cin>>jawab;
            }while(jawab =="Y" || jawab == "y");
            break;

        case 6 :
            do
            {
                cout<<"Nama Peserta yang akan dihapus : ";cin>>name;
                deleteP(P,R,name);
                cout<<endl;
                cout<<"Delete Lagi ? Y/N"; cin>>jawab;
            }while(jawab =="Y" || jawab == "y");
            break;

        case 7 :

            TampilHistory(H);
            cout<<endl;
            cout<<"press Enter . . . ";
            getch();
            break;

        case 8 :
            viewDataJ(J);
            cout<<endl;
            cout<<"press Enter . . . ";
            getch();
            break;
        case 9 :
            viewDataP(P,R);
            cout<<endl;
            cout<<"press Enter . . . ";
            getch();
            break;
        }
   }while(pilih != 0);
   cout<<"press Enter\n";
   getch();
}

void MenuJuri(adrJ LJ, ListH H, ListP &P, ListR &R)
{
    int opsi;
    string jawab;

    do
    {
        system("CLS");
        cout<<"========================[X]========================\n";
        cout<<"                     MENU JURI \n";
        cout<<"========================[X]========================\n";
        cout<<"   1. Input Nilai Peserta \n";
        cout<<"   2. History\n";
        cout<<endl;
        cout<<"   0.Exit\n";
        cout<<"========================[X]========================\n";
        getch();
        cout<<"Pilih Opsi : ";cin>>opsi;
        switch (opsi)
        {
            case 1 :
                do
                {
                    menilai(R,LJ,P);
                    InputHistory(H,R);
                    cout<<"A";
                    getch();
                    cout<<"Selesai ? (Y/N)";cin>>jawab;
                }while (jawab == "N" || jawab == "n");
            break;

            case 2 :
                TampilHistory(H);
                getch();
            break;
        }
    }while (opsi<3 && opsi != 0);
    cout<<"press Enter . . .\n";
    getch();
}

void TampilHistory(ListH LH)
{
    adrH A;

    if (LH.First)
    {
        A = LH.First;
        do
        {
            cout<<"Nama Juri    : "<<A->Info.NamaJ<<endl;
            cout<<"Nama Peserta : "<<A->Info.NamaP<<endl;
            cout<<"Nilai        : "<<A->Info.Nilai<<endl;
            cout<<endl;
            A= A->Next;
        }while(A != NULL);
    }
}

void InputHistory(ListH &LH,ListR LR)
{
    adrH A = new dataH;
    adrR B;

    B=LR.First;
    do
    {
        A->Info.NamaJ = Info(Top(B)).namaJ;
        A->Info.NamaP = Info(Bottom(B)).namaP;
        A->Info.Nilai = B->Info.nilai;
        A->Next = NULL;
        if (LH.First == NULL)
        {
            LH.First = A;
        }
        else
        {
            A->Next = LH.First;
            LH.First = A;
        }
        B = B->Next;
    }while (B!= LR.Last);
}
