#include"DokterAndPasien.h"
void createListDokter(listDokter &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createListPasien(listPasien &L){
    first(L) = NULL;
    last(L) = NULL;
}
addressDokter createDokter(int id,string name,string special){
    addressDokter P = new Dokter;
    info(P).name = name;
    info(P).id = id;
    info(P).special = special;
    info(P).sumPasien = 0;
    createListPasien(info(P).namePasien);
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
addressPasien createPasien(int id,string name,string status){
    addressPasien P = new Pasien;
    info(P).name = name;
    info(P).id = id;
    info(P).sumDokter = 0;
    info(P).status = status;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void addDokter(listDokter &L,addressDokter P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void addPasien(listPasien &L,addressPasien P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
addressPasien searchPasien(listPasien L,string name){
    addressPasien P = first(L);
    while(P != NULL && info(P).name != name)
        P = next(P);
    return P;
}
addressDokter searchDokter(listDokter L,string name){
    addressDokter P = first(L);
    while(P != NULL && info(P).name != name)
        P = next(P);
    return P;
}
void relationshipDokterPasien(listDokter &L1,listPasien &L2,string nameDokter,string namePasien){
    addressDokter P = searchDokter(L1,nameDokter);
    addressPasien Q = searchPasien(L2,namePasien);
    if(P != NULL && Q != NULL){
        addressPasien R = createPasien(info(Q).id,info(Q).name,info(Q).status);
        addPasien(info(P).namePasien,R);
        info(P).sumPasien++;
        info(Q).sumDokter++;
    }
}
void deleteRelationship(listDokter &L1, listPasien &L2, string namePasien){
    addressPasien P = searchPasien(L2,namePasien);
    if(P != NULL){
        addressDokter D = first(L1);
        while(D != NULL){
            addressPasien tmp = searchPasien(info(D).namePasien,namePasien);
            if(tmp != NULL){
                info(D).sumPasien--;
                deleteAddressPasien(info(D).namePasien,tmp);
            }
            D = next(D);
        }
    }
    deleteAddressPasien(L2,P);
    delete P;
}
void deleteAddressPasien(listPasien &L,addressPasien &P){
    if(P != NULL){
        if(P == first(L)){
            first(L) = next(P);
            prev(first(L)) = NULL;
        }else if(P == last(L)){
            last(L) = prev(P);
            next(last(L)) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
        }
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deletePasien(listPasien &L,string namePasien){
    addressPasien P = searchPasien(L,namePasien);
    deleteAddressPasien(L,P);
    delete P;
}
void deleteDokter(listDokter &L1,listPasien &L2,string nameDokter){
    addressDokter P = searchDokter(L1,nameDokter);
    if(P != NULL){
        while(info(P).sumPasien != 0){
            addressPasien Q = first(info(P).namePasien);
            Q = searchPasien(L2,info(Q).name);
            info(Q).sumDokter--;
            deletePasien(info(P).namePasien,info(Q).name);
            info(P).sumPasien--;
        }
        if(P == first(L1)){
            first(L1) = next(P);
            prev(first(L1)) = NULL;
        }else if(P == last(L1)){
            last(L1) = prev(P);
            next(last(L1)) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
        }
        next(P) = NULL;
        prev(P) = NULL;
    }
    delete P;
}
void printAllDokter(listDokter L){
    addressDokter P = first(L);
    while(P != NULL){
        printDokter(P);
        P = next(P);
    }
}
void printDokter(addressDokter P){
    int i = 1;
    cout<<"Id Dokter    : "<<info(P).id<<endl;
    cout<<"Nama Dokter  : "<<info(P).name<<endl;
    cout<<"Specialized  : "<<info(P).special<<endl;
    addressPasien Q = first(info(P).namePasien);
    cout<<"Daftar Pasien : "<<endl;
    while(Q != NULL){
        cout<<"\t\t"<<i<<".  "<<info(Q).name<<endl;
        Q = next(Q);
        i++;
    }
    cout<<"--------------------"<<endl;
}
void printPasien(listDokter L,string Pasien){
    cout<<"Nama Pasien \t: "<<Pasien<<endl;
    cout<<"List Dokternya \t: "<<endl;
    addressDokter D = first(L);
    int i = 1;
    while(D != NULL){
        if(searchPasien(info(D).namePasien,Pasien) != NULL){
            cout<<"\t\t  "<<i++<<".  "<<info(D).name<<endl;
        }
        D = next(D);
    }
}
void showGoodDokter(listDokter L){
    int maks = 0;
    addressDokter P;
    addressDokter Q = first(L);
    while(Q !=  NULL){
        if(info(Q).sumPasien > maks){
            maks = info(Q).sumPasien;
            P =Q;
        }
        Q = next(Q);
    }
    printDokter(P);
}
void showIllPasien(listPasien L){
    addressPasien P = first(L);
    while(P != NULL){
        if(info(P).sumDokter > 1)
            cout<<"Nama : "<<info(P).name<<"      Jumlah Dokter : "<<info(P).sumDokter<<endl;
        P = next(P);
    }
}
