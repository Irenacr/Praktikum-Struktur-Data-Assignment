# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Sorting didefinisikan sebagai pengurutan sejumlah data berdasarkan nilai kunci tertentu. Pengurutan  dapat  dilakukan  dari  nilai  terkecil  ke  nilai  terbesar  (ascending)  atau  sebaliknya (descending). Algoritma Sorting termasuk salah satu contoh yang kaya akan solusi (Wisudawan, 2008).Untuk mengatasi masalah kompleksitas waktu yang terkait dengan sorting algorithmpada pengaplikasian  fitur  pengurutan  harga  dari  terendah  dan  tertinggi  di  Shopee  berikut  beberapa solusi yang dapat kami tawarkan berdasarkan hasil penelitian kami (A. Oktian Permana & Sudin Saepudin, 2023)[1].

 Algoritma bubble   sort dan selection   sort kita menggunakan ide partition khusus algoritma yang mirip dengan quicksort. Begitu pula, algoritma insertion sortkita menggunakan ide merge khusus algoritma yang mirip dengan merge sort. Berbeda dengan merge sort dan quicksort, algoritma kita tidak efisien secara komputasi. Hal ini dikarenakan oleh fungsi partition dan merge  yang lambat yang digunakan oleh algoritma kita, yang masing-masing memanggil dirinya sendiri sebanyak empat atau tiga kali. Sebaliknya, fungsi merge  dari merge sorthanya memanggil dirinya sendiri dua kali (Ganapathi, P., & Chowdhury, R. 2021)[1].


### 1. Insertion Sort
Salah  satu  algoritma  sorting  yang  paling sederhana  adalah insertion  sort.  Insertion  Sort disebut-sebut   sebagai      metode   pertengahan. Artinya,  metode  ini  memiliki  kecepatan  rata-rata    antara    metode    primitif    (bubble    dan selection)  dan  modern  (merge  dan  quick)[10]. Metode   ini,   didasarkan   pada   sebuah   kunci yang  diambilpada  elemen  ke-2  pada  sebuah larik,  lalu  menyisipkan  elemen  tersebut  jika kondisi percabangan terpenuhi. Metode penyisipan (insertion) bertujuan untuk menjadikan  bagian  sisi  kiri  larik  terurutkan sampai dengan seluruh larik berhasil diurutkan[2].


### 2. Bubble Sort
Bubble  Sort adalah    algoritma  pengurutan  sederhana  yang  digunakan  dalam  komputer untuk mengurutkan sejumlah item data dalam urutan tertentu, biasanya dari yang terkecil hingga yang terbesar (ascending order) atau sebaliknya. Algoritma ini termasuk dalam kategori algoritma swap sort karena pada setiap iterasi pasangan elemen yang tidak berurutan dipertukarkan hingga seluruh data  terurut. Dalam analisa yang dilakukan oleh Rahayuningsih, P. A. (2016), Bubble sort algoritma sorting paling tua dan sederhana untuk diimplementasikan. Tetapi, algoritma ini juga merupakan  algoritma  yang  paling  lamban  dan  tidak  mangkus  dibandingkan  dengan  algoritma pengurutan yang lain dalam penggunaan secara umum.
[1].



## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
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


```
Kode tersebut adalah contoh program dalam bahasa C++ yang mengimplementasikan algoritma pengurutan Bubble Sort untuk mengurutkan sebuah array dari elemen-elemen bertipe data double. Program ini memungkinkan pengguna untuk mengurutkan bilangan dalam array dari nilai terkecil ke nilai terbesar.

kode tersebut adalah untuk mengurutkan bilangan dalam sebuah array menggunakan algoritma Bubble Sort dan kemudian menampilkan hasil pengurutan tersebut ke layar.

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void print_array(char a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[] = {'c', 'f', 'a', 'z', 'd', 'p'}; // Menghapus deklarasi length karena sudah dihitung secara otomatis
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);
    insertion_sort(a, length);
    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
    return 0; // Menambah return 0
}


```
#### Output:


Kode tersebut adalah implementasi dari algoritma pengurutan Insertion Sort untuk mengurutkan array karakter (char) dari urutan karakter terkecil hingga terbesar.

#### Full code Screenshot:


## Unguided


### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!
```C++
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

```


#### Output:

kode di atas berfungsi untuk mengurutkan IPS mahasiswa dari yang tersebsar ke yang terkecil, menggunakan algoritma Selection Sort .
1. mengurutkan array ips yang berisi nilai-nilai IPS mahasiswa dari yang tertinggi hingga terendah.
2.fungsi printArray() untuk mencetak array ke layar sebelum dan setelah pengurutan. Ini membantu dalam melihat hasil pengurutan dengan jelas.
3.Data nilai IPS mahasiswa disimpan dalam array ips[]. Dalam contoh ini, terdapat 5 nilai IPS yang diinisialisasi secara statis.
4. Kode ini mencetak nilai IPS mahasiswa sebelum dan setelah pengurutan ke layar.


#### Full code Screenshot:



### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!
```C++
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


```
#### Output:



tujuan dari kode ini adalah untuk mengurutkan nama-nama dalam sebuah array menggunakan algoritma Bubble Sort dan menampilkan hasil pengurutan tersebut. pengurutan Bubble Sort untuk mengurutkan sebuah array dari nama-nama dalam bentuk string. 
1. Fungsi menerima sebuah array string arr dan panjang array n. Di dalamnya, terdapat dua perulangan bersarang yang digunakan untuk membandingkan dan menukar elemen-elemen array agar terurut secara ascending (dari kecil ke besar) berdasarkan urutan alfabet.
2. Fungsi ini digunakan untuk mencetak semua elemen dalam array ke layar, dipisahkan oleh spasi. Ini digunakan untuk mencetak array sebelum dan setelah pengurutan.
3. Nama-nama disimpan dalam sebuah array string dengan nama names[]. Dalam contoh ini, terdapat 10 nama yang diinisialisasi secara statis.
4. Program ini mencetak nama-nama sebelum dan setelah pengurutan menggunakan Bubble Sort.

#### Full code Screenshot:


### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! 
```C++
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
 ```

 #### Output
Kode ini adalah program dalam bahasa C++ yang meminta pengguna untuk memasukkan suatu bilangan n dan sejumlah n karakter. Kemudian program akan melakukan pengurutan karakter secara menaik (ascending) dan menurun (descending) menggunakan vektor dan algoritma sorting bawaan dari C++ STL (Standard Template Library).tujuan dari kode ini adalah untuk memungkinkan pengguna memasukkan karakter-karakter, mengurutkannya secara menaik dan menurun, dan menampilkan hasil pengurutan tersebut.


## Kesimpulan
terungkap bahwa penggunaan algoritma Bubble Sort memiliki  keunggulan  dalam  kesederhanaan  maka  lebih  mudah  dipahami,  khususnya  dalam situasi dengan jumlah data yang relatif kecil,Selection Sortdapat menjadi pilihan yang lebih baik daripada Bubble  Sort(Rizki  Saputra,  Andryana  and  Sholihati,  2021)[1].


## Referensi
[1]  Davina Azalia Tara, "Analisis Kompleksitas Waktu Menggunakan Sorting Algorithmpada Pengaplikasian Fitur Pengurutan Harga dari Terendah dan Tertinggidi Shopee", Jurnal Potensial, Vol.3 No.1, E-ISSN: 2829-3886, 2024
[2]  Aried Hendra Saptadi, "ANALISISALGORITMA INSERTION SORT, MERGE SORT DAN IMPLEMENTASINYA DALAM BAHASA PEMROGRAMAN C++", 2012.
