#include <iostream>
#include <windows.h>
#include <fstream>
#include "header.h"

using namespace std;

struct linkedlist{
    string data;
    linkedlist* next;
};

bool inisialisasiFlag = 0;

linkedlist* head;
linkedlist* tail;
linkedlist* simpul;
linkedlist* clear;

void buat_simpul(string data_masukkan){
    simpul = new linkedlist;
    simpul->data = data_masukkan;
    simpul->next = NULL;
}

void inisialisasi(){
    head = NULL;
    tail = NULL;
}

bool simpul_kosong(){
    if(head == NULL && tail == NULL){
        return true;
    }else{
        return false;
    }
}

void TambahDepan(string data_user){
    if (inisialisasiFlag == 0){
        inisialisasi();
        inisialisasiFlag = 1;
    }else{
        if(simpul_kosong()==true){
        buat_simpul(data_user);
        head=simpul;
        tail=simpul;
    }else{
     buat_simpul(data_user);
        simpul->next = head;
        head = simpul;
    }
}
    }


void HapusData(){
   if(simpul_kosong()==true){
       cout<<"Tidak ada data!";
   }else{
       linkedlist* helper;
       helper = head;
      // head = clear;
   if(head == tail){
       head = NULL;
       tail = NULL;
       delete helper;
   }else{
       head = head->next;
       head = clear;
       delete helper;
     }
   }
}


void TampilData(){
    if(simpul_kosong()==true){
        cout<<"Tidak ada data yang ditampilkan"<<endl;
    }else{
        linkedlist* helper;
        helper = head;
        tail = tail;
    while(helper != NULL){
        cout<<helper->data<<endl;

        helper=helper->next;
        }
    }
}

void eksporData()
{
    if(simpul_kosong() == true){
        cout << "Tidak ada data yang diekspor!" << endl;
    }else{
        linkedlist* helper;
        helper = head;
        tail = tail;

        ofstream pengunjung ("ekspor.csv");

        if (pengunjung.is_open()){
            pengunjung << "Nama,Alamat,Nomor Kamar,Harga,Durasi,Total" << endl;
            while (helper != NULL){
                pengunjung << helper -> data << endl;
                helper = helper -> next;
            }
        }
        pengunjung.close();
        cout << "Data berhasil diekspor!";
    }
}

void riwayatReservasi(){
    int pil;

    system("cls");

    cout << "BERANDA > TAMPIL TAMU\n" << endl;

    TampilData();

    cout << "1.  Expor riwayat reservasi" << endl;
    cout << "2.  Hapus semua riwayat reservasi" << endl;
    cout << "\n99. Kembali ke BERANDA" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;

    switch(pil){
    case 1:
        eksporData();
        system("pause");
        riwayatReservasi();
        break;

    case 2:
        HapusData();
        cout << "Data telah dihapus!" << endl;
        system("pause");
        riwayatReservasi();
        break;

    case 99:
        main();
        break;

    default:
        cout << "Maaf, pilihan tidak tersedia." << endl;
        system("pause");
        riwayatReservasi();
    }
}
