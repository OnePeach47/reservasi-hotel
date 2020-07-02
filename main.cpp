#include <iostream>
#include <windows.h>
#include "header.h"

using namespace std;

int main() {
    SetConsoleTitle("reservasi-hotel v0.1 (nightly)");

    int pil;

    system("cls");
    cout << "BERANDA\n" << endl <<
         "1.  Check-in" << endl <<
         "2.  Tampil tamu" << endl <<
         "3.  Cari tamu" << endl <<
         "4.  Check out" << endl <<
         "5.  Denah" << endl <<
         "6.  Lihat riwayat reservasi" << endl <<
         "7.  Tentang aplikasi" << endl <<
         "\n99. Keluar" << endl <<
         "Masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil) {
    case 1:
        checkIn();
        break;

    case 2:
        tampilTamu();
        break;

    case 3:
        cariTamu();
        break;

    case 4:
        checkOut();
        break;

    case 5:
        denah();
        break;

    case 6:
        riwayatReservasi();
        break;

    case 7:
        tentang();
        break;

    case 99:
        keluar();
        break;

    default:
        cout << "Maaf, pilihan tidak tersedia." << endl;
        system("pause");
        main();

    }
}
