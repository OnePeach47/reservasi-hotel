#include <iostream>

#include <windows.h>

#include "header.h"

using namespace std;

void keluar();

int main()
{
    SetConsoleTitle("reservasi-hotel");

    int pil;

    system("cls");
    cout << "BERANDA\n" << endl;
    cout << "1.  Otentikasi" << endl;
    cout << "2.  Pengaturan" << endl;
    cout << "3.  Reservasi" << endl;
    cout << "4.  Periksa ketersediaan kamar" << endl;
    cout << "5.  Periksa denah" << endl;
    cout << "6.  Tentang aplikasi" << endl;
    cout << "\n88. Keluar" << endl;
    cout << "Silakan masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil){
    case 1:
        otentikasi();
        break;

    case 2:
        pengaturan();
        break;

    case 3:
        reservasi();
        break;

    case 4:
        cekKamar();
        break;

    case 5:
        denah();
        break;

    case 88:
        keluar();

    default:
        cout << "[ERROR] Maaf pilihan tidak tersedia." << endl;
        system("pause");
        main();
    }
}

void keluar(){
    char input;

    cout << "BERANDA > KELUAR\n" << endl;
    cout << "Anda yakin ingin keluar (y/t) ";
    cin >> input;

    if (input == 'y' || input == 'Y'){
        cout << "Terima kasih telah menggunakan program ini.";
    }else if (input == 't' || input == 'T'){
        main();
    }
}
