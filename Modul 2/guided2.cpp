#include <iostream>
using namespace std;

int main() {
    int maks, a, i = 1, lokasi = 0; // 1. Inisialisasi lokasi
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++) {
        cout << "Array ke-" << (i + 1) << ": "; // 3. Perbaikan output nomor array
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << (lokasi + 1) << endl; // 2. Penambahan 1 pada lokasi
    return 0;
}
