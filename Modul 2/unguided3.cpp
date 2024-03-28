#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (int i = 0; i < a; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    int maks = array[0];
    int min = array[0];
    int total = 0;
    float rata;

    for (int i = 0; i < a; i++) {
        total += array[i];
        if (array[i] > maks) {
            maks = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    rata = (float)total / a;

    int pilihan;
    cout << "Menu:\n";
    cout << "1. Nilai Maksimum\n";
    cout << "2. Nilai Minimum\n";
    cout << "3. Nilai Rata-rata\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Nilai maksimum adalah " << maks << endl;
            break;
        case 2:
            cout << "Nilai minimum adalah " << min << endl;
            break;
        case 3:
            cout << "Nilai rata-rata adalah " << rata << endl;
            break;
        default:
            cout << "Pilihan tidak valid.\n";
    }

    return 0;
}
