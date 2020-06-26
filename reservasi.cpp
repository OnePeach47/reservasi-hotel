#include <iostream>
#include <ctime>
#include <windows.h>
#include "header.h"
#include "list.cpp"

using namespace std;

/* operasi aritmetika pada waktu */


/* buat struktur untuk menyimpan tamu */
struct tamu {
    string nama;
    string namaPanggilan;
    string alamat;
    int kamar;
    int harga;
    time_t waktu;
};

/* alokasikan kapasitas array dinamis berstruktur */
const int kapasitas = 1000;
tamu *pelanggan = new tamu[kapasitas];
int indexTamu = 0;

/* prosedur untuk menambahkan data ke struktur tamu */
void tambahDataTamu(int p) {
    for (int i = indexTamu; i < p+indexTamu; i++) {
        cout << "Masukkan data pelanggan ke-" << i+1 << ", indeks ke-" << i << ":" << endl;
        cout << "Masukkan nama lengkap               : ";
        getline(cin, pelanggan[i].nama);
        cin.sync();
        cout << "Masukkan nama panggilan             : ";
        getline(cin, pelanggan[i].namaPanggilan);
        cin.sync();
        cout << "Masukkan alamat                     : ";
        getline(cin, pelanggan[i].alamat);
        cin.sync();
        cout << "Masukkan nomor kamar                : ";
        cin >> pelanggan[i].kamar;
        cout << "Masukkan harga                      : ";
        cin >> pelanggan[i].harga;
        pelanggan[i].waktu = time(0);
        cout << endl;
    }
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

    system("pause");
    main();
}

/* main driver tampil tamu */
void tampilTamu() {
    int i = 0;
    bool kembali = 0;

    do {
        system ("cls");

        cout << "BERANDA > TAMPIL TAMU\n" << endl;
        cout << "\n[RINCIAN TAMU DAN PEMBAYARAN]" << endl;
        cout << "Nama          : " << pelanggan[i].nama << endl;
        cout << "Nama panggilan: " << pelanggan[i].nama << endl;
        cout << "Alamat        : " << pelanggan[i].alamat << endl;
        cout << "Nomor kamar   : " << pelanggan[i].kamar << endl;
        i++;

        cout << "Lanjut (y/n)? ";
        cin >> kembali;
    } while (i <= indexTamu && kembali == 0);
}

/* main driver check out */
void checkOut() {
    int k, indeksData, bayar;

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
    time_t sekarang = time(0);
    time_t durasi = sekarang - pelanggan[indeksData].waktu;
    cout << "Durasi              : " << durasi << " malam" << endl;
    cout << "Total               : Rp" << pelanggan[indeksData].harga*durasi << endl;
    cout << "====================================================================" << endl;
    cout << "Bayar               : Rp";
    cin >> bayar;
    cout << "Kembali             : Rp";

    TambahDepan(pelanggan[indeksData].nama + "," + pelanggan[indeksData].alamat + "," +
                pelanggan[indeksData].kamar + "," + pelanggan[indeksData].harga + "," +
                );

    delete[indeksData] pelanggan;
}

/* main driver check-in */
void checkIn() {
    int p;

    system("cls");

    cout << "BERANDA > CHECK-IN\n" << endl;
    cout << "Masukkan jumlah data yang ingin ditambah: ";
    cin >> p;
    tambahDataTamu(p);
    cout << "Data berhasil disimpan!" << endl;
    system("pause");
    main();
}
