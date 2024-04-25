#include <iostream>
#include <string>
#include <cctype> // Untuk menggunakan fungsi isalpha() dan tolower()

using namespace std;

string kalimat;
int jumlah_vokal = 0;

int main() {
    cout << "\tMENGHITUNG BANYAKNYA HURUF VOKAL DALAM KALIMAT\n";
    cout << "\n Masukkan kalimat: ";
    getline(cin, kalimat);

    // Konversi kalimat menjadi huruf kecil untuk memudahkan penghitungan
    for (char &ch : kalimat) {
        ch = tolower(ch);
    }

    // Menghitung jumlah huruf vokal dalam kalimat yang diinputkan
    for (char ch : kalimat) {
        if (isalpha(ch) && (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            jumlah_vokal++;
        }
    }

    cout << "\n Jumlah huruf vokal dalam kalimat: " << jumlah_vokal << endl;

    return 0;
}
