#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "header.h"

using namespace std;

int jumlahKamar=999;
int *dataKamar;
int**dataJarak;
bool cekMatrik=false;
int posisiIndeks,jarakSekarang,jarakLama,jarakBaru;
int kamarAsal, kamarSekarang, kamarTujuan;
int sudahDikunjungi=1;
int belumDikunjungi=0;
int*jarakDiketahui;
int*kunjungan;
int baris;

void buatMatriks() {
    dataKamar=new int [jumlahKamar];
    dataJarak=new int*[jumlahKamar];
    dataJarak[0]=new int[jumlahKamar*jumlahKamar];
    for(int i=1; i<jumlahKamar; i++) {
        dataJarak[i]=dataJarak[i-1]+jumlahKamar;
    }
    cout<<"\n[NOMOR KAMAR]"<<endl;
    for(int i=0; i<jumlahKamar; i++) {
        cout<<"Kamar ke-"<<i+1<<": ";
        cin>>dataKamar[i];
    }

    cout<<"\n[JARAK ANTAR KAMAR]"<<endl;
    for(int baris=0; baris<jumlahKamar; baris++) {
        for(int kolom=0; kolom<jumlahKamar; kolom++) {
            cout<<dataKamar[baris]<<" --> "<<dataKamar[kolom]<<": ";
            cin>>dataJarak[baris][kolom];
        }
        cekMatrik=true;
    }
}

int cariKamar(int k) {
    int i = 0;

    while (i < jumlahKamar) {
        if (dataKamar[i] == k) {
            break;
        }
        i++;
    }

    return i;
}

void hitungJarakTerdekat() {
    if(cekMatrik) {
        jarakDiketahui=new int[jumlahKamar];
        kunjungan=new int[jumlahKamar];
        for(int i=0; i<jumlahKamar; i++) {
            jarakDiketahui[i]=999;
            kunjungan[i]=belumDikunjungi;
        }
        kunjungan[kamarAsal]=sudahDikunjungi;
        jarakDiketahui[kamarAsal]=0;
        kamarSekarang=kamarAsal;
        cout<<dataKamar[kamarSekarang];
        while(kamarSekarang!=kamarTujuan) {
            jarakLama=999;
            jarakSekarang=jarakDiketahui[kamarSekarang];
            for(int i=0; i<jumlahKamar; i++) {
                if(kunjungan[i]==belumDikunjungi) {
                    jarakBaru=jarakSekarang+dataJarak[kamarSekarang][i];
                    if(jarakBaru<jarakDiketahui[i]) {
                        jarakDiketahui[i]=jarakBaru;
                    }
                    if(jarakDiketahui[i]<jarakLama) {
                        jarakLama=jarakDiketahui[i];
                        posisiIndeks=i;
                    }
                }
            }
            kamarSekarang=posisiIndeks;
            kunjungan[kamarSekarang]=sudahDikunjungi;
            cout<<" -> "<<dataKamar[kamarSekarang];
        }
        cout<<"\nJarak terdekat dari "<<dataKamar[kamarAsal]<<" ke "<<dataKamar[kamarTujuan]<<" adalah "<<jarakDiketahui[kamarTujuan]<<endl;
        delete jarakDiketahui;
        delete kunjungan;
    }
}

void tampilMatriks() {
    cout << "\n[MATRIKS]" << endl;

    if(cekMatrik) {
        for(int i=0; i<jumlahKamar; i++) {
            cout<<dataKamar[i]<<" ";
        }
        cout<<endl;
        for(int baris=0; baris<jumlahKamar; baris++) {
            for(int kolom=0; kolom<jumlahKamar; kolom++) {
                cout<<dataJarak[baris][kolom]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"Matriks tidak ditemukan."<<endl;
    }
}

void denah() {
    int pilihan;

    system("cls");

    cout << "BERANDA > DENAH\n" << endl;
    cout << "1.  Atur denah" << endl;
    cout << "2.  Cari jalur terdekat" << endl;
    cout << "\n99. Kembali ke menu BERANDA" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;

    switch(pilihan) {
    case 1:
        system("cls");

        cout << "BERANDA > DENAH > ATUR DENAH\n" << endl;
        cout << "Masukkan jumlah kamar: ";
        cin >> jumlahKamar;
        buatMatriks();
        tampilMatriks();
        cout << "\nPengaturan denah berhasil." << endl;
        system("pause");
        denah();
        break;

    case 2:
        int asal, tujuan;

        system("cls");

        cout << "BERANDA > PENCARIAN JALUR\n" << endl;
        cout << "Masukkan kamar asal  : ";
        cin >> asal;
        kamarAsal = cariKamar(asal);
        cout << "Masukkan kamar tujuan: ";
        cin >> tujuan;
        kamarTujuan = cariKamar(tujuan);
        cout << "\n[HASIL]" << endl;
        hitungJarakTerdekat();
        system("pause");
        main();
        break;

    case 99:
        main();
        break;

    default :
        cout << "Maaf, pilihan tidak tersedia." << endl;
        system("pause");
        denah();
    }
}
