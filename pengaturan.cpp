#include <iostream>
#include <windows.h>
#include "header.h"
using namespace std;

void pengaturan(){
    system("cls");

    int pil;

    cout << "BERANDA > PENGATURAN\n" << endl;
    cout << "1.  Atur ruang kamar dan denah" << endl;
    cout << "2.  Tampilkan struktur folder" << endl;
    cout << "3. " << endl;
    cout << "\n99. Kembali ke menu BERANDA" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil){
    case 99:
        main();

    default:
        cout << "[ERROR] Maaf pilihan tidak tersedia." << endl;
        system("pause");
        pengaturan();
    }
}
