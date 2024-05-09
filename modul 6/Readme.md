# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Linked List adalah salah satu bentuk struktur data, berisi kumpulan data 
(node) yang tersusun secara sekuensial, saling sambungmenyambung, 
dinamis dan terbatas. 
- Linked List sering disebut juga Senarai Berantai 
- Linked List saling terhubung dengan bantuan variabel pointer 
- Masing-masing data dalam Linked List disebut dengan node (simpul) yang 
menempati alokasi memori secara dinamis dan biasanya berupa struct 
yang terdiri dari beberapa field[1].

### 1. Single Linked List
Single Linked List adalah sebuah LINKED LIST yang menggunakan sebuah variabel pointer saja untuk menyimpan banyak data dengan metode LINKED LIST, suatu daftar isi yang saling berhubungan.Single Linked List adalah sekumpulan dari node yang saling terhubung dengan node lain melalui sebuah pointer.Single Linked List hanya memiliki satu arah dan tidak memiliki dua arah atau bulak balik, dua arah tersebut disebut dengan double linked list Pada Implementasinya, Single Linked List terdapat dua variasi yaitu circular dan noncircular[1].
Kelebihan dari Single Linked List dengan Head & Tail adalah pada penambahan data di belakang, hanya dibutuhkan tail yang mengikat node baru saja tanpa harus menggunakan perulangan pointer bantu[1].
1. Single Linked List Non Circular
Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan nodebaru,mulanya pointer next dan prev akan menunjuk ke nilai NULL. Selanjutnya pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node selanjutnya pada list[3].
2. Single Linked list Circular
Single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya[3].
### 2. Double Linked List
Pada dasarnya, penggunaan Double Linked List hampir sama dengan penggunaan Single Linked List. Hanya saja Double Linked List menerapkan sebuah pointer baru, yaitu prev, yang digunakan untuk menggeser mundur selain tetap mempertahankan pointer next[2].
- Keberadaan 2 pointer penunjuk (next dan prev) menjadikan Double Linked List menjadi lebih fleksibel dibandingkan Single Linked List, namun dengan mengorbankan adanya memori tambahan dengan adanya pointer tambahan tersebut[2].

## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
Kode ini merupakan implementasi dari struktur data linked list (daftar berantai) dalam bahasa C++. Linked list adalah struktur data linear di mana setiap elemen (node) terdiri dari dua bagian: data dan pointer ke node berikutnya.
Kode ini menyediakan implementasi sederhana dari linked list non-circular dengan sejumlah operasi dasar seperti penambahan, penghapusan, pengubahan, dan tampilan isi linked list. ini adalah single linked list dengan head & tail.

### 2. Tipe Data Abstrak

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}

```
Kode ini adalah implementasi dari struktur data Doubly Linked List dalam bahasa C++. Doubly Linked List adalah jenis linked list di mana setiap node memiliki dua pointer: satu untuk menunjuk ke node sebelumnya (prev) dan satu untuk menunjuk ke node selanjutnya (next). Kode ini bertujuan untuk menyediakan penggunaan interaktif dari Doubly Linked List melalui menu pilihan yang disediakan dalam fungsi main(). Pengguna dapat memanipulasi linked list dengan menambah, menghapus, mengubah nilai, menghapus semua elemen, dan menampilkan isi linked list sesuai dengan pilihan yang mereka buat dari menu.


## Unguided 

### 1. 

```C++
#include <iostream>
using namespace std;

class Node {
public:
    string nama;
    int usia;
    Node* next;

    Node(string _nama, int _usia) {
        nama = _nama;
        usia = _usia;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambah_depan(string nama, int usia) {
        Node* new_node = new Node(nama, usia);
        new_node->next = head;
        head = new_node;
    }

    void tambah_belakang(string nama, int usia) {
        Node* new_node = new Node(nama, usia);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last_node = head;
        while (last_node->next) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    void tampilkan() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->nama << "\t" << current->usia << endl;
            current = current->next;
        }
    }

    void hapus_data(string nama) {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }

        if (head->nama == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current && current->nama != nama) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << "Data " << nama << " tidak ditemukan." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    void ubah_data(string nama, int usia_baru) {
        Node* current = head;
        while (current) {
            if (current->nama == nama) {
                current->usia = usia_baru;
                return;
            }
            current = current->next;
        }
        cout << "Data " << nama << " tidak ditemukan." << endl;
    }

    void ubah_data(string nama, string nama_baru, int usia_baru) {
        Node* current = head;
        while (current) {
            if (current->nama == nama) {
                current->nama = nama_baru;
                current->usia = usia_baru;
                return;
            }
            current = current->next;
        }
        cout << "Data " << nama << " tidak ditemukan." << endl;
    }

    void tambah_tengah(string nama, int usia, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih besar dari 0." << endl;
            return;
        }

        Node* new_node = new Node(nama, usia);
        if (posisi == 1 || !head) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        int current_pos = 1;
        while (current && current_pos < posisi - 1) {
            current = current->next;
            current_pos++;
        }

        if (!current) {
            cout << "Posisi melebihi panjang linked list." << endl;
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList linked_list;

    // Menambahkan data sesuai permintaan
    linked_list.tambah_belakang("John", 19);
    linked_list.tambah_belakang("Jane", 20);
    linked_list.tambah_belakang("Michael", 18);
    linked_list.tambah_belakang("Yusuke", 19);
    linked_list.tambah_belakang("Akechi", 20);
    linked_list.tambah_belakang("Hoshino", 18);
    linked_list.tambah_belakang("Karin", 18);

    // Menu program
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "a. Hapus data" << endl;
        cout << "c. Tambahkan data nama dan umur di depan" << endl;
        cout << "b. Tambahkan data nama dan umur di belakang" << endl;
        cout << "m. Tambahkan data nama dan umur di tengah" << endl;
        cout << "e. Ubah data" << endl;
        cout << "f. Tampilkan seluruh data" << endl;
        cout << "x. Keluar" << endl;

        char pilihan;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 'a') {
            string nama_hapus;
            cout << "Masukkan nama yang ingin dihapus: ";
            cin >> nama_hapus;
            linked_list.hapus_data(nama_hapus);
        } else if (pilihan == 'c') {
            string nama;
            int usia;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan usia: ";
            cin >> usia;
            linked_list.tambah_depan(nama, usia);
        } else if (pilihan == 'b') {
            string nama;
            int usia;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan usia: ";
            cin >> usia;
            linked_list.tambah_belakang(nama, usia);
        } else if (pilihan == 'm') {
            string nama;
            int usia, posisi;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan usia: ";
            cin >> usia;
            cout << "Masukkan posisi (mulai dari 1): ";
            cin >> posisi;
            linked_list.tambah_tengah(nama, usia, posisi);
        } else if (pilihan == 'e') {
            string nama, nama_baru;
            int usia_baru;
            cout << "Masukkan nama yang ingin diubah: ";
            cin >> nama;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru;
            cout << "Masukkan usia baru: ";
            cin >> usia_baru;
            linked_list.ubah_data(nama, nama_baru, usia_baru);
        } else if (pilihan == 'f') {
            cout << "\nData Mahasiswa:" << endl;
            linked_list.tampilkan();
        } else if (pilihan == 'x') {
            cout << "Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-05-09 235942](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/becec643-3e5b-47ba-8fc8-73973908caa1)
![Screenshot 2024-05-10 000000](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/77313c2f-bebf-4265-ac48-488c04862a94)
![Screenshot 2024-05-10 000056](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/1c4c4fc4-51a5-46aa-8db4-909535d9c210)



Kode ini adalah implementasi dari struktur data Linked List berbasis Node dalam bahasa C++. Linked List adalah struktur data dinamis yang terdiri dari sejumlah Node yang saling terhubung, di mana setiap Node menyimpan data dan referensi ke Node berikutnya.

fungsi Kode:
1. Penyediaan Fungsionalitas Linked List:
Menambah Data:
- tambah_depan: Menambahkan data di awal linked list.
- tambah_belakang: Menambahkan data di akhir linked list.
- tambah_tengah: Menambahkan data di posisi tertentu dalam linked list.
Menghapus Data:
- hapus_data: Menghapus data berdasarkan nama dari linked list.
Mengubah Data:
- ubah_data: Mengubah data berdasarkan nama dengan data baru (nama dan usia).
Menampilkan Data:
- tampilkan: Menampilkan seluruh data yang ada dalam linked list.
2. Mengosongkan Linked List:
- Destruktor ~LinkedList(): Mengosongkan memori yang dialokasikan untuk linked list pada akhir program.
Interaksi Pengguna:
- Pengguna dapat berinteraksi dengan linked list melalui menu yang disediakan:
- Menambah data di depan, belakang, atau di tengah.
- Menghapus data berdasarkan nama.
- Mengubah data berdasarkan nama.
- Menampilkan seluruh isi linked list.
- Keluar dari program.


#### Full code Screenshot:
![Screenshot 2024-05-09 235441](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/01370a68-eec2-4dc4-bb1e-1e3ad4d2b1a2)




### 2. 

#### Class
```C++
#include <iostream>
using namespace std;

class Node {
public:
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;

    Node(string _nama, int _harga) {
        nama_produk = _nama;
        harga = _harga;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambah_belakang(string nama, int harga) {
        Node* new_node = new Node(nama, harga);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void tambah_tengah(string nama, int harga, string nama_sebelum) {
        Node* new_node = new Node(nama, harga);
        Node* current = head;
        while (current) {
            if (current->nama_produk == nama_sebelum) {
                new_node->next = current->next;
                if (current->next)
                    current->next->prev = new_node;
                current->next = new_node;
                new_node->prev = current;
                if (current == tail)
                    tail = new_node;
                break;
            }
            current = current->next;
        }
    }

    void hapus(string nama) {
        Node* current = head;
        while (current) {
            if (current->nama_produk == nama) {
                if (current == head) {
                    head = current->next;
                    if (head)
                        head->prev = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                break;
            }
            current = current->next;
        }
    }

    void update(string nama, string nama_baru, int harga_baru) {
        Node* current = head;
        while (current) {
            if (current->nama_produk == nama) {
                current->nama_produk = nama_baru;
                current->harga = harga_baru;
                break;
            }
            current = current->next;
        }
    }

    void tampilkan() {
        cout << "Nama Produk\tHarga" << endl;
        Node* current = head;
        while (current) {
            cout << current->nama_produk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }

    ~DoubleLinkedList() {
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoubleLinkedList skincare;

    // Menambahkan data awal
    skincare.tambah_belakang("Originote", 60000);
    skincare.tambah_belakang("Somethinc", 150000);
    skincare.tambah_belakang("Skintific", 100000);
    skincare.tambah_belakang("Wardah", 50000);
    skincare.tambah_belakang("Hanasui", 30000);

    // Menu program
    while (true) {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int pilihan;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama_produk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                skincare.tambah_belakang(nama_produk, harga);
                break;
            }
            case 2: {
                string nama_produk_hapus;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_produk_hapus;
                skincare.hapus(nama_produk_hapus);
                break;
            }
            case 3: {
                string nama_produk_update;
                string nama_produk_baru;
                int harga_baru;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_produk_update;
                cout << "Masukkan nama produk baru: ";
                cin >> nama_produk_baru;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                skincare.update(nama_produk_update, nama_produk_baru, harga_baru);
                break;
            }
            case 4: {
                string nama_produk;
                int harga;
                string nama_sebelum;
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> nama_sebelum;
                skincare.tambah_tengah(nama_produk, harga, nama_sebelum);
                break;
            }
            case 5: {
                // Implementasi hapus data urutan tertentu (opsional)
                break;
            }
            case 6: {
                // Implementasi hapus seluruh data (opsional)
                break;
            }
            case 7: {
                cout << "\nData Mahasiswa:" << endl;
                skincare.tampilkan();
                break;
            }
            case 8: {
                cout << "Program selesai." << endl;
                return 0;
            }
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0;
}


```
#### Output:
![Screenshot 2024-05-10 001038](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/ae9c956d-4143-42d9-b8c8-caac33fddb40)
![Screenshot 2024-05-10 001054](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/51fed021-590e-40c6-8432-8bf3d1d46dfd)
![Screenshot 2024-05-10 001111](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/6a6ae120-8866-4bcf-a3a6-815b701b29d7)


Kode ini adalah implementasi dari struktur data Doubly Linked List dalam bahasa C++ untuk manajemen data produk skincare di sebuah toko. Kode ini memungkinkan pengguna untuk melakukan operasi dasar pada data skincare, seperti menambah, menghapus, memperbarui, dan menampilkan data, serta menambahkan data di posisi tertentu.
##### Tujuan Kode
- Manajemen Data Produk Skincare:
Kode ini bertujuan untuk menyediakan sistem manajemen data produk skincare di sebuah toko.
Data produk skincare disimpan dalam bentuk Doubly Linked List, yang memungkinkan operasi penambahan, penghapusan, dan pembaruan data dengan fleksibilitas.
- Interaksi Pengguna dengan Menu:
Kode ini menyediakan menu interaktif untuk pengguna, di mana pengguna dapat memilih berbagai operasi yang ingin dilakukan terhadap data produk skincare.
Menu ini memungkinkan pengguna untuk menambahkan data baru, menghapus data, memperbarui data, menambahkan data di posisi tertentu, dan menampilkan seluruh data.
##### manfaat 
1. Fleksibilitas dalam Penambahan Data:
- Pengguna dapat menambahkan data produk skincare di belakang atau di posisi tertentu dalam linked list sesuai kebutuhan toko.
2. Efisiensi pada Penghapusan Data:
- Dengan menggunakan Doubly Linked List, penghapusan data dapat dilakukan dengan efisien tanpa memerlukan pergeseran besar pada elemen data lainnya.
3. Kemudahan dalam Pembaruan Data:
- Pengguna dapat dengan mudah memperbarui data produk skincare dengan memberikan nama produk yang ingin diperbarui beserta data baru (nama produk dan harga baru).
4. Antarmuka Interaktif untuk Pengguna:
- Kode ini menyediakan antarmuka yang mudah dipahami oleh pengguna dengan menggunakan menu interaktif, di mana pengguna dapat dengan jelas memilih operasi yang ingin dilakukan terhadap data skincare.
5. Pengelolaan Memori yang Aman:
- Kode ini memastikan pengelolaan memori yang aman dengan menghapus node-node yang dialokasikan secara dinamis menggunakan destruktor DoubleLinkedList pada akhir program.

Melalui implementasi ini, pengguna dapat mengelola data produk skincare secara efisien dan fleksibel dengan menggunakan struktur data Doubly Linked List, yang cocok digunakan dalam skenario manajemen data seperti ini. Ini memungkinkan pengembangan lebih lanjut dan pemeliharaan yang mudah terhadap sistem manajemen data tersebut.


#### Full code Screenshot:
![Screenshot 2024-05-09 235621](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/9403bbed-9942-44db-8522-3b275b84eb6e)




## Kesimpulan
Pada modul 3 SINGLE AND DOUBLE LINKED LIST, saya memahami perbedaan konsep Single, Double, Circular dan Non Linked List berdasarkan guided 1 dan 2. dan saya juga menerapkan SingleSingle, Double, Circular dan Non Linked List ke dalam pemrograman unguided 1 dan 2. dari keseluruhan modul single linked list saya mengetahui bahwa Untuk aplikasi umum dengan pertimbangan performa dan efisiensi memori, Single Linked List Biasa (Non-Circular) sering kali merupakan pilihan yang baik karena sederhana dan mudah diimplementasikan. Namun, untuk kasus-kasus khusus seperti jika kita sering kali memerlukan operasi tambah belakang, menggunakan Single Linked List dengan Tail Pointer bisa menjadi opsi yang lebih efisien. 



## Referensi
[1] Agung Kurniman Putra, Single Linked List. Osf.oi, 2019. dapat diakses di: https://doi.org/10.31219/osf.io/u6qf7

[2] Triase, Struktur Data, osf.io, 2020. dapat diakses di: http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf

[3] Adzriel Arraffi, PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK, 2019. dapat diakses di: https://doi.org/10.31219/osf.io/sczvp
