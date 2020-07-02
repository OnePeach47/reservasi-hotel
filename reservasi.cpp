#include <iostream>
#include <windows.h>
#include <sstream>
#include "header.h"

using namespace std;

/* buat struktur untuk menyimpan tamu */
struct tamu {
    string nama;
    string namaPanggilan;
    string alamat;
    int kamar;
    int harga;
    int waktu;
};

/* alokasikan kapasitas array dinamis berstruktur */
const int kapasitas = 1000;
tamu *pelanggan = new tamu[kapasitas];
int indexTamu = 0;

/* prosedur untuk menambahkan data ke struktur tamu */
void tambahDataTamu(int p) {
    for (int i = indexTamu; i < p+indexTamu; i++) {
        cout << endl;
        cout << "[DATA PELANGGAN KE-" << i+1 << ", INDEKS KE-" << i << "]" << endl;
        cout << "Masukkan nama lengkap  : ";
        cin >> pelanggan[i].nama;
        cout << "Masukkan nama panggilan: ";
        cin >> pelanggan[i].namaPanggilan;
        cout << "Masukkan alamat        : ";
        cin >> pelanggan[i].alamat;
        cout << "Masukkan nomor kamar   : ";
        cin >> pelanggan[i].kamar;
        cout << "Masukkan harga         : ";
        cin >> pelanggan[i].harga;
        cout << "Masukkan durasi (malam): ";
        cin >> pelanggan[i].waktu;
    }

    indexTamu = p+indexTamu;
}

/* prosedur pencarian kamar metode sequential */
int cariIndeksKamar(int k) {
    int i = 0;

    while (i < indexTamu) {
        if (pelanggan[i].kamar == k) {
            break;
        }
        i++;
    }

    return i;
}

/* prosedur pencarian indeks kamar tamu metode sequential */
int cariIndeksKamarTamu (string n) {
    int i = 0;

    while (i < indexTamu) {
        if (pelanggan[i].namaPanggilan == n) {
            break;
        }
        i++;
    }

    return i;
}

/* main driver cari tamu */
void cariTamu() {
    string n;
    int indeksData;

    system("cls");

    cout << "BERANDA > CARI TAMU\n" << endl;
    cout << "Masukkan nama panggilan: ";
    cin >> n;

    indeksData = cariIndeksKamarTamu(n);

    cout << "\n[DATA TAMU]" << endl;
    cout << "Nama                   : " << pelanggan[indeksData].nama << endl;
    cout << "Alamat                 : " << pelanggan[indeksData].alamat << endl;
    cout << "Nomor kamar            : " << pelanggan[indeksData].kamar << endl;
    cout << endl;

    system("pause");
    main();
}

/* main driver tampil tamu */
void tampilTamu() {
    int i = 0;

    system ("cls");
    cout << "BERANDA > TAMPIL TAMU\n" << endl;
    cout << "\n[RINCIAN TAMU]" << endl;

    do {
        cout << "PELANGGAN KE-" << i+1 << ", INDEKS KE-" << i << ":" << endl;
        cout << "Nama          : " << pelanggan[i].nama << endl;
        cout << "Nama panggilan: " << pelanggan[i].namaPanggilan << endl;
        cout << "Alamat        : " << pelanggan[i].alamat << endl;
        cout << "Nomor kamar   : " << pelanggan[i].kamar << endl;
        cout << endl;
        i++;

    } while (i < indexTamu);

    system("pause");
    main();
}

/* main driver check out */
void checkOut() {
    int k, indeksData, bayar, total;

    system("cls");

    cout << "BERANDA > CHECK OUT \n" << endl;
    cout << "Masukkan nomor kamar: ";
    cin >> k;

    indeksData = cariIndeksKamar(k);

    cout << "\n[RINCIAN TAMU DAN PEMBAYARAN]" << endl;
    cout << "Nama                : " << pelanggan[indeksData].nama << endl;
    cout << "Alamat              : " << pelanggan[indeksData].alamat << endl;
    cout << "Nomor kamar         : " << pelanggan[indeksData].kamar << endl;
    cout << "Harga               : Rp" << pelanggan[indeksData].harga << endl;
    cout << "Durasi              : " << pelanggan[indeksData].waktu << " malam" << endl;
    total = pelanggan[indeksData].harga*pelanggan[indeksData].waktu;
    cout << "Total               : Rp" << total << endl;
    cout << "====================================================================" << endl;
    cout << "Bayar               : Rp";
    cin >> bayar;
    cout << "Kembali             : Rp" << bayar-total;
    cout << endl;

    stringstream ss;
    ss << pelanggan[indeksData].nama << ";" << pelanggan[indeksData].alamat << ";" << pelanggan[indeksData].kamar << ";" << pelanggan[indeksData].harga << ";" << pelanggan[indeksData].waktu << ";" << total;
    string data = ss.str();

    TambahDepan(data);

    for (int i = indeksData; i <= indexTamu; i++) {
        pelanggan[i].nama = pelanggan[i+1].nama;
        pelanggan[i].namaPanggilan = pelanggan[i+1].namaPanggilan;
        pelanggan[i].alamat = pelanggan[i+1].alamat;
        pelanggan[i].kamar = pelanggan[i+1].kamar;
        pelanggan[i].harga = pelanggan[i+1].harga;
        pelanggan[i].waktu = pelanggan[i+1].waktu;
    }

    indexTamu--;

    cout << "\nPengunjung berhasil check out." << endl;
    system("pause");
    main();
}

/* main driver check-in */
void checkIn() {
    int p;

    system("cls");

    cout << "BERANDA > CHECK-IN\n" << endl;
    cout << "Masukkan jumlah data yang ingin ditambah : ";
    cin >> p;
    tambahDataTamu(p);
    cout << "\nData berhasil disimpan!" << endl;
    system("pause");
    main();
}

/* prosedur membebaskan memori */
void freeMemory() {
    delete [] pelanggan;
}
