#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);

    // Meminta pengguna untuk memasukkan n karakter
    for (int i = 0; i < n; ++i) {
        cout << "Masukkan karakter ke-" << i + 1 << " : ";
        cin >> characters[i];
    }

    // Menampilkan urutan karakter sebelum sorting
    cout << "\nUrutan karakter sebelum di sorting:" << endl;
    for (char ch : characters) {
        cout << ch << "\t";
    }
    cout << endl;

    // Melakukan sorting secara menaik (ascending)
    sort(characters.begin(), characters.end());

    // Menampilkan urutan karakter setelah ascending sort
    cout << "Urutan karakter setelah ascending sort:" << endl;
    for (char ch : characters) {
        cout << ch << "\t";
    }
    cout << endl;

    // Melakukan sorting secara menurun (descending)
    sort(characters.rbegin(), characters.rend());

    // Menampilkan urutan karakter setelah descending sort
    cout << "Urutan karakter setelah descending sort:" << endl;
    for (char ch : characters) {
        cout << ch << "\t";
    }
    cout << endl;

    return 0;
}
