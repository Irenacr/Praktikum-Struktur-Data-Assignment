#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string NIM;
    int nilai;
};

// Hash table untuk menyimpan data mahasiswa
unordered_map<string, Mahasiswa> hashTable;

// Fungsi untuk menambahkan data baru
void tambahData() {
    string NIM;
    int nilai;

    cout << "Masukkan NIM: ";
    cin >> NIM;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    hashTable[NIM] = {NIM, nilai};
    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus data
void hapusData() {
    string NIM;

    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> NIM;

    if (hashTable.find(NIM) != hashTable.end()) {
        hashTable.erase(NIM);
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencari data berdasarkan NIM
void cariDataNIM() {
    string NIM;

    cout << "Masukkan NIM yang akan dicari: ";
    cin >> NIM;

    if (hashTable.find(NIM) != hashTable.end()) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~<<>>~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Data ditemukan!" << endl;
        cout << "NIM: " << hashTable[NIM].NIM << endl;
        cout << "Nilai: " << hashTable[NIM].nilai << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~<<>>~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencari data berdasarkan rentang nilai (80 – 90)
void cariDataNilai() {
    int nilaiAwal = 80;
    int nilaiAkhir = 90;

    cout << "Data dengan nilai dalam rentang " << nilaiAwal << " - " << nilaiAkhir << ":" << endl;

    for (const auto& pair : hashTable) {
        if (pair.second.nilai >= nilaiAwal && pair.second.nilai <= nilaiAkhir) {
            cout << "NIM: " << pair.first << endl;
            cout << "Nilai: " << pair.second.nilai << endl;
        }
    }
}

int main() {
    int pilihan;

    while (true) {
        cout << "--------------/~ Menu ~/--------------" <<endl;
        cout << "1. Tambahkan data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Cari data berdasarkan NIM" << endl;
        cout << "4. Cari data berdasarkan rentang nilai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                cariDataNIM();
                break;
            case 4:
                cariDataNilai();
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid!. Silakan pilih lagi." << endl;
        }
    }

    return 0;
}