#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;

    // Meminta user untuk memasukkan data array
    cout << "Masukkan data array (pisahkan dengan koma): ";
    getline(cin, input);

    // Mengonversi input pengguna menjadi array of integers
    int data_array[100]; // asumsi(misal) maksimal 100 elemen
    int data_count = 0;

    stringstream ss(input);
    int num;
    while (ss >> num) {
        data_array[data_count++] = num;
        if (ss.peek() == ',')
            ss.ignore(); // ini berfungsi agar jika kita meng inputkan koma, koma tersebut akan di abaikan dan tidak terinput
    }

    //  fungsi Memisahkan nomor genap dan ganjil dari data array
    int genap[100], ganjil[100]; // asumsi maksimal 100 elemen genap/ganjil
    int genap_count = 0, ganjil_count = 0;

    for (int i = 0; i < data_count; ++i) {
        if (data_array[i] % 2 == 0)
            genap[genap_count++] = data_array[i];
        else
            ganjil[ganjil_count++] = data_array[i];
    }

    // Menampilkan output

    //menampilakan output semua array yang di inputkan
    cout << "data array: ";
    for (int i = 0; i < data_count; ++i) {
        cout << data_array[i];
        if (i != data_count - 1)
            cout << ", ";
    }
    cout << endl;
//menampilkan array elemen genap
    cout << "nomor genap: ";
    for (int i = 0; i < genap_count; ++i) {
        cout << genap[i];
        if (i != genap_count - 1)
            cout << ", ";
    }
    cout << endl;
//menampilkan array elemen ganjil
    cout << "nomor ganjil: ";
    for (int i = 0; i < ganjil_count; ++i) {
        cout << ganjil[i];
        if (i != ganjil_count - 1)
            cout << ", ";
    }
    cout << endl;

    return 0;
}
