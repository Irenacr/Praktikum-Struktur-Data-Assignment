#include <iostream>
#include <map>

using namespace std;

int main() {
    // Membuat map yang menampung NIM (key) dan nama mahasiswa (value)
    map<int, string> daftarMahasiswa;

    // Menambahkan data mahasiswa ke dalam map
    daftarMahasiswa[23112233] = "Asep";
    daftarMahasiswa[23112244] = "Jarwo";
    daftarMahasiswa[23112255] = "Siti";
    daftarMahasiswa[23112266] = "Selly";

    // Menampilkan daftar mahasiswa
    cout << "Daftar Mahasiswa:" << endl;
    for (const auto& pair : daftarMahasiswa) {
        cout << "NIM: " << pair.first << ", Nama: " << pair.second << endl;
    }

    // Mengakses data mahasiswa berdasarkan NIM
    int nimCari;
    cout << "Masukkan NIM: ";
    cin >> nimCari;

    // Memeriksa apakah NIM ditemukan dalam map
    auto it = daftarMahasiswa.find(nimCari);
    if (it != daftarMahasiswa.end()) {
        cout << "Nama mahasiswa dengan NIM " << nimCari << " adalah " << it->second << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }

    return 0;
}
