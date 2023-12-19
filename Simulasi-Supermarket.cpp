#include <iostream>
#include <string>

using namespace std;

struct Barang {
  string kode;
  string nama;
  int harga;
  int stok;
};

Barang dataBarang[100];
int count = 0;

void tambahDataBarang() {
  if(count == 100) {
    cout << "Data penuh!" << endl;
    return;
  }

  Barang b;
  
  cout << "Kode: ";
  cin >> b.kode;
  cout << "Nama: ";
  cin >> b.nama;
  cout << "Harga: ";
  cin >> b.harga;
  cout << "Stok: "; 
  cin >> b.stok;

  dataBarang[count] = b;
  count++;
}

void tampilDataBarang() {
  cout << "Data Barang:" << endl;
  for(int i = 0; i < count; i++) {
    cout << dataBarang[i].kode << " | ";
    cout << dataBarang[i].nama << " | "; 
    cout << dataBarang[i].harga << " | ";
    cout << dataBarang[i].stok << endl;
  }  
}

void sortirDataBarang() {
  
  for(int i = 0; i < count - 1; i++) {
    for(int j = 0; j < count - i - 1; j++) {
      if(dataBarang[j].harga > dataBarang[j+1].harga) {
        Barang temp = dataBarang[j];
        dataBarang[j] = dataBarang[j+1];
        dataBarang[j+1] = temp;
      }
    }
  }
  
  cout << "Data berhasil diurutkan" << endl;  
}

void cariDataBarang() {

  string nama;
  cout << "Masukkan nama barang: ";
  cin >> nama;
  
  for(int i = 0; i < count; i++) {
    if(dataBarang[i].nama == nama) {
      cout << "Ketemu: " << dataBarang[i].nama << " | ";  
      cout << dataBarang[i].harga << endl;
      return;
    }
  }

  cout << "Barang tidak ditemukan" << endl;  
}

struct tumpukan {
  Barang data[100];
  int top;
};

tumpukan barangMasuk = {}; // Initialize to default values

struct antrian {
  Barang data[100];
  int depan;
  int belakang;
};

antrian antrianKasir = {}; // Initialize to default values

struct node {
  Barang data;
  node* next;
};

node* head = NULL;
node* tail = NULL;

void addTransaksi(Barang b) {
  node* newNode = new node({b, NULL});
  
  if(head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode; 
  }
  
}

int main() {
  int menu;
  
  while(true) {
    cout << "MENU:" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tampil Barang" << endl;
    cout << "3. Urutkan Barang" << endl;
    cout << "4. Cari Barang" << endl;
    cout << "5. Keluar" << endl;
    
    cin >> menu;
    
    if(menu == 1) {
      tambahDataBarang(); 
    } else if(menu == 2) {
      tampilDataBarang();
    } else if (menu == 3) {
      sortirDataBarang();
    } else if(menu == 4) {
      cariDataBarang();
    } else if(menu == 5) {
      break; 
    }
  }

  return 0; 
}
