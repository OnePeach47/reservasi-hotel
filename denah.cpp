#include  <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

int jumlahKamar=999;
int *dataKamar;
int**dataJarak;
bool cekMatrik=false;
int posisiIndeks,jarakSekarang,jarakLama,jarakBaru;
int kamarAsal, kamarSekarang, kamarTujuan;
int sudahDikunjungi=1;
int belumDikunjungi=0;
int*jarakDiketahui;
int*kunjungan;
int baris;
char ya_tidak;

void buatMatriks(){
    dataKamar=new int [jumlahKamar];
    dataJarak=new int*[jumlahKamar];
    dataJarak[0]=new int[jumlahKamar*jumlahKamar];
    for(int i=1;i<jumlahKamar;i++){
        dataJarak[i]=dataJarak[i-1]+jumlahKamar;
    }
cout<<"Silahkan masukkan nomer kamar: "<<endl;
    for(int i=0;i<jumlahKamar;i++){
        cout<<"Nomer"<<i+1<<":";
        cin>>dataKamar[i];
    }

cout<<"Silahkan masukkan jarak antar kamar: "<<endl;
    for(int baris=0;baris<jumlahKamar;baris++){
        for(int kolom=0;kolom<jumlahKamar;kolom++){
            cout<<dataKamar[baris]<<"-->"<<dataKamar[kolom]<<":";
            cin>>dataJarak[baris][kolom];
        }
        cekMatrik=true;
    }
}
void hitungJarakTerdekat(){
    if(cekMatrik){
        jarakDiketahui=new int[jumlahKamar];
        kunjungan=new int[jumlahKamar];
        for(int i=0;i<jumlahKamar;i++){
            jarakDiketahui[i]=999;
            kunjungan[i]=belumDikunjungi;
        }
        kunjungan[kamarAsal]=sudahDikunjungi;
        jarakDiketahui[kamarAsal]=0;
        kamarSekarang=kamarAsal;
        cout<<kamarSekarang;
        while(kamarSekarang!=kamarTujuan){
            jarakLama=999;
            jarakSekarang=jarakDiketahui[kamarSekarang];
            for(int i=0;i<jumlahKamar;i++){
                if(kunjungan[i]==belumDikunjungi){
                    jarakBaru=jarakSekarang+dataJarak[kamarSekarang][i];
                    if(jarakBaru<jarakDiketahui[i]){
                        jarakDiketahui[i]=jarakBaru;
                    }
                    if(jarakDiketahui[i]<jarakLama){
                        jarakLama=jarakDiketahui[i];
                        posisiIndeks=i;
                    }
                }
            }
            kamarSekarang=posisiIndeks;
            kunjungan[kamarSekarang]=sudahDikunjungi;
            cout<<" -> "<<kamarSekarang;
        }
        cout<<"\nJarak terdekat dari "<<kamarAsal<<" ke "<<kamarTujuan<<" adalah "<<jarakDiketahui[kamarTujuan]<<endl;
        delete jarakDiketahui;
        delete kunjungan;
    }
}

void tampilMatriks(){
    if(cekMatrik){
        for(int i=0;i<jumlahKamar;i++){
            cout<<dataKamar[i]<<" ";
        }
        cout<<endl;
        for(int baris=0;baris<jumlahKamar;baris++){
            for(int kolom=0;kolom<jumlahKamar;kolom++){
                cout<<dataJarak[baris][kolom]<<" "; }
                cout<<endl;
            }
        }else{
            cout<<"Tidak ada matriks"<<endl;
    }
}

int main(){
    char keluar;
    int pilihan;

  do {
    system("cls");
    cout << "\t Pencarian Jalur Terdekat antar Kamar" << endl;
    cout << "1. Atur jumlah kamar" << endl;
    cout << "2. Atur jarak antar kamar" << endl;
    cout << "3. Cari jalur terdekat" << endl;
    cout << "4. Keluar" << endl;
    cout << "Silahkan Pilih Program (1-4): ";
    cin >> pilihan;

    switch(pilihan){
    case 1:
        cout << "Masukkan jumlah kamar: ";
        cin >> jumlahKamar;
        system("pause");
        break;
    case 2:
        buatMatriks();
        tampilMatriks();
        cout<< "berhasil mengatur jarak"<<endl;
        system("pause");
        break;
    case 3:
        cout << "Masukkan kamar asal: ";
        cin>>kamarAsal;
        cout << "Masukkan kamar tujuan: ";
        cin>>kamarTujuan;
        cout << "Jarak terdekat antar kamar adalah: ";
        hitungJarakTerdekat();
        cout<<endl;
        cout <<"berhasil mencari jarak terdekat";
        system("pause");
        break;
    case 4:
        cout<<"Yakin ingin keluar (y/t) ? ";
        cin>>ya_tidak;
    if(ya_tidak == 'y' || ya_tidak == 'Y'){
        cout<<" Terima kasih"<<endl;
        keluar = true;
    }
        system("cls");
        break;
        default :
    cout<<"Pilihan tidak tersedia..."<<endl;
    cout<<"Keluar (y/t) ? ";
    cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }else{
            system("cls");
        }
    }
}while(keluar == false);
    return 0;
}
