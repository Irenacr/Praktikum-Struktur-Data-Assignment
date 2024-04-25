#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string kalimat;
char cari;

void selection_sort() {
    sort(kalimat.begin(), kalimat.end());
}

void binary_search() {
    int awal = 0, akhir = kalimat.length() - 1, tengah;
    bool b_flag = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (kalimat[tengah] == cari) {
            b_flag = true;
            break;
        } else if (kalimat[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (b_flag) {
        cout << "\n Huruf '" << cari << "' ditemukan pada indeks ke-" << tengah << endl;
    } else {
        cout << "\n Huruf '" << cari << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main() {
    cout << "\tBINARY SEARCH UNTUK MENCARI HURUF DALAM KALIMAT\n";
    cout << "\n Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "\n Kalimat sebelum diurutkan: " << kalimat << endl;

    // Konversi kalimat menjadi huruf kecil untuk memudahkan pencarian
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    cout << "\n Masukkan huruf yang ingin Anda cari: ";
    cin >> cari;

    // Urutkan kalimat menggunakan selection sort
    selection_sort();

    cout << "\n Kalimat setelah diurutkan: " << kalimat << endl;

    binary_search();

    return 0;
}
