#include <iostream>
#include <windows.h>
#include <sstream>
#include "header.h"

using namespace std;

/* buat struktur untuk menyimpan tamu */
struct tamu {
    string nama, namaPanggilan, alamat;
    int kamar, harga, waktu;
};

/* alokasikan kapasitas array dinamis berstruktur */
const int kapasitas = 1000;
tamu *pelanggan = new tamu[kapasitas];
int ukuran = 0;

/* prosedur untuk menambahkan data ke struktur tamu */
void tambahDataTamu(int p) {
    if (ukuran+p <= kapasitas) {
        for (int i = ukuran; i < ukuran+p; i++) {
            cout << endl;
            cout << "[DATA PELANGGAN KE-" << i+1 << "]" << endl;
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

        ukuran = ukuran+p;
        cout << "\nData berhasil disimpan!" << endl;
        system("pause");
    } else if (p == 0) {
        main();
    } else {
        cerr << "\nRuang memori tidak mencukupi, silakan check out beberapa tamu terlebih dahulu." << endl;
        system("pause");
        main();
    }

}

/* prosedur pencarian kamar metode sequential */
int cariIndeksKamar(int k) {
    int i = 0;

    while (i < ukuran) {
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

    while (i < ukuran) {
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

    if (ukuran == 0) {
        cout << "\nData tamu kosong." << endl;
        system("pause");
        main();
    } else {
        cout << "\n[DATA TAMU]" << endl;
        cout << "Nama                   : " << pelanggan[indeksData].nama << endl;
        cout << "Alamat                 : " << pelanggan[indeksData].alamat << endl;
        cout << "Nomor kamar            : " << pelanggan[indeksData].kamar << endl;
        cout << endl;

        system("pause");
        main();
    }
}

/* main driver tampil tamu */
void tampilTamu() {
    int i = 0;

    system ("cls");
    cout << "BERANDA > TAMPIL TAMU\n" << endl;
    if (ukuran == 0) {
        cout << "Data tamu kosong." << endl;
        system("pause");
        main();
    } else {
        cout << "[RINCIAN TAMU]" << endl;
        do {
            cout << "PELANGGAN KE-" << i+1 << ":" << endl;
            cout << "Nama          : " << pelanggan[i].nama << endl;
            cout << "Nama panggilan: " << pelanggan[i].namaPanggilan << endl;
            cout << "Alamat        : " << pelanggan[i].alamat << endl;
            cout << "Nomor kamar   : " << pelanggan[i].kamar << endl;
            cout << endl;
            i++;

        } while (i < ukuran);

        system("pause");
        main();
    }
}

/* main driver check out */
void checkOut() {
    int k, indeksData, bayar, total;
    float diskon;

    system("cls");

    cout << "BERANDA > CHECK OUT \n" << endl;
    if (ukuran == 0) {
        cout << "\nTidak ada data tamu yang menginap." << endl;
        system("pause");
        main();
    } else {
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
        cout << "Total sebelum diskon: Rp" << total << endl;
        cout << "Diskon (%)          : ";
        cin >> diskon;
        float hitungDiskon = (float)diskon / 100.0;
        float konversiHitungDiskon = hitungDiskon*(float)total;
        int hasil = total - konversiHitungDiskon;
        if (diskon != 0) {
            cout << "Total setelah diskon: Rp" << hasil << endl;
        }
        cout << "====================================================================" << endl;
        cout << "Bayar               : Rp";
        cin >> bayar;
        cout << "Kembali             : Rp" << bayar - hasil;
        cout << endl;

        stringstream ss;
        ss << pelanggan[indeksData].nama << ";" << pelanggan[indeksData].alamat << ";" << pelanggan[indeksData].kamar << ";" << pelanggan[indeksData].harga << ";" << pelanggan[indeksData].waktu << ";" << diskon << ";" << hasil;
        string data = ss.str();

        TambahDepan(data);

        for (int i = indeksData; i < ukuran; i++) {
            string tempPelanggan = pelanggan[i].nama;
            string tempNamaPanggilan = pelanggan[i].namaPanggilan;
            string tempAlamat = pelanggan[i].alamat;
            int tempKamar = pelanggan[i].kamar;
            int tempHarga = pelanggan[i].harga;
            int tempWaktu = pelanggan[i].waktu;
            pelanggan[i].nama = pelanggan[i+1].nama;
            pelanggan[i].namaPanggilan = pelanggan[i+1].namaPanggilan;
            pelanggan[i].alamat = pelanggan[i+1].alamat;
            pelanggan[i].kamar = pelanggan[i+1].kamar;
            pelanggan[i].harga = pelanggan[i+1].harga;
            pelanggan[i].waktu = pelanggan[i+1].waktu;
            pelanggan[i+1].nama = tempPelanggan;
            pelanggan[i+1].namaPanggilan = tempNamaPanggilan;
            pelanggan[i+1].alamat = tempAlamat;
            pelanggan[i+1].kamar = tempKamar;
            pelanggan[i+1].harga = tempHarga;
            pelanggan[i+1].waktu = tempWaktu;
        }

        ukuran--;

        cout << "\nPengunjung berhasil check out." << endl;
        system("pause");
        main();
    }
}


/* main driver check-in */
void checkIn() {
    int p;

    system("cls");

    cout << "BERANDA > CHECK-IN\n" << endl;
    cout << "Masukkan jumlah data yang ingin ditambah : ";
    cin >> p;
    tambahDataTamu(p);
    main();
}

/* prosedur membebaskan memori */
void freeMemory() {
    delete [] pelanggan;
}
