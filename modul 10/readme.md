# <h1 align="center">Laporan Praktikum Modul GRAPH DAN TREE</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### 1. TREE
Tree dapat diimplementasikan dengan menyimpan node pada memori sebagai sebuah array. Atau, tree juga dapat diimplementasikan dengan menyimpan node pada memori dan menghubungkannya menggunakan references pada tiap node yang menunjuk pada children node tersebut. Berikut ini beberapa class yang perlu implementasikan dalam membuat program binary tree.
a. Class Node
Class Node sebagai objek yang merepresentasikan data objek yang akan disimpan dan juga memuat reference ke masing-masing dua children
b. Class Tree
Class Tree merepresentasikan objek tree itu sendiri, yaitu sebuah objek yang menangani semua node. Pada class Tree, hanya ada 1 field, yaitu variable node dengan nama root. Node lain diakses melalui root sehingga tidak diperlukan adanya field lain.Terdapat beberapa method pada class Tree, yaitu method untuk pencarian (find), menambahkan node (insert), menghapus node (delete), serta method yang menangani berbagai macam travers, dan untuk menampilkan tree (display).
c. Class TreeApp
Class TreeApp berisi method main untuk menjalankan program. Pada listing program berikut, method main menyediakan sebuah primitive user interfacesehingga user dapat menentukan aksi dari input keyboard, apakah ingin insert, find, delete, show, atau travers[1].
### 2. GRAPH
Graph adalah struktur data yang hampir menyerupai tree. Graph terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai:
G = (V, E)
dimana G adalah Graph, V adalah simpul atau vertex (jamaknya vertices) atau node atau titik, dan E adalah busur atau edge atau arc.  Graph dapat digunakan untuk merepresentasikan jaringan, peta (mencari jalur terpendek), penjadwalan (perencanaan proyek), dll[1].

## Guided 

### 1. GRAPH

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis",
                    "Bandunng",
                    "Bekasi",
                    "Tasikmalaya",
                    "Cianjur",
                    "Purwokerto",
                    "Yogyakarta"};

int busur [7] [7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 8, 0},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};
 void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++){
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";

        }
        cout << endl;
    }
 }

 int main() {
    tampilGraph();
    return 0;
 }


```
Kode ini dibuat untuk merepresentasikan dan menampilkan graf berbobot yang merepresentasikan hubungan antar kota di Jawa Barat dan Jawa Tengah. Graf berbobot adalah struktur data yang terdiri dari simpul (nodes atau vertices) dan busur (edges) dengan bobot yang terkait.

### 2. TREE

```C++
#include <iostream>
using namespace std;

//definisi struct pohon
struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

//deklarasi variabel global 
pohon * simpul;
pohon * root;
pohon * saatini;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

//fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

//fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul -> data = dataMasukkan;
    simpul -> kanan = NULL;
    simpul -> kiri = NULL;
}

//fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "silahkan masukan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "root terbentuk..." << endl;
    } else {
        cout << "root sudah ada..." << endl;
    }
}
// fungsi untuk menambah simpul 
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatini = alamat[i];
                saatini -> kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatini = alamat[i];
                    saatini -> kanan = simpul;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

//fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatini = alamat[i];
            cout << saatini -> data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n*2;
            }
            i++;
        }
    }
}

//fungsi utama
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}

```
Kode ini dibuat untuk merepresentasikan dan mengelola sebuah pohon biner dengan menggunakan struktur data dan fungsi dalam bahasa pemrograman C++. Pohon biner adalah struktur data yang terdiri dari simpul-simpul, di mana setiap simpul memiliki maksimal dua anak.


## Unguided 

### 1. 
#### GRAPH

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display menu
void showMenu_2311110066_IRENA_CAHYA_RESINAH() {
    int numSimpul;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> numSimpul;

    vector<string> simpul;
    for (int i = 1; i <= numSimpul; i++) {
        string namaSimpul;
        cout << "Simpul " << i << ": ";
        cin >> namaSimpul;
        simpul.push_back(namaSimpul);
    }

    // Input bobot antar simpul
    vector<vector<int>> bobot(numSimpul, vector<int>(numSimpul));
    for (int i = 0; i < numSimpul; i++) {
        for (int j = 0; j < numSimpul; j++) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    // Display table
    cout << " ";
    for (const string& s : simpul) {
        cout << s << " ";
    }
    cout << endl;
    for (int i = 0; i < numSimpul; i++) {
        cout << simpul[i];
        for (int j = 0; j < numSimpul; j++) {
            cout << " " << bobot[i][j];
        }
        cout << endl;
    }

    
}

int main() {
    showMenu_2311110066_IRENA_CAHYA_RESINAH();
    return 0;
}

```


#### Output:
![Screenshot 2024-06-07 193538](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/11253fce-3c54-4984-a007-6600c45dc91f)


Kode ini dibuat untuk merepresentasikan sebuah graf dengan simpul-simpul dan bobot-bobot di antara mereka dalam bentuk tabel.
##### Tujuan Kode
1. Meminta pengguna untuk memasukkan jumlah simpul dalam graf:
2. Mengumpulkan nama simpul dari pengguna
Pengguna diminta memasukkan nama-nama untuk setiap simpul. Nama-nama ini disimpan dalam sebuah vector bernama `simpul`.
3. Meminta pengguna untuk memasukkan bobot antar simpul:
Pengguna diminta memasukkan bobot (nilai integer) untuk setiap pasangan simpul. Nilai-nilai ini disimpan dalam sebuah matriks dua dimensi bernama `bobot`, yang merepresentasikan graf berarah (directed graph) atau tidak berarah (undirected graph) tergantung pada bobot yang diisi pengguna.
Menampilkan tabel adjacency dari graf:
Kode ini menampilkan tabel yang menunjukkan bobot antara setiap pasangan simpul dalam bentuk matriks adjacency. Matriks ini digunakan untuk merepresentasikan bobot antar simpul di dalam graf.
##### Fungsi Kode
showMenu():
Fungsi ini mengumpulkan data dari pengguna tentang `jumlah simpul`, `nama simpul`, dan bobot antara simpul.
Fungsi ini kemudian menampilkan tabel adjacency dari graf berdasarkan input pengguna.



#### Full code Screenshot:
![Screenshot 2024-06-07 200129](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/1793d83f-7c96-47c0-9807-64e88359b352)



### 2. 

#### TREE
```C++
#include <iostream>
using namespace std;

// Definisi struct pohon
struct pohon {
    pohon *kanan;
    char data;
    pohon *kiri;
};

// Deklarasi variabel global
pohon *simpul;
pohon *root;
pohon *saatini;
pohon *helperA;
pohon *helperB;
pohon *alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
    for (int i = 0; i < 256; i++) {
        alamat[i] = NULL;
    }
}

// Fungsi untuk membuat simpul baru
void simpulBaru_2311110066_IRENA_CAHYA_RESINAH(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// Fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silakan masukan data akar: ";
        cin >> dataAnda;
        simpulBaru_2311110066_IRENA_CAHYA_RESINAH(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1;
        char dataUser;
        alamat[i] = root;

        while (i < 256 && alamat[i] != NULL) {
            cout << "Masukkan data kiri dari " << alamat[i]->data << " (masukkan '0' jika tidak ada): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru_2311110066_IRENA_CAHYA_RESINAH(dataUser);
                alamat[i]->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                alamat[i]->kiri = NULL;
            }

            cout << "Masukkan data kanan dari " << alamat[i]->data << " (masukkan '0' jika tidak ada): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru_2311110066_IRENA_CAHYA_RESINAH(dataUser);
                alamat[i]->kanan = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                alamat[i]->kanan = NULL;
            }

            i++;
        }
    }
}

// Fungsi untuk membaca pohon pre-order
void bacaPreOrder(pohon *node) {
    if (node != NULL) {
        cout << node->data << " ";
        bacaPreOrder(node->kiri);
        bacaPreOrder(node->kanan);
    }
}

// Fungsi untuk membaca pohon in-order
void bacaInOrder(pohon *node) {
    if (node != NULL) {
        bacaInOrder(node->kiri);
        cout << node->data << " ";
        bacaInOrder(node->kanan);
    }
}

// Fungsi untuk membaca pohon post-order
void bacaPostOrder(pohon *node) {
    if (node != NULL) {
        bacaPostOrder(node->kiri);
        bacaPostOrder(node->kanan);
        cout << node->data << " ";
    }
}

// Fungsi utama
int main() {
    inisialisasi();
    int pilihan;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Membuat simpul akar" << endl;
        cout << "2. Menambah simpul" << endl;
        cout << "3. Membaca pohon pre-order" << endl;
        cout << "4. Membaca pohon in-order" << endl;
        cout << "5. Membaca pohon post-order" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                simpulAkar();
                break;
            case 2:
                tambahSimpul();
                break;
            case 3:
                cout << "Pre-order: ";
                bacaPreOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "In-order: ";
                bacaInOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Post-order: ";
                bacaPostOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 6);

    return 0;
}


```


Kode ini dibuat untuk mengimplementasikan operasi dasar pada pohon biner (binary tree) 
##### isi kode
1. Menginisialisasi pohon dengan simpul akar (root node) dan menyediakan fungsi untuk menambah simpul baru ke pohon.
2. meminta pengguna untuk menambah simpul ke pohon secara interaktif.
3. Menyediakan fungsi untuk membaca (traverse) pohon dalam urutan pre-order, in-order, dan post-order.
intinya:
Kode ini dapat digunakan untuk memahami dasar-dasar biner tree dan cara operasi dasar seperti penambahan simpul dan traversal pohon dilakukan. Ini bisa mdi gunakan pada proyek yang lebih besar yang membutuhkan manajemen struktur data pohon, seperti dalam aplikasi database, pencarian, atau kompresi data.

#### Full code Screenshot:
![Screenshot 2024-06-07 200240](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/441966a8-e055-403c-b4fa-6bc0978cc52f)




## Kesimpulan
Pada modul 3 GRAPH AND TREE, saya memahami perbedaan konsep GRAPH dan TREE, dan saya juga amenyadari bahwa kedua kode tersebut memiliki kesamaan yaitu menggunakan `node` dan juga sama-sama memiliki fungsi saling menghubungkan. jika graph menghubungkan antara `simpul` ke `simpul`, maka tree menghubungkan antara `parent` ke `child`. dan saya juga jadi mengetahui lebih banyak tetang tree dan graph serta jenis-jenisnya.


## Referensi
[1] Khadijah Fahmi Hayati Holle, M.Kom, Struktur Data. UIN Malang, 2022. 

