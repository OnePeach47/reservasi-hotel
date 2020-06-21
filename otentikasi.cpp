#include <iostream>
#include <fstream>
#include <string>

#include <conio.h>
#include <windows.h>

#include "header.h"
#include "helper.cpp"

using namespace std;

bool cekBerkasOtentikasi();
bool buatBerkasOtentikasi();
void akunBaru();
void masuk();

void otentikasi(){
    int pil;

    system("cls");
    cout << "BERANDA > OTENTIKASI\n" << endl;
    cout << "1. Masuk" << endl;
    cout << "2. Buat akun baru" << endl;
    cout << "3. Keluar" << endl;
    cout << "\n99.  Kembali ke BERANDA" << endl;
    cout << "Silakan masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil){
    case 1:
        masuk();
        break;

    case 2:
        akunBaru();
        break;

    case 3:
        //keluar();
        break;

    case 99:
        main();
        break;

    default:
        cout << "[ERROR] Maaf pilihan tidak tersedia." << endl;
        system("pause");
        otentikasi();
    }
}

bool cekBerkasOtentikasi(){
    ofstream otentikasi("kredensial.dat");

    if(otentikasi.is_open()){
        return 1;
    }else{
        return 0;
    }
}

bool buatBerkasOtentikasi(){

}

string getpass(char *prompt, bool show_asteriks = true){
    const char BACKSPACE = 8;
    const char RETURN = 13;

    string password;
    unsigned char ch = 0;

    cout << prompt;

    while ((ch = getch()) != RETURN){
        if (ch == BACKSPACE){
            if(password.length() != 0){
                if(show_asteriks){
                    cout << "\b \b";
                    password.resize(password.length() - 1);
                }
            }
        }else if (ch == 0 || ch == 224){
            getch();
            continue;
        }else{
            password += ch;
            if (show_asteriks){
                cout << "*";
            }
        }
    }
    cout << endl;
    return password;
}

void akunBaru(){
    string usr;
    system("cls");

    cout << "BERNDA > OTENTIKASI > BUAT AKUN BARU\n" << endl;
    cout << "Masukkan nama penguna    : ";
    cin >> usr;
    string pwd=getpass("Masukkan kata sandi      : ",true);
    string password=getpass("Masukkan ulang kata sandi: ",true);

    if (pwd == password){
        ofstream credential;
        credential.open ("kredensial.dat");

        if(credential.is_open()){
            int cek = cekStructCredential();
            string cekFname = to_string(cek);
            ofstream savestate;
            string savestateFname = ("savestate_p" + cekFname + "_" + usr + ".dat");
            savestate.open (savestateFname);

            if (savestate.is_open()){
                void pNum = p + cek;
                kredensial pNum = {usr, password, savestate};
                credential << (&["p" + cek], sizeof(struct kredensial));

            }else{
                cout << "\n[ERROR] Gagal membuat berkas save state , pastikan Anda memiliki akses perizinan yang cukup";
                system("pause");
                otentikasi();
            }

        }else{
            cout << "\n[ERROR] Gagal membuka berkas kredential, pastikan Anda memiliki akses perizinan yang cukup";
            system("pause");
            otentikasi();
        }
        credential.close();

        cout << "\n[SUCCSESS] Kredensial berhasil disimpan dan\n berkas save state berhasil dibuat.";
        system("pause");
        masuk();
    }else{
        cout << "\n[ERROR] Kata sandi tidak cocok." << endl;
        system("pause");
        otentikasi();
    }
}

void masuk(){
    int pil;
    system("cls");

    cout << "BERANDA > OTENTIKASI > MASUK\n" << endl;
    if (cekBerkasOtentikasi() == 1){
        ofstream otentikasi("kredensial.dat");
    }else{
        cout << "[ERROR] Berkas kredensial tidak dapat ditemukan\nsilakan buat akun baru terlebih dahulu.\n" << endl;
        cout << "1. Buat akun baru" << endl;
        cout << "2. Kembali ke menu OTENTIKASI" << endl;
        cout << "Silakan masukkan pilihan Anda: ";
        cin >> pil;

        switch(pil){
        case 1:
            akunBaru();

        case 2:
            otentikasi();

        default:
            cout << "[ERROR] Maaf pilihan tidak tersedia." << endl;
            system("pause");
            masuk();
        }
    }
}
