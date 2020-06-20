#include <iostream>
#include <windows.h>
#include "header.h"
using namespace std;

void tentang(){
    int pil;

    system("cls");
    cout << "BERANDA > TENTANG APLIAKSI\n" << endl;
    cout << "reservasi-hotel\n" <<
            "Initial project by OnePeach47\n" <<
            "https://github.com/OnePeach47/reservasi-hotel\n" <<
            "Icon (c) Google\n" <<
            "\nPlease give me a star if you like this repository.\n" <<
            "You are free to use, modify, or develop this repository to your own project\n" <<
            "by not removing the initial contributor (OnePeach47).\n"
            "\nSee the rest contributor on my GitHub. DONATIONS ARE OPEN!" << endl;
    cout << "\n99.  Kembali ke BERANDA" << endl;
    cout << "Silakan masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil){
    case 99:
        main();
        break;

    default:
        cout << "[ERROR] Maaf pilihan tidak tersedia." << endl;
        system("pause");
        tentang();
    }
}
