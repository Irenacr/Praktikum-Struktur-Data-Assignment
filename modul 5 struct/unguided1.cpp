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
    // Membuat array dari struct nama_buku untuk menyimpan informasi 5 buku
    nama_buku daftar_buku[5];

    // Mengisi data untuk setiap buku dalam array
    daftar_buku[0] = {"Belajar Struktur Data", "Yanto", "Gramedia Pustaka Utama", 300, 150000};
    daftar_buku[1] = {"Algoritma Pemrograman", "Bambang", "Gramedia Pustaka Utama", 200, 120000};
    daftar_buku[2] = {"Pemrograman C++", "Budi", "Gramedia Pustaka Utama", 250, 125000};
    daftar_buku[3] = {"Dasar-Dasar Pemrograman", "Anisa", "Gramedia Pustaka Utama", 180, 100000};
    daftar_buku[4] = {"Aljabar Linear", "Citra", "Gramedia Pustaka Utama", 350, 180000};

    int pilihan;

    // Meminta pengguna untuk memilih buku yang ingin dilihat
    cout << "Pilih nomor buku yang ingin dilihat (1-5): ";
    cin >> pilihan;

    // Validasi input pengguna
    if (pilihan < 1 || pilihan > 5) {
        cout << "Input tidak valid. Harap pilih nomor buku antara 1 sampai 5." << endl;
        return 1; // Keluar dari program dengan kode error
    }

    // Menampilkan informasi dari buku yang dipilih
    cout << "Informasi Buku " << pilihan << ":" << endl;
    cout << "Judul Buku: " << daftar_buku[pilihan - 1].judul_buku << endl;
    cout << "Pengarang: " << daftar_buku[pilihan - 1].pengarang << endl;
    cout << "Penerbit: " << daftar_buku[pilihan - 1].penerbit << endl;
    cout << "Tebal Halaman: " << daftar_buku[pilihan - 1].tebal_halaman << " halaman" << endl;
    cout << "Harga Buku: Rp" << daftar_buku[pilihan - 1].harga_buku << endl;

    return 0;
}
