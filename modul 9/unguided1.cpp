#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1; // Basis Case
    } else {
        return n * factorial(n - 1); // Rekursif
    }
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    int result = factorial(n);
    cout << "Faktorial dari " << n << " adalah " << result << endl;

    return 0;
}