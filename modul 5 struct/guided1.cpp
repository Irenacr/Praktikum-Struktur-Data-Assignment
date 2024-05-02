#include <iostream>
using namespace std;

struct nama_buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() {
    // Membuat objek dari struct nama_buku
    nama_buku buku1, buku2;

    // Mengisi data buku
    buku1.judul_buku = "Belajar struktur data";
    buku1.pengarang = "Yanto";
    buku1.penerbit = "gramedia pustaka utama";
    buku1.tebal_halaman = 300;
    buku1.harga_buku = 150000;

    // Menampilkan informasi buku
    cout << "Judul Buku: " << buku1.judul_buku << endl;
    cout << "Pengarang: " << buku1.pengarang << endl;
    cout << "Penerbit: " << buku1.penerbit << endl;
    cout << "Tebal Halaman: " << buku1.tebal_halaman << " halaman" << endl;
    cout << "Harga Buku: Rp" << buku1.harga_buku << endl;

    
    // Mengisi data buku2
    buku2.judul_buku = "Algoritma perograman";
    buku2.pengarang = "Yanto";
    buku2.penerbit = "gramedia pustaka utama";
    buku2.tebal_halaman = 200;
    buku2.harga_buku = 150000;

    // Menampilkan informasi buku
    cout << "Judul Buku: " << buku2.judul_buku << endl;
    cout << "Pengarang: " << buku2.pengarang << endl;
    cout << "Penerbit: " << buku2.penerbit << endl;
    cout << "Tebal Halaman: " << buku2.tebal_halaman << " halaman" << endl;
    cout << "Harga Buku: Rp" << buku2.harga_buku << endl;

    return 0;
}
