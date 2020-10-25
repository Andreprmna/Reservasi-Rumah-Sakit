#include "DokterAndPasien.h"
#include<iostream>
#include<dos.h>
#include<cstdio>

#include<conio.h>
using namespace std;

int main(){

//        clrscr();
        int pil;

        cout<<"=======  Menu Utama \n";
        cout<<"======= 1. Input Pasien \n";
        cout<<"======= 2. Input DOKTER \n";
        cout<<"======= 3. Delete Pasien \n";
        cout<<"======= 4. Output Semua Dokter Serta Pasiennya \n";
        cout<<"======= 5. Output Dokter Melayani Pasien Tertentu \n";
        cout<<"======= 6. Output Dokter Banyak Pasien \n";
        cout<<"======= 7. Output yang memiliki 2/lebih dokter \n";
        cout<<"=====================================================\n";
        cout<<" Masukkan Pilihan Anda : ";cin>>pil;

        switch (pil){

    case 1:
        clrscr();
            //
        getch();
        goto mulai;

    case 2:
        clrscr();
            //
        getch();
        goto mulai;

    case 3:
        clrscr();
            //
        getch();
        goto mulai;
    case 4:
        clrscr();
            //
        getch();
        goto mulai;

    case 5:
        clrscr();
        gecth();
        goto mulai;

    case 6:
        clrscr();
        gecth();
        goto mulai;

    case 7:
        clrscr();
        //
        gect();
        goto mulai;
    listDokter L1;
    listPasien L2;
    createListDokter(L1);
    createListPasien(L2);
    addressDokter P = createDokter(1,"A","X");
    addDokter(L1,P);
    addressPasien Q = createPasien(1,"Z","wafat");
    addPasien(L2,Q);
    Q = createPasien(2,"Y","wafat");
    addPasien(L2,Q);
    P = createDokter(2,"B","XX");
    addDokter(L1,P);
    relationshipDokterPasien(L1,L2,"A","Z");
    relationshipDokterPasien(L1,L2,"A","Y");
    relationshipDokterPasien(L1,L2,"B","Y");
    printAllDokter(L1);
    cout<<"DOKTER Paling Banyak Pasiennya"<<endl;
    showGoodDokter(L1);
    cout<<"-------------------------------------"<<endl;
    system("pause");
    showIllPasien(L2);
    system("pause");
    printPasien(L1,"Y");
}
}
