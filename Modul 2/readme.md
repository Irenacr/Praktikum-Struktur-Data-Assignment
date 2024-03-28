# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Struktur Data memberikan penjelasan tentang suatu koleksi atau kelompok data yang dapat dikarakteristikan oleh organisasi serta operasi yang didefinisikan terhadapnya. Pemakaian struktur data yang tepat didalam proses pemrograman,akan menghasilkan algoritma yang kebih jelas dan tepat sehingga menjadikan program secara keseluruhan lebih sederhana. Didalam sruktur data ini ada struktur data sederhana, salah satunya adalah array. Array bisa juga disebut sebagai salah satu program yang terlahir dari dunia tekhnologi lewat pola pikir manusia yang bermanfaat untuk menyelesaikan suatu penghitungan[2].

Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal[2]. 



### 1. Array Satu Dimensi
Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan
Deklarasi : Type_Data Nama_Variabel [index] 
Misalnya : int A[5]; [2]


### 2. Array Dua Dimensi
Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama[2].

### 3. Array Tiga Dimensi
Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama[2].Array tiga dimensi merupakan array yang terdiri dari x buah
baris, y buah kolom, dan z panjang karakter[1].

## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
// Program input array tiga dimensi
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z <<
 "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z <<
 "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Program di atas merupakan contoh program yang digunakan untuk mendemonstrasikan konsep penggunaan array tiga dimensi dalam bahasa pemrograman C++. Tujuan dari program ini adalah untuk mengilustrasikan bagaimana array tiga dimensi dapat dideklarasikan, diisi dengan nilai, dan ditampilkan ke layar.

Dengan menggunakan program ini, pengguna dapat memahami cara kerja array tiga dimensi, termasuk cara mengakses dan memanipulasi setiap elemen dalam array tersebut. Program ini juga membantu pengguna untuk memahami konsep penggunaan loop bersarang untuk mengakses setiap elemen array dalam berbagai dimensi. Selain itu, program ini dapat digunakan sebagai dasar untuk membangun aplikasi yang lebih kompleks yang melibatkan manipulasi data dalam array tiga dimensi.

### 2. Program Mencari Nilai Maksimal pada Array


```C++
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

```
Kode di atas adalah sebuah program dalam bahasa C++ yang bertujuan untuk mencari nilai maksimum dari sejumlah angka yang dimasukkan oleh pengguna ke dalam sebuah array.


## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
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

```
#### Output:
![Screenshot 2024-03-21 211955](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/cdc0014e-ab17-4fbc-9970-63f96cb88d09)


Kode di atas adalah sebuah program dalam bahasa C++ yang bertujuan untuk memisahkan dan menampilkan bilangan genap dan ganjil dari sebuah array yang diinputkan oleh pengguna.
Kesimpulan: Program ini membantu pengguna untuk memahami konsep manipulasi array, penggunaan loop untuk iterasi array, serta konsep dasar dalam mengelola input dan output dalam bahasa pemrograman C++.
-	Program ini meminta pengguna untuk memasukkan data array, yang dipisahkan oleh koma. 
-	 Setelah mendapatkan array dari input pengguna, program melakukan iterasi melalui array tersebut. Setiap elemen dicek apakah genap atau  ganjil, dan kemudian disimpan dalam array genap atau ganjil sesuai dengan kategorinya.
-	Setelah memisahkan genap dan ganjil, program menampilkan output dengan cara:
- Menampilkan semua elemen array yang diinputkan oleh pengguna.
- Menampilkan semua elemen genap.
- Menampilkan semua elemen ganjil.

#### Full code Screenshot:
![Screenshot 2024-03-21 213424](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/7b3223df-0e00-4b76-8ee3-47609ecb01c4)



### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!
```C++
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



#### Output:


Kode di atas adalah sebuah program dalam bahasa C++ yang bertujuan untuk mencari nilai maksimum dari sebuah array yang diinputkan oleh pengguna

- Program ini meminta pengguna untuk memasukkan panjang array, yaitu jumlah elemen yang akan dimasukkan ke dalam array.
- Setelah mendapatkan panjang array, pengguna diminta untuk memasukkan angka sejumlah panjang array tersebut. Setiap angka yang dimasukkan akan disimpan dalam array.
- Program kemudian melakukan iterasi melalui array untuk mencari nilai maksimum. Pada awalnya, nilai maksimum diinisialisasi dengan nilai pertama dalam array (array[0]). Selama iterasi, jika nilai pada indeks tertentu lebih besar dari nilai maksimum saat ini, nilai maksimum diperbarui dan lokasi (indeks) nilai maksimum tersebut juga disimpan.
- Setelah selesai mencari nilai maksimum, program menampilkan nilai maksimum beserta dengan lokasinya (indeks) dalam array.

Program ini membantu pengguna untuk memahami cara mengimplementasikan pencarian nilai maksimum dalam sebuah array menggunakan bahasa pemrograman C++.


#### Full code Screenshot:



### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user

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



Kode di atas adalah sebuah program dalam bahasa C++ yang memungkinkan pengguna untuk memasukkan sejumlah angka ke dalam sebuah array, kemudian melakukan operasi untuk mencari nilai maksimum, minimum, atau rata-rata dari angka-angka tersebut berdasarkan pilihan pengguna.
Berikut adalah fungsi utama dari program ini:
1.  Program meminta pengguna untuk memasukkan panjang array, yaitu jumlah elemen yang akan dimasukkan ke dalam array. Setelah itu, pengguna diminta untuk memasukkan angka sejumlah panjang array tersebut. Setiap angka yang dimasukkan akan disimpan dalam array.
2. Setelah semua angka dimasukkan, program melakukan iterasi melalui array untuk mencari nilai maksimum, minimum, dan total dari semua angka. Setelah total nilai ditemukan, program menghitung rata-rata dengan membagi total oleh jumlah elemen array.
3. Setelah selesai menghitung nilai maksimum, minimum, dan rata-rata, program menampilkan menu untuk meminta pilihan pengguna. Pengguna dapat memilih opsi untuk menampilkan nilai maksimum, minimum, atau rata-rata dari angka-angka yang dimasukkan. Program kemudian menampilkan nilai sesuai dengan pilihan pengguna.

Kode ini membantu pengguna untuk memahami cara mengimplementasikan operasi sederhana seperti mencari nilai maksimum, minimum, dan rata-rata dalam sebuah array menggunakan bahasa pemrograman C++.


#### Full code Screenshot:
![Screenshot 2024-03-21 213235](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/81473268-7069-41f6-8b94-6f23c368cd0e)


## Kesimpulan
Pada modul 1 guided ini kita belajar mengenai array. array di bagi menjadi 3 jenis:
1. Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data
dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. 
2. Array dua dimensi adalah variable yang terdiri dari kumpulan array
satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom.
3. Array multidimensi memiliki kesamaan dengan array satu dimensi dan
dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini
digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau
array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array
empat dimensi, array lima dimensi, dan seterusnya.


## Referensi
[1]  Universitas pembangunan Jaya, Wayan suparta, Struktur data: Tipe Data Array.dapat di akses di: https://ocw.upj.ac.id/files/Handout-INF202-INF202-Struktur-Data-Wayan-Pertemuan-4.pdf

[2]  Universitas Mitra Indonesia, M. Aldi Pratama, Array,2020. dapat di akses di: https://osf.io/vyech/download
