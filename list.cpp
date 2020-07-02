#include <iostream>
#include <windows.h>
#include <fstream>
#include "header.h"

using namespace std;

struct linkedlist {
    string data;
    linkedlist* next;
};

bool inisialisasiEksporFlag = 0;
bool inisialisasiFlag = 0;

linkedlist* head;
linkedlist* tail;
linkedlist* simpul;
linkedlist* clear;

void buat_simpul(string data_masukkan) {
    simpul = new linkedlist;
    simpul->data = data_masukkan;
    simpul->next = NULL;
}

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool simpul_kosong() {
    if(head == NULL && tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void TambahDepan(string data_user) {
    if (inisialisasiFlag == 0) {
        inisialisasi();
        inisialisasiFlag = 1;
    }
    if(simpul_kosong()==true) {
        buat_simpul(data_user);
        head=simpul;
        tail=simpul;
    } else {
        buat_simpul(data_user);
        simpul->next = head;
        head = simpul;
    }
}

void HapusData() {
    if(simpul_kosong()==true) {
        cout << "Tidak ada data yang dihapus." << endl;
    } else {
        linkedlist* helper;
        helper = head;
        if(head == tail) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            head = head->next;
            head = clear;
            delete helper;
        }
    }
}


void TampilData() {
    if(simpul_kosong()==true) {
        cout<< "Tidak ada data yang ditampilkan." << endl;
    } else {
        linkedlist* helper;
        helper = head;
        while(helper != NULL) {
            cout<<helper->data<<endl;

            helper=helper->next;
        }
    }
}


void eksporData() {
    ofstream pengunjung ("ekspor.csv", ios::app);

    if (inisialisasiEksporFlag == 0) {
        if (pengunjung.is_open()) {
            pengunjung << "Nama;Alamat;Nomor Kamar;Harga;Durasi;Total" << endl;
        } else {
            cerr << "Tidak dapat membuka berkas. Pastikan akses perizinan berkas yang memadai untuk mengakses berkas." << endl;
        }
        pengunjung.close();
    }

    if(simpul_kosong()==true) {
        cout<< "Tidak ada data yang diekspor." << endl;
    } else {
        pengunjung.open("ekspor.csv", ios::app);

        if (pengunjung.is_open()) {
            linkedlist* helper;
            helper = head;
            while(helper != NULL) {
                pengunjung<<helper->data<<endl;

                helper=helper->next;
            }
            pengunjung.close();
            cout << "\nData berhasil diekspor!" << endl;
        } else {
            cerr << "Tidak dapat membuka berkas. Pastikan akses perizinan berkas yang memadai untuk mengakses berkas." << endl;
        }
    }
}

/*
void eksporData() {
    ofstream pengunjung ("ekspor.csv", ios::app);

    if(simpul_kosong() == true) {
        cout << "Tidak ada data yang diekspor." << endl;
    } else {
        linkedlist* helper;
        helper = head;
        tail = tail;

        if (inisialisasiEksporFlag == 0) {
            if(pengunjung.is_open()) {
                pengunjung << "Nama;Alamat;Nomor Kamar;Harga;Durasi;Total" << endl;
                pengunjung.close();
            } else {
                cerr << "Tidak dapat membuka berkas. Pastikan akses perizinan berkas yang memadai untuk mengakses berkas." << endl;
            }
            inisialisasiEksporFlag = 1;
        } else {
            pengunjung.open("ekspor.csv", ios::app);

            if (pengunjung.is_open()) {
                while (helper != NULL) {
                    pengunjung << helper -> data << endl;
                    helper = helper -> next;
                }
                pengunjung.close();
            } else {
                cerr << "Tidak dapat membuka berkas. Pastikan akses perizinan berkas yang memadai untuk mengakses berkas." << endl;
            }
        }
        cout << "\nData berhasil diekspor!" << endl;
    }
}
*/

void riwayatReservasi() {
    int pil;

    system("cls");

    cout << "BERANDA > RIWAYAT RESERVASI\n" << endl;
    cout << "Nama;Alamat;Nomor Kamar;Harga;Durasi;Total" << endl;
    TampilData();
    cout << "\n1.  Expor riwayat reservasi" << endl;
    cout << "\n99. Kembali ke BERANDA" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil) {
    case 1:
        eksporData();
        HapusData();
        system("pause");
        riwayatReservasi();
        break;

    case 99:
        main();
        break;

    default:
        cout << "Maaf, pilihan tidak tersedia." << endl;
        system("pause");
        riwayatReservasi();
    }
}
