#include <iostream>
#include "header.h"
#include <windows.h>

using namespace std;

void tentang(){
    cout << "Program ini dikembangkan oleh :";
    cout<<endl;
    cout << "Afifah Nuraeni"<<endl;
    cout << "Jihad Shindu Ghossa"<<endl;
    cout << "Rozan Fajri Irfani"<<endl;
    cout << "Santho Madear Purba"<<endl;
 system("pause");
 main();
}

void keluar(){
    cout << "Terima Kasih Sudah Menggunakan Layanan Kami"<<endl;
    cout << "Selamat Menikmati,Semoga Hari Anda Menyenangkan :)"<<endl;
    cout << "Sampai Jumpa :)"<<endl;
    cout << endl;

    char pil;
    cout<< "Yakin ingin keluar(Y/T)? ";
    cin >> pil;
    if (pil == 'Y' || 'y'){
        cout << "Terima Kasih Sudah Menggunakan Layanan Kami"<<endl;
        exit(1);
    }else if (pil == 'T'|| 't'){
    main();
    }
}


