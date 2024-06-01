# <h1 align="center">Laporan Praktikum Modul REKURSIF & HASH TABLE</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori
### 1. Rekursif
Rekursi adalah teknik dalam pemrograman dimana suatu method/fungsi memanggil dirinya sendiri. Fungsi ini akan terus berjalan sampai kondisi berhenti terpenuhi, oleh karena itu dalam sebuah fungsi rekursi perlu terdapat 2 blok penting, yaitu blok yang menjadi titik berhenti dari sebuah proses rekursi dan blok yang memanggil dirinya sendiri. Konsep ini dapat digunakan untuk merumuskan solusi sederhana dalam sebuah permasalahan yang sulit untuk diselesaikan secara iteratif dengan menggunakan loop for, while, do-while. Pada saat tertentu konsep ini dapat digunakan untuk mendefinisikan permasalahan dengan konsisten dan sederhana[1].
### 2. Hash Table
Hash Table adalah sebuah struktur data yang sangat cepat dalam insertion dan searching. Hash table diimplementasikan menggunakan array. Penambahan dan pencarian sebuah key pada hash table berdasarkan fungsi hash yang digunakan. Fungsi hash memetakkan elemen pada indek hash table. Fungsi hash yang baik memiliki sifat berikut: mudah dihitung, cukup mampu mendistribusikan key, meminimalkan jumlah collision (tabrakan) yang terjadi. Fungsi hash dapat menggunakan beberapa teknik, diantaranya:
a. Truncation. Mengambil beberapa digit dari key sebagai indeks
b. Folding. Menjumlahkan beberapa digit dari key, hasil penjumlahan sebagai indeks
c. Modular. Menggunakan sisa hasil bagi dari key (bilangan bulat) dengan ukuran hash table.
Berdasarkan teknik untuk menangani collision, hash table dapat dikategorikan menjadi: Closed Hashing (Open Addressing) dan Open hashing (Separate Chaining). Collision sendiri terjadi ketika terdapat dua key/lebih yang dipetakkan pada sebuah sel array yang sama[1].

## Guided 

### 1. 

```C++
// Guided 1
#include <iostream>
using namespace std;

// Fungsi ini melakukan hitung mundur dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan inputnya
    cout << endl;
    return 0;
}
```
Kode ini merupakan fungsi rekursif dengan menggunakan `countdown` bekerja untuk mencetak nilai dari 5 hingga 1 secara berurutan, menghentikan eksekusi saat nilai mencapai 0.

### 2. 

```C++
#include <iostream>
using namespace std;

void functionB (int n) ;
void functionA (int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1) ; //pemanggilan rekursif tidak langsung

    }
}

void functionB (int n) {
    if (n > 1) {
        cout << n << " ";
        functionA (n / 2); // pemanggilan rekursif tidak langsung

    }
}

int main () {
    int num = 5;
    cout << "Rekursif tidak langsung: ";
    functionA (num);
    return 0;
}

```
Kode di atas menunjukkan contoh pemrograman rekursif tidak langsung (indirect recursion). Rekursi tidak langsung terjadi ketika sebuah fungsi memanggil fungsi lain, yang pada gilirannya memanggil fungsi pertama, menciptakan siklus rekursi. Dalam guided 2 ini, functionA memanggil functionB, dan functionB memanggil functionA.

### 3.
```C++

// Guided 3
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hash_val += key[i];
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (size_t i = 0; i < table[hash_val].size(); ++i) {
            if (table[hash_val][i]->name == name) {
                table[hash_val][i]->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (size_t i = 0; i < table[hash_val].size(); ++i) {
            if (table[hash_val][i]->name == name) {
                delete table[hash_val][i]; // Free memory allocated for the node
                table[hash_val].erase(table[hash_val].begin() + i);
                return;
            }
        }
        cout << "Node with name '" << name << "' not found." << endl;
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (size_t i = 0; i < table[hash_val].size(); ++i) {
            if (table[hash_val][i]->name == name) {
                return table[hash_val][i]->phone_number;
            }
        }
        return "";
    }
    
    void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (table[i][j] != NULL) {
                    cout << "[" << table[i][j]->name << ", " << table[i][j]->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    cout << "Phone Hp Ghana : " << employee_map.searchByName("Ghana") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}

```
kode Pemrograman ini dibuat untuk mengimplementasikan struktur data tabel hash (hash table) yang digunakan untuk menyimpan dan mengelola informasi karyawan berdasarkan nama dan nomor telepon mereka. Tabel hash adalah struktur data yang memungkinkan penyimpanan dan pencarian data yang efisien menggunakan fungsi hash untuk memetakan kunci ke lokasi tertentu dalam tabel.



## Unguided 

### 1. 

```C++
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
```
#### Output:
![Screenshot 2024-06-01 113623](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/b26fd25d-dfb7-4362-80a7-560fc59008dc)



Pemrograman ini adalah contoh implementasi fungsi rekursif untuk menghitung `faktorial` dari suatu bilangan bulat positif. Faktorial dari suatu bilangan adalah hasil perkalian semua bilangan bulat positif yang lebih kecil dari atau sama dengan bilangan tersebut, dalam urutan yang menurun.
Misalnya, faktorial dari 5 adalah 5 * 4 * 3 * 2 * 1 = 120.
Pemrograman ini menggunakan fungsi rekursif `factorial` yang memanggil dirinya sendiri dengan argumen yang berkurang secara terus-menerus hingga mencapai basis case, yaitu `n == 0`. Basis case ini mengembalikan nilai 1, karena faktorial dari 0 adalah 1.


#### Full code Screenshot:
![Screenshot 2024-06-01 113239](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/f1b0dde7-4fe1-4ad4-b23c-6ecbcfff9531)




### 2. 

#### Class
```C++
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


```
#### Output:
![Screenshot 2024-06-01 113731](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/4513d916-093f-4250-994d-1b1d2f112366)


Pemrograman ini adalah contoh implementasi fungsi rekursif untuk menghitung faktorial dari suatu bilangan bulat positif. Faktorial dari suatu bilangan adalah hasil perkalian semua bilangan bulat positif yang lebih kecil dari atau sama dengan bilangan tersebut, dalam urutan yang menurun.
Perbedaan utama dengan kode unguided1 adalah bahwa kode ini menggunakan dua parameter dalam fungsi `factorial`, yaitu` n` dan `current`. Parameter `current` digunakan untuk menghitung `faktorial` dengan cara menghitung perkalian bilangan-bilangan dari `1 hingga n`.
Misalnya, jika pengguna memasukkan bilangan 5, fungsi factorial akan dipanggil dengan argumen n = 5 dan current = 1. Fungsi ini akan memanggil dirinya sendiri dengan argumen n = 5 dan `current` = 2, lalu n = 5 dan current = 3, dan seterusnya, hingga mencapai basis case current == n, yaitu `current` == 5. Basis case ini mengembalikan nilai 1, karena `faktorial` dari 5 adalah 1 * 2 * 3 * 4 * 5 = 120.

perbedaan lainnya yang jelas terlihat antara unguided 1 dan 2 adalah Dalam `rekursif langsung`, fungsi memanggil dirinya sendiri dengan `argumen yang sama`. sedangkan dalam uguided 2 dalam `rekursif tidak langsung`, fungsi memanggil dirinya sendiri dengan `argumen yang berbeda`.




#### Full code Screenshot:
![Screenshot 2024-06-01 113333](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/8b059a31-cd32-4ef0-9ca6-abbcf927ad6c)


### 3.
```C++
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string NIM;
    int nilai;
};

// Hash table untuk menyimpan data mahasiswa
unordered_map<string, Mahasiswa> hashTable;

// Fungsi untuk menambahkan data baru
void tambahData() {
    string NIM;
    int nilai;

    cout << "Masukkan NIM: ";
    cin >> NIM;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    hashTable[NIM] = {NIM, nilai};
    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus data
void hapusData() {
    string NIM;

    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> NIM;

    if (hashTable.find(NIM) != hashTable.end()) {
        hashTable.erase(NIM);
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencari data berdasarkan NIM
void cariDataNIM() {
    string NIM;

    cout << "Masukkan NIM yang akan dicari: ";
    cin >> NIM;

    if (hashTable.find(NIM) != hashTable.end()) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~<<>>~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Data ditemukan!" << endl;
        cout << "NIM: " << hashTable[NIM].NIM << endl;
        cout << "Nilai: " << hashTable[NIM].nilai << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~<<>>~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencari data berdasarkan rentang nilai (80 – 90)
void cariDataNilai() {
    int nilaiAwal = 80;
    int nilaiAkhir = 90;

    cout << "Data dengan nilai dalam rentang " << nilaiAwal << " - " << nilaiAkhir << ":" << endl;

    for (const auto& pair : hashTable) {
        if (pair.second.nilai >= nilaiAwal && pair.second.nilai <= nilaiAkhir) {
            cout << "NIM: " << pair.first << endl;
            cout << "Nilai: " << pair.second.nilai << endl;
        }
    }
}

int main() {
    int pilihan;

    while (true) {
        cout << "--------------/~ Menu ~/--------------" <<endl;
        cout << "1. Tambahkan data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Cari data berdasarkan NIM" << endl;
        cout << "4. Cari data berdasarkan rentang nilai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                cariDataNIM();
                break;
            case 4:
                cariDataNilai();
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid!. Silakan pilih lagi." << endl;
        }
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-06-01 113927](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/e5fa1d3c-8df1-41c4-a8b0-cffada844edb)


Pemrograman ini adalah contoh implementasi sistem manajemen data mahasiswa yang menggunakan hash table untuk menyimpan data dan beberapa fungsi untuk mengelola data tersebut. Sistem ini memungkinkan pengguna untuk menambahkan, menghapus, dan mencari data mahasiswa berdasarkan NIM atau rentang nilai.
Berikut adalah fungsi-fungsi yang tersedia dalam sistem ini:
1. Tambahkan Data: Fungsi `tambahData` memungkinkan pengguna untuk menambahkan data baru ke dalam hash table. Pengguna diminta untuk memasukkan NIM dan nilai mahasiswa, lalu data tersebut akan disimpan dalam hash table.
2. Hapus Data: Fungsi `hapusData` memungkinkan pengguna untuk menghapus data mahasiswa dari hash table. Pengguna diminta untuk memasukkan NIM mahasiswa yang akan dihapus, lalu data tersebut akan dihapus jika ditemukan.
3. Cari Data Berdasarkan NIM: Fungsi `cariDataNIM` memungkinkan pengguna untuk mencari data mahasiswa berdasarkan NIM. Pengguna diminta untuk memasukkan NIM mahasiswa yang akan dicari, lalu data tersebut akan ditampilkan jika ditemukan.
4. Cari Data Berdasarkan Rentang Nilai: Fungsi `cariDataNilai` memungkinkan pengguna untuk mencari data mahasiswa yang memiliki nilai dalam rentang tertentu (80-90). Sistem ini akan menampilkan data mahasiswa yang memiliki nilai dalam rentang tersebut.

Sistem ini menggunakan struktur data Mahasiswa untuk menyimpan data `mahasisw`a dan hash table `unordered_map` untuk menyimpan data dalam bentuk NIM-data. Sistem ini juga menggunakan switch-case untuk mengelola pilihan pengguna dan memanggil fungsi yang sesuai.
Dengan demikian, sistem ini dapat membantu dalam mengelola dan mencari data mahasiswa dengan lebih efektif dan efisien.


#### Full code Screenshot:
![Screenshot 2024-06-01 113450](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/fec58525-096d-4408-a77b-7e085f5c02e9)



## Kesimpulan
Pada modul 9 REKURSIF DAN HASH TABLE, saya memahami dan dapat mengimplementasikan konsep rekursif dan hash code dalam pemrograman.dan saya jadi bisa meningkatkan kemampuan dalam mengelola data dan algoritma dengan cara menggunakan rekursif dan hash code yang efektif dan efisien. dan juga saya belajar jenis-jenis rekursif serta kelebihan kekurangan dalam memakai nya.



## Referensi
[1] Khadijah Fahmi Hayati Holle, M.Kom, Struktur Data. UIN Malang, 2022. 

