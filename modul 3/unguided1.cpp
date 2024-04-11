#include <iostream>
using namespace std;

void selectionSort(double arr[], int length) {
    int pos_max;
    double temp;
    for (int i = 0; i < length - 1; i++) {
        pos_max = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[pos_max]) {
                pos_max = j;
            }
        }
        if (pos_max != i) {
            temp = arr[i];
            arr[i] = arr[pos_max];
            arr[pos_max] = temp;
        }
    }
}

void printArray(double arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    const int length = 5;
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS mahasiswa sebelum diurutkan: " << endl;
    printArray(ips, length);

    selectionSort(ips, length);

    cout << "\nIPS mahasiswa setelah diurutkan: " << endl;
    printArray(ips, length);

    return 0;
}
