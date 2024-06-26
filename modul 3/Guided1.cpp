#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j = 0;
    double tmp;
    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void selectSort(int arr[], int n) {
    int pos_min, temp;
    for (int i = 0; i < n - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos_min])
                pos_min = j;
        }
        if (pos_min != i) {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
}

void print_array(double a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6; // Jumlah elemen pada array
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99, 99.99}; // Penyesuaian jumlah elemen
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);
    bubble_sort(a, length);
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
    return 0;
}
