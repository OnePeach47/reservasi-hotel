#include <iostream>

using namespace std;

struct linkedlist{
    string data;
    linkedlist* next;
};

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

void HapusData(){
   if(simpul_kosong()==true){
       cout<<"Tidak ada simpul";
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
        cout<<"Tidak ada data"<<endl;
    }else{
        linkedlist* helper;
        helper = head;
        tail = tail;
    while(helper != NULL){
        cout<<helper->data<<" ";

        helper=helper->next;
        }
    }
}


int main(){
    inisialisasi();
    TambahDepan("Rozan HAHA hahah");
    TambahDepan("ah");
    TambahDepan ("woyy");
    HapusData();
    TampilData();

    return 0;
}
