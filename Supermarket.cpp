#include <iostream>
#include <string>

using namespace std;

struct Barang {
  string kode;
  string nama;
  int harga;
  int stok;
};

struct Node {
  Barang data;
  Node* next;

  Node(Barang b) : data(b), next(NULL) {}
};

struct LinkedList {
  Node* head;
  Node* tail;

  LinkedList() : head(NULL), tail(NULL) {}

  void display() {
    Node* current = head;
    while (current != NULL) {
      cout << current->data.kode << " | ";
      cout << current->data.nama << " | ";
      cout << current->data.harga << " | ";
      cout << current->data.stok << endl;
      current = current->next;
    }
  }

  void sortirByKode() {
    if (head == NULL || head->next == NULL) return;

    bool swapped;
    Node* current;
    Node* last = NULL;

    do {
      swapped = false;
      current = head;

      while (current->next != last) {
        if (current->data.kode > current->next->data.kode) {
          swap(current->data, current->next->data);
          swapped = true;
        }
        current = current->next;
      }
      last = current;
    } while (swapped);
  }

  Node* findNodeByNama(string nama) {
    Node* current = head;
    while (current != NULL) {
      if (current->data.nama == nama) {
        return current;
      }
      current = current->next;
    }
    return NULL;
  }
};

LinkedList linkedList;

struct Stack {
  Node* top;

  Stack() : top(NULL) {}

  void push(Barang b) {
    Node* newNode = new Node(b);
    newNode->next = top;
    top = newNode;
  }

  void pop() {
    if (top != NULL) {
      Node* temp = top;
      top = top->next;
      delete temp;
    }
  }
};

struct Queue {
  Node* front;
  Node* rear;

  Queue() : front(NULL), rear(NULL) {}

  void enqueue(Barang b) {
    Node* newNode = new Node(b);
    if (rear == NULL) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  void dequeue() {
    if (front != NULL) {
      Node* temp = front;
      front = front->next;
      if (front == NULL) {
        rear = NULL;
      }
      delete temp;
    }
  }
};

Stack stack;
Queue queue;

void tambahDataBarang() {
  Barang b;

  cout << "Kode: ";
  cin >> b.kode;
  cout << "Nama: ";
  cin >> b.nama;
  cout << "Harga: ";
  cin >> b.harga;
  cout << "Stok: ";
  cin >> b.stok;

  Node* newNode = new Node(b);
  newNode->next = NULL;

  if (linkedList.head == NULL) {
    linkedList.head = linkedList.tail = newNode;
  } else {
    linkedList.tail->next = newNode;
    linkedList.tail = newNode;
  }
}

void tampilDataBarang() {
  cout << "Data Barang:" << endl;
  linkedList.display();
}

void sortirDataBarang() {
  linkedList.sortirByKode();
  cout << "Data berhasil diurutkan berdasarkan Kode Barang" << endl;
}

void cariDataBarang() {
  string nama;
  cout << "Masukkan nama barang: ";
  cin >> nama;

  Node* result = linkedList.findNodeByNama(nama);
  if (result != NULL) {
    cout << "Ketemu: " << result->data.nama << " | ";
    cout << result->data.harga << endl;
  } else {
    cout << "Barang tidak ditemukan" << endl;
  }
}

void barangMasukGudang() {
  Barang b;

  cout << "Tambah Barang Masuk - Kode: ";
  cin >> b.kode;
  cout << "Nama: ";
  cin >> b.nama;
  cout << "Harga: ";
  cin >> b.harga;
  cout << "Stok: ";
  cin >> b.stok;

  stack.push(b);
}

void barangKeluarGudang() {
  if (stack.top != NULL) {
    Barang b = stack.top->data;
    cout << "Barang Keluar - Kode: " << b.kode << " | Nama: " << b.nama << endl;
    queue.enqueue(b);
    stack.pop();
  } else {
    cout << "Gudang kosong" << endl;
  }
}

int main() {
  int menu;

  while (true) {
    cout << "MENU:" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tampil Barang" << endl;
    cout << "3. Urutkan Barang" << endl;
    cout << "4. Cari Barang" << endl;
    cout << "5. Barang Masuk Gudang" << endl;
    cout << "6. Barang Keluar Gudang" << endl;
    cout << "7. Keluar" << endl;
    cout << "Masukan Menu: ";
    cin >> menu;

    switch (menu) {
      case 1:
        tambahDataBarang();
        break;
      case 2:
        tampilDataBarang();
        break;
      case 3:
        sortirDataBarang();
        break;
      case 4:
        cariDataBarang();
        break;
      case 5:
        barangMasukGudang();
        break;
      case 6:
        barangKeluarGudang();
        break;
      case 7:
        return 0;
      default:
        cout << "Pilihan tidak valid!" << endl;
        break;
    }
  }

  return 0;
}

