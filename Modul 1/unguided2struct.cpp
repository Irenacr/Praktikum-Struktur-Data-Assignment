#include <iostream>
using namespace std;

// Deklarasi struct Mahasiswa
struct Mahasiswa {
    // Atribut
    string nama;
    int nilai;

    // Konstruktor untuk inisialisasi objek Mahasiswa
    Mahasiswa(string n, int ni) {
        nama = n;
        nilai = ni;
    }

    // Metode untuk menampilkan data mahasiswa
    void display() {
        cout << "Nama   : " << nama << endl;
        cout << "Nilai  : " << nilai << endl;
        cout << "Status : " << (lulus() ? "LULUS" : "TIDAK LULUS") << endl;
    }

private:
    // Metode untuk menentukan status kelulusan
    bool lulus() {
        return nilai > 75;
    }
};

int main() {
    string nama;
    int nilai;

    cout << "Masukkan nama    : ";
    getline(cin, nama);
    cout << "Masukkan nilai   : ";
    cin >> nilai;

    // Membuat objek Mahasiswa menggunakan konstruktor
    Mahasiswa mhs(nama, nilai);

    cout << endl;

    // Memanggil metode untuk menampilkan data mahasiswa
    mhs.display();

    return 0;
}
