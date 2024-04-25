#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int jumlah_4 = 0;

    // Mencetak daftar data
    cout << "Data: {";
    for (int i = 0; i < 10; i++) {
        cout << data[i];
        if (i < 9) {
            cout << ", ";
        }
    }
    cout << "}" << endl << endl;

    // Mencetak data yang dicari
    cout << "Data yang dicari: " << cari << endl << endl;

    // Algoritma Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < 10; i++) {
        if (data[i] == cari) {
            jumlah_4++;
        }
    }

    // Mencetak jumlah data yang ditemukan
    cout << "Total data yang ditemukan: " << jumlah_4 << endl;

    return 0;
}
