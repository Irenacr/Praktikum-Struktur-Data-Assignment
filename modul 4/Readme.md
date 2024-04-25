# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Pencarian (Searching) yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Hasil pencarian adalah salah satu dari tiga keadaan ini: data ditemukan, data ditemukan lebih dari satu, atau data tidak ditemukan. Searching juga dapat dianggap sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau setiap index kolomnya dengan menggunakan teknik perulangan untuk melakukan pencarian data.

### 1. Sequential Searching
Algoritma sequential searching yang biasanya disebut sebagai pendekatan pencarian secara beruntun merupakan pencarian yang diawali dari elemen awal sampai dengan elemen akhir secara beruntun hingga bisa menemukan elemen yang akan dikunjungi. Algoritma ini mampu melakukan pencarian dengan array yang data-datanya tidak perlu melalui pengurutan data sebelumnya. Cara kerja algoritma ini adalah dengan melakukan perbandingan antara data yang ada dengan data yang akan dicari satu per satu secara berurutan sampai dapat menemukan datanya[1].Konsep Sequential Search yaitu:

• Membandingkan setiap elemen pada array satu per satu secara 
berurut
• Proses pencarian dimulai dari indeks pertama hingga indeks terakhir
• Proses pencarian akan berhenti apabila data ditemukan. Jika hingga 
akhir array data masih juga tidak ditemukan, maka proses pencarian 
tetap akan dihentikan
• Proses perulangan pada pencarian akan terjadi sebanyak jumlah N 
elemen pada array


### 2. Binary Search
Pencarian biner (Binary Search) adalah metode pencarian data pada array yang telah terurut. Metode ini lebih efisien daripada metode pencarian linier dimana semua elemen di dalam array diuji satu per satu sampai ditemukan elemen yang diinginkan. Selain dari pencarian biner, terdapat juga pencarian interpolasi (interpolation search), pencarian lompat (jump search), yang sama-sama bekerja pada data yang terurut. Pencarian pada data yang terurut menghasilkan pencarian yang cepat. Pencarian interpolasi mempunyai kekompleksan waktu rata-rata adalah O (log log n),sedangkan pencarian lompat adalah O(kn1/(k+1)). Kekompleksan waktu untuk pencarian biner adalah O (log n) seperti yang dikemukakan oleh Knuth. Pada pencarian biner, data harus dalam keadaan terurut. Proses pencarian bermula dengan membagikan array menjadi dua. Jika data yang dicari lebih kecil dari data yang terletak di tengah-tengah, maka proses pencarian akan dilanjutkan ke sebelah kiri dengan cara membagi array sebelah kirim menjadi dua. Sebaliknya jika data yang dicari lebih besar dari data yang terletak di tengah, maka proses pencarian akan dilanjutkan ke sebelah kanan dengan kembali membagi array menjadi dua bagian dan mencari titik tengahnya. Proses pembagian akan terus berulang hingga data yang dicari ditemukan[2].Konsep Binary Search:
• Data diambil dari posisi 1 sampai posisi akhir N
• Kemudian data akan dibagi menjadi dua untuk mendapatkan posisi 
data tengah
• Selanjutnya data yang dicari akan dibandingkan dengan data yang 
berada di posisi tengah, apakah lebih besar atau lebih kecil.
• Apabila data yang dicari lebih besar dari data tengah, maka dapat 
dipastikan bahwa data yang dicari kemungkinan berada di sebelah 
kanan dari data tengah. Proses pencarian selanjutnya akan 
dilakukan pembagian data menjadi dua bagian pada bagian kanan 
dengan acuan posisi data tengah akan menjadi posisi awal untuk 
pembagian tersebut.
• Apabila data yang dicari lebih kecil dari data tengah, maka dapat 
dipastikan bahwa data yang dicari kemungkinan berada di sebelah 
kiri dari data tengah. Proses pencarian selanjutnya akan dilakukan 
pembagian data menjadi dua bagian pada bagian kiri. Dengan acuan 
posisi data tengah akan menjadi posisi akhir untuk pembagian 
selanjutnya.
• Apabila data belum ditemukan, maka pencarian akan dilanjutkan 
dengan kembali membagi data menjadi dua
• Namun apabila data bernilai sama, maka data yang dicari langsung 
ditemukan dan pencarian dihentikan

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    
    // algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    
    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    
    if (ketemu) {
        cout << "\nangka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    
    return 0;
}

```
Kode yang diberikan adalah program dalam bahasa C++ yang mengimplementasikan algoritma Sequential Search (pencarian berurutan) untuk mencari angka tertentu dalam sebuah array.

### 2. Tipe Data Abstrak

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```
Kode tersebut adalah sebuah program dalam bahasa C++ yang mengimplementasikan algoritma Binary Search untuk mencari sebuah angka dalam sebuah array.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string kalimat;
char cari;

void selection_sort() {
    sort(kalimat.begin(), kalimat.end());
}

void binary_search() {
    int awal = 0, akhir = kalimat.length() - 1, tengah;
    bool b_flag = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (kalimat[tengah] == cari) {
            b_flag = true;
            break;
        } else if (kalimat[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (b_flag) {
        cout << "\n Huruf '" << cari << "' ditemukan pada indeks ke-" << tengah << endl;
    } else {
        cout << "\n Huruf '" << cari << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main() {
    cout << "\tBINARY SEARCH UNTUK MENCARI HURUF DALAM KALIMAT\n";
    cout << "\n Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "\n Kalimat sebelum diurutkan: " << kalimat << endl;

    // Konversi kalimat menjadi huruf kecil untuk memudahkan pencarian
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    cout << "\n Masukkan huruf yang ingin Anda cari: ";
    cin >> cari;

    // Urutkan kalimat menggunakan selection sort
    selection_sort();

    cout << "\n Kalimat setelah diurutkan: " << kalimat << endl;

    binary_search();

    return 0;
}

```


program tersebut adalah implementasi dari algoritma Binary Search dalam bahasa C++ yang mencari sebuah huruf dalam sebuah kalimat. Pada program yang saya buat,  
-	void binary_search(): Sebuah fungsi untuk melakukan pencarian biner pada variabel kalimat yang sudah diurutkan. Fungsi ini mencari huruf yang disimpan dalam variabel cari di dalam kalimat yang disimpan dalam variabel kalimat. Jika huruf tersebut ditemukan, fungsi akan mencetak indeks di mana huruf tersebut ditemukan. Jika tidak, fungsi akan mencetak pesan bahwa huruf tersebut tidak ditemukan dalam kalimat[2].






### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!


#### Class
```C++
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


```




Kode tersebut adalah sebuah program dalam bahasa C++ yang menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna.[2] pada program yang saya buat:

- saya menggunakan getline(cin, kalimat): Menggunakan fungsi getline() untuk membaca satu baris kalimat yang dimasukkan oleh pengguna, dan menyimpannya dalam variabel kalimat.
- saya juga menggunakan for (char &ch : kalimat): Melakukan iterasi melalui setiap karakter dalam kalimat menggunakan loop for each. Variabel ch merepresentasikan setiap karakter dalam kalimat. Dalam loop ini, setiap karakter dikonversi menjadi huruf kecil menggunakan fungsi tolower() untuk memudahkan penghitungan.
- for (char ch : kalimat): Loop kedua juga melakukan iterasi melalui setiap karakter dalam kalimat. Dalam loop ini, setiap karakter dicek apakah merupakan huruf vokal atau bukan menggunakan fungsi isalpha(). Jika karakter adalah huruf dan merupakan huruf vokal ('a', 'e', 'i', 'o', atau 'u'), maka jumlah_vokal akan ditambah satu.



### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search

```C++
#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int jumlah_4 = 0;

    // Mencetak daftar data
    cout << "Data: {";
    for (int i = 0; i < 10; i++) {
        cout << data[i];
        if (i < 9) {
            cout << ", ";
        }
    }
    cout << "}" << endl << endl;

    // Mencetak data yang dicari
    cout << "Data yang dicari: " << cari << endl << endl;

    // Algoritma Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < 10; i++) {
        if (data[i] == cari) {
            jumlah_4++;
        }
    }

    // Mencetak jumlah data yang ditemukan
    cout << "Total data yang ditemukan: " << jumlah_4 << endl;

    return 0;
}


```


Kode yang Anda berikan adalah program dalam bahasa C++ yang menggunakan algoritma Sequential Search untuk menghitung jumlah kemunculan suatu angka tertentu dalam sebuah array. 
berikut beberapa fungsi dan variabel yang saya gunakan:

1. Mendefinisikan array `data` yang berisi sekumpulan angka.
2. Mendefinisikan variabel `cari` yang menyimpan angka yang ingin dicari dalam array.
3. Mendefinisikan variabel `jumlah_4` yang akan digunakan untuk menghitung jumlah kemunculan angka yang dicari.
4. Mencetak daftar data yang ada dalam array menggunakan loop `for`.
5. Mencetak data yang dicari.
6. Melakukan pencarian menggunakan algoritma Sequential Search dengan loop `for`. Setiap kali angka yang dicari ditemukan dalam array, variabel `jumlah_4` akan ditambah satu.
7. Mencetak jumlah data yang ditemukan.

Jadi, tujuan dari kode tersebut adalah untuk mencari berapa kali suatu angka (dalam kasus ini angka 4) muncul dalam array `data`, dan kemudian mencetak jumlah kemunculan tersebut.





## Kesimpulan
Pada modul 4 guided ini kita belajar mengenai algoritma searching yang ada pada bahasa C++. Ada 2 tipe data yang ada yaitu Sequential Search,dan binary search. Sequential Search merupakan salah satu algoritma pencarian data yang biasa digunakan untuk data yang berpola acak atau belum terurut. Sequential search juga merupakan teknik pencarian data dari array yang  paling mudah, dimana data dalam array dibaca satu demi satu dan diurutkan dari index terkecil ke index terbesar, maupun sebaliknya. Pada tipe Binary Search termasuk ke dalam interval search, dimana algoritma ini merupakan algoritma pencarian pada array/list dengan elemen terurut. Pada metode ini, data harus diurutkan terlebih dahulu dengan cara data dibagi menjadi dua bagian (secara logika), untuk setiap tahap pencarian. Dalam penerapannya algoritma ini sering digabungkan dengan algoritma sorting karena data yang akan digunakan harus sudah terurut terlebih dahulu.

Kemudian untuk modul 1 unguided kita belajar mengenai metode algoritma searching, membuat program yang menggunakan sequential search dan binary search. dan saya juga belajar bahwa Perbedaan utama antara keduanya terletak pada keefisienan waktu dan implementasi. Sequential search cocok untuk kumpulan data yang kecil atau tidak terurut, sementara binary search cocok untuk kumpulan data yang besar dan sudah terurut.
## Referensi
[1] Rahmanto,Penerapan Algoritma Sequential Search pada Aplikasi Kamus Bahasa Ilmiah Tumbuhan. Universitas Teknokrat Indonesia, 2021.

[2] Alba Ragil Sutra Deva, PENERAPAN ALGORITMA BINARY SEARCH PADA APLIKASI E-ORDER (STUDI KASUS PARIS VAN JAVA KOTA BENGKULU).Volume 3, Nomor 6, Desember 2020;P-ISSN: 2655-755X, 2020.

[3] 
[4] 