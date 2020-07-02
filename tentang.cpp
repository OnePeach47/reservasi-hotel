/*
Mengandung prefiks raw string literal (R"( raw_characters )")
yang hanya kompatibel oleh kompiler C++11 ke atas.
Referensi lebih lanjut: https://en.cppreference.com/w/cpp/language/string_literal
*/

#include <iostream>
#include "header.h"
#include <windows.h>

using namespace std;

char pil;

void tentang() {
    system ("cls");

    cout << "BERANDA > TENTANG APLIKASI\n" << endl;
    cout << R"(              _
              -=\`\
          |\ ____\_\__
        -=\c`""""""" "`)
           `~~~~~/ /~~`                              reservasi-hotel
             -==/ /                                  v0.2-alpha (nightly)
               '-'                                   github.com/OnePeach47/reservasi-hotel/tree/nightly

               _  _                                  Pengembang awal: OnePeach47
              ( `   )_                               Kontributor    : AfifahNuraeni, rozanfajri, sanmade
             (    )    `)
           (_   (_ .  _) _)
                                          _
                                         (  )        Licensed under MIT license.
          _ .                         ( `  ) . )
        (  _ )_                      (_, _(  ,_)_)
      (_  _(_ ,))" << endl;
    cout << endl;
    system("pause");
    main();
}

void keluar() {
    system("cls");

    cout << "BERANDA > KELUAR\n" << endl;
    cout << "Apakah Anda yakin ingin keluar (y/t)? ";
    cin >> pil;

    if (pil == 'T' || pil == 't') {
        main();
    } else if (pil == 'Y' || pil == 'y') {
        cout << R"(                                   /\
                              /\  //\\
                       /\    //\\///\\\        /\
                      //\\  ///\////\\\\  /\  //\\
         /\          /  ^ \/^ ^/^  ^  ^ \/^ \/  ^ \
        / ^\    /\  / ^   /  ^/ ^ ^ ^   ^\ ^/  ^^  \
       /^   \  / ^\/ ^ ^   ^ / ^  ^    ^  \/ ^   ^  \       *
      /  ^ ^ \/^  ^\ ^ ^ ^   ^  ^   ^   ____  ^   ^  \     /|\
     / ^ ^  ^ \ ^  _\___________________|  |_____^ ^  \   /||o\
    / ^^  ^ ^ ^\  /______________________________\ ^ ^ \ /|o|||\
   /  ^  ^^ ^ ^  /________________________________\  ^  /|||||o|\
  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||\
 / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |
/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |ooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

             TERIMA KASIH TELAH MENGGUNAKAN APLIKASI INI
                           SAMPAI JUMPA :))" << endl;
        freeMemory(); //dealokasi memori pada variabel array dinamis
        HapusData(); //dealokasi linked list
        system("pause");
        exit(1);
    } else {
        cout << "Maaf, pilihan tidak tersedia." << endl;
        system("pause");
        keluar();
    }
}


