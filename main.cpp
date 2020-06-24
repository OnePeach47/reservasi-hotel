#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int pil;

    system("cls");
    cout << "BERANDA\n" << endl <<
         "1.  Check-in" << endl <<
         "2.  Tampil tamu" << endl <<
         "3.  Cari tamu" << endl <<
         "4.  Check out" << endl <<
         "5.  Denah" << endl <<
         "6.  Lihat riwayat reservasi" << endl <<
         "\n99. Keluar" << endl <<
         "Masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil)
    {
    case 1:
        checkIn();
        break;

    case 2:
        tampilTamu();
        break;

    case 3:
        tampilTamu();
        break;

    case 4:
        checkOut();
        break;
    }
}
