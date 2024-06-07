#include <iostream>
using namespace std;

//definisi struct pohon
struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

//deklarasi variabel global 
pohon * simpul;
pohon * root;
pohon * saatini;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

//fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

//fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul -> data = dataMasukkan;
    simpul -> kanan = NULL;
    simpul -> kiri = NULL;
}

//fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "silahkan masukan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "root terbentuk..." << endl;
    } else {
        cout << "root sudah ada..." << endl;
    }
}
// fungsi untuk menambah simpul 
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatini = alamat[i];
                saatini -> kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatini = alamat[i];
                    saatini -> kanan = simpul;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

//fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatini = alamat[i];
            cout << saatini -> data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n*2;
            }
            i++;
        }
    }
}

//fungsi utama
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}