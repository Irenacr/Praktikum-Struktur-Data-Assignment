#include <iostream>
#include <string>
using namespace std;

struct nama_buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() {
    const int max_buku = 5; // Batas maksimum jumlah buku yang bisa dimasukkan
    nama_buku daftar_buku[max_buku];
    int jumlah_buku = 0; // Jumlah buku yang telah dimasukkan

    char lanjut_input;
    do {
        if (jumlah_buku >= max_buku) {
            cout << "Batas maksimum jumlah buku telah tercapai." << endl;
            break;
        }

        cout << "Masukkan data untuk Buku " << jumlah_buku + 1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin >> ws, daftar_buku[jumlah_buku].judul_buku); // Menggunakan getline untuk membaca seluruh baris termasuk spasi
        cout << "Pengarang: ";
        getline(cin >> ws, daftar_buku[jumlah_buku].pengarang);
        cout << "Penerbit: ";
        getline(cin >> ws, daftar_buku[jumlah_buku].penerbit);
        cout << "Tebal Halaman: ";
        cin >> daftar_buku[jumlah_buku].tebal_halaman;
        cout << "Harga Buku: Rp";
        cin >> daftar_buku[jumlah_buku].harga_buku;
        cout << endl;

        ++jumlah_buku;

        if (jumlah_buku < max_buku) {
            cout << "Apakah ingin memasukkan buku lagi? (y/n): ";
            cin >> lanjut_input;
            cin.ignore(); // Membersihkan buffer agar getline berikutnya berfungsi dengan baik
        } else {
            cout << "Batas maksimum jumlah buku telah tercapai." << endl;
            break;
        }
    } while (lanjut_input == 'y' || lanjut_input == 'Y');

    // Menampilkan informasi dari setiap buku dalam array
    cout << "Daftar Buku:" << endl;
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Buku " << i + 1 << ":" << endl;
        cout << "Judul Buku: " << daftar_buku[i].judul_buku << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Penerbit: " << daftar_buku[i].penerbit << endl;
        cout << "Tebal Halaman: " << daftar_buku[i].tebal_halaman << " halaman" << endl;
        cout << "Harga Buku: Rp" << daftar_buku[i].harga_buku << endl;
        cout << endl;
    }

    return 0;
}
