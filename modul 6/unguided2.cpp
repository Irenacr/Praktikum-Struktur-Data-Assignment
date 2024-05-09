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
