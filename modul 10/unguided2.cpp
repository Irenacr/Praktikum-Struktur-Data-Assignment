#include <iostream>
using namespace std;

// Definisi struct pohon
struct pohon {
    pohon *kanan;
    char data;
    pohon *kiri;
};

// Deklarasi variabel global
pohon *simpul;
pohon *root;
pohon *saatini;
pohon *helperA;
pohon *helperB;
pohon *alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
    for (int i = 0; i < 256; i++) {
        alamat[i] = NULL;
    }
}

// Fungsi untuk membuat simpul baru
void simpulBaru_2311110066_IRENA_CAHYA_RESINAH(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// Fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silakan masukan data akar: ";
        cin >> dataAnda;
        simpulBaru_2311110066_IRENA_CAHYA_RESINAH(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1;
        char dataUser;
        alamat[i] = root;

        while (i < 256 && alamat[i] != NULL) {
            cout << "Masukkan data kiri dari " << alamat[i]->data << " (masukkan '0' jika tidak ada): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru_2311110066_IRENA_CAHYA_RESINAH(dataUser);
                alamat[i]->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                alamat[i]->kiri = NULL;
            }

            cout << "Masukkan data kanan dari " << alamat[i]->data << " (masukkan '0' jika tidak ada): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru_2311110066_IRENA_CAHYA_RESINAH(dataUser);
                alamat[i]->kanan = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                alamat[i]->kanan = NULL;
            }

            i++;
        }
    }
}

// Fungsi untuk membaca pohon pre-order
void bacaPreOrder(pohon *node) {
    if (node != NULL) {
        cout << node->data << " ";
        bacaPreOrder(node->kiri);
        bacaPreOrder(node->kanan);
    }
}

// Fungsi untuk membaca pohon in-order
void bacaInOrder(pohon *node) {
    if (node != NULL) {
        bacaInOrder(node->kiri);
        cout << node->data << " ";
        bacaInOrder(node->kanan);
    }
}

// Fungsi untuk membaca pohon post-order
void bacaPostOrder(pohon *node) {
    if (node != NULL) {
        bacaPostOrder(node->kiri);
        bacaPostOrder(node->kanan);
        cout << node->data << " ";
    }
}

// Fungsi utama
int main() {
    inisialisasi();
    int pilihan;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Membuat simpul akar" << endl;
        cout << "2. Menambah simpul" << endl;
        cout << "3. Membaca pohon pre-order" << endl;
        cout << "4. Membaca pohon in-order" << endl;
        cout << "5. Membaca pohon post-order" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                simpulAkar();
                break;
            case 2:
                tambahSimpul();
                break;
            case 3:
                cout << "Pre-order: ";
                bacaPreOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "In-order: ";
                bacaInOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Post-order: ";
                bacaPostOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 6);

    return 0;
}
