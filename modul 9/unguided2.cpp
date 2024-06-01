#include <iostream>

using namespace std;

int factorial(int n, int current) {
    if (current == n) {
        return 1; // Basis Case
    } else {
        return current * factorial(n, current + 1); // Rekursif
    }
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    int result = factorial(n, 1);
    cout << "Faktorial dari " << n << " adalah " << result << endl;

    return 0;
}