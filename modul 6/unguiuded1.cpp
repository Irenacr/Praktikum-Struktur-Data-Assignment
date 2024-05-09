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
