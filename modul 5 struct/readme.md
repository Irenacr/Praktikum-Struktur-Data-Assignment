# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Irena Cahya Resinah</p>

## Dasar Teori

Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri. Variabel-variabel yang menjadi anggota struct disebut dengan elemen struct[1]

Dalam C++, Struct merupakan kata kunci. setiap anggota dari struct, meskipun diapit oleh sepasang kurung kurawal (yang membentukk sebuah blok), tidak di pandang sebagai sebuah statemen gabungan. jadi, sebuah semikoloni (yang berada setelah kuring kurawal kanan) sangat penting untuk mengakhiri statemen struct. semikoloni di akhir definisi struct merupakan bagian dari sintaks.[2].

Penggunaan/pemakaian tipe data struct dilakukan dengan membuat suatu variabel yang bertipe data struct tersebut. Pengaksesan elemen struct dilakukan secara individual dengan menyebutkan nama variabel struct diikuti dengan operator titik (.). Terdapat banyak format penulisan struct diantaranya :

### 1.
```
struct { 
    string namaDepan; 
    string namaBelakang;
    int usia;
    char jenis_kelamin;
}namaVariabelStrukA, namaVariabelStrukB 
```

### 2. 
```
struct namaTipe{
    string namaDepan;
    string namaTengah;
    string namaBelakang;
}; struct namaTipe namaVariabelStrukA, namaVariabelStrukB;
```

### 3. 
```
typedef struct {
    string namaDepan;
    string namaTengah;
    string namaBelakang;
}namaTipe;
namaTipe namaVariabelStrukA, namaVariabelStrukB
```

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>
#include <string>

using namespace std;

struct buku { 
    string judul_buku;
    string pengarang;
    string penerbit; 
    int tebal_halaman;
    int harga_buku; 

};

int main() {
    struct buku book, book2; 

    book.judul_buku = "The Great Gatsby"; 
    book.pengarang = "F. Scott Fitzgerald";
    book.penerbit = "Charles Scribner's Sons";
    book.tebal_halaman = 180;
    book.harga_buku = 250000;

    book2.judul_buku = "Death Comes for the Archbishop"; 
    book2.pengarang = "Willa Cather";
    book2.penerbit = "Alfred A. Knopf";
    book2.tebal_halaman = 297;
    book2.harga_buku = 300000;

    cout << "=====STRUCT I=====" << endl;
    cout << "Judul Buku: " << book.judul_buku << endl;
    cout << "Pengarang: " << book.pengarang << endl;
    cout << "Penerbit: " << book.penerbit << endl;
    cout << "Tebal Halaman: " << book.tebal_halaman << endl;
    cout << "Harga Buku: " << book.harga_buku << endl;

    cout << "\n=====STRUCT II=====" << endl;
    cout << "Judul Buku: " << book2.judul_buku << endl;
    cout << "Pengarang: " << book2.pengarang << endl;
    cout << "Penerbit: " << book2.penerbit << endl;
    cout << "Tebal Halaman: " << book2.tebal_halaman << endl;
    cout << "Harga Buku: " << book2.harga_buku << endl;

}
```
Kode di atas digunakan untuk mencetak struct `buku`. Pertama kita membuat dahulu struct `buku` yang berisi `judul_buku`, `pengarang`, `penerbit`, `tebal_halaman`, dan `harga_buku`. Lalu pada main program kita panggil struct `buku` tersebut lalu isikan dengan variabel yang sesuai. Lalu setelah diisi kita bisa menampilkan struct `buku` yang telah kita buat dan isikan.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.


```C++
#include <iostream>
#include <string>

using namespace std;

struct hewan { 
    string nama_hewan;
    string jenis_kelamin;
    string cara_berkembangbiak;
    string alat_pernapasan;
    string tempat_hidup;
    bool apakah_karnivora;   
};
hewan info_hewan;

struct hewan_darat { 
    int jumlah_kaki;
    bool apakah_menyusui; 
    string suara;
    hewan info_hewan;
};
hewan_darat hewan1;

struct hewan_laut {
    string bentuk_sirip;
    string bentuk_pertahanan;
    hewan info_hewan;
};
hewan_laut hewan2;

int main () {
    //struct hewan1, hewan2;

    hewan1.info_hewan.nama_hewan = "Kambing";
    hewan1.info_hewan.jenis_kelamin = "Jantan";
    hewan1.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan1.info_hewan.alat_pernapasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Darat";
    hewan1.info_hewan.apakah_karnivora = false;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "play";

    hewan2.info_hewan.nama_hewan = "Paus";
    hewan2.info_hewan.jenis_kelamin = "Betina";
    hewan2.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan2.info_hewan.alat_pernapasan = "Paru-paru";
    hewan2.info_hewan.tempat_hidup = "laut";
    hewan2.info_hewan.apakah_karnivora = false;
    hewan2.bentuk_sirip = "segitiga";
    hewan2.bentuk_pertahanan = "melawan";

    cout << "=====HEWAN DARAT=====" << endl;
    cout << "Nama Hewan :" << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin :" << hewan1.info_hewan.jenis_kelamin << endl;
    cout << "Cara Berkembangbiak :" << hewan1.info_hewan.cara_berkembangbiak << endl;
    cout << "ALat Pernapasan :" << hewan1.info_hewan.alat_pernapasan << endl;
    cout << "Tempat Hidup :" << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora :" << hewan1.info_hewan.apakah_karnivora << endl;
    cout << "Jumlah Kaki :" << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui :" << hewan1.apakah_menyusui << endl;
    cout << "Suara :" << hewan1.suara << endl;

    cout << "\n=====HEWAN LAUT=====" << endl;
    cout << "Nama Hewan :" << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin :" << hewan2.info_hewan.jenis_kelamin << endl;
    cout << "Cara Berkembangbiak :" << hewan2.info_hewan.cara_berkembangbiak << endl;
    cout << "ALat Pernapasan :" << hewan2.info_hewan.alat_pernapasan << endl;
    cout << "Tempat Hidup :" << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora :" << hewan2.info_hewan.apakah_karnivora << endl;
    cout << "Bentuk Sirip :" << hewan2.bentuk_sirip << endl;
    cout << "Bentuk Pertahanan :" << hewan2.bentuk_pertahanan << endl;
}
```
Kode di atas digunakan untuk mencetak struct `hewan`. Pertama kita buat dahulu struct `hewan` yang berisikan `nama_hewan`, `jenis_kelamin`, `cara_berkembangbiak`, `alat_pernapasan`, `tempat_hidup`, dan `apakah_karnivora`. Lalu kita membuat struct `hewan_darat` yang berisikan variable dari struct `hewan` dan ada `jumlah_kaki`, `apakah_menyusui`, dan `suara`. Kemudian kita membuat struct `hewan_laut` yang berisikan variable dari struct `hewan` dan ditambah `bentuk_sirip` dan `bentuk_pertahanan_diri`. Setelah selesai membuat struct kita bisa memanggil ketiga struct tersebut dan mengisikan data sesuai dengan variable. Setelah itu, kita bisa menampilkan hasil struct yang sudah kita isikan.

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan

```C++
#include <iostream>
#include <string>
using namespace std;

struct nama_buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() {
    // Membuat array dari struct nama_buku untuk menyimpan informasi 5 buku
    nama_buku daftar_buku[5];

    // Mengisi data untuk setiap buku dalam array
    daftar_buku[0] = {"Belajar Struktur Data", "Yanto", "Gramedia Pustaka Utama", 300, 150000};
    daftar_buku[1] = {"Algoritma Pemrograman", "Bambang", "Gramedia Pustaka Utama", 200, 120000};
    daftar_buku[2] = {"Pemrograman C++", "Budi", "Gramedia Pustaka Utama", 250, 125000};
    daftar_buku[3] = {"Dasar-Dasar Pemrograman", "Anisa", "Gramedia Pustaka Utama", 180, 100000};
    daftar_buku[4] = {"Aljabar Linear", "Citra", "Gramedia Pustaka Utama", 350, 180000};

    int pilihan;

    // Meminta pengguna untuk memilih buku yang ingin dilihat
    cout << "Pilih nomor buku yang ingin dilihat (1-5): ";
    cin >> pilihan;

    // Validasi input pengguna
    if (pilihan < 1 || pilihan > 5) {
        cout << "Input tidak valid. Harap pilih nomor buku antara 1 sampai 5." << endl;
        return 1; // Keluar dari program dengan kode error
    }

    // Menampilkan informasi dari buku yang dipilih
    cout << "Informasi Buku " << pilihan << ":" << endl;
    cout << "Judul Buku: " << daftar_buku[pilihan - 1].judul_buku << endl;
    cout << "Pengarang: " << daftar_buku[pilihan - 1].pengarang << endl;
    cout << "Penerbit: " << daftar_buku[pilihan - 1].penerbit << endl;
    cout << "Tebal Halaman: " << daftar_buku[pilihan - 1].tebal_halaman << " halaman" << endl;
    cout << "Harga Buku: Rp" << daftar_buku[pilihan - 1].harga_buku << endl;

    return 0;
}

```

Dalam program ini:

- saya menggunakan array `daftar_buku` untuk menyimpan informasi tentang 5 buku.
- Program meminta user untuk memilih nomor buku yang ingin dilihat dengan memasukkan angka dari 1 hingga 5.
- Input user (pilihan) kemudian divalidasi. Jika input tidak valid (di luar rentang angka 1-5), program akan memberikan pesan kesalahan dan keluar dengan kode error.
- Jika input valid, program akan menampilkan informasi dari buku yang dipilih berdasarkan nomor pilihan user.
- saya juga menggunakan akses ke array `daftar_buku` dilakukan dengan indeks pilihan - 1 karena array diindeks mulai dari 0.-

Dengan cara ini, program akan menampilkan informasi dari buku yang dipilih oleh user, sesuai dengan nomor yang dimasukkan. Jika ingin melihat buku lain, user dapat menjalankan program lagi dan memilih nomor buku yang yang lain.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```C++
#include <iostream>
#include <string>
using namespace std;

struct nama_buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() {
    const int max_buku = 5; // Batas maksimum jumlah buku yang bisa dimasukkan
    nama_buku daftar_buku[max_buku];
    int jumlah_buku = 0; // Jumlah buku yang telah dimasukkan

    char lanjut_input;
    do {
        if (jumlah_buku >= max_buku) {
            cout << "Batas maksimum jumlah buku telah tercapai." << endl;
            break;
        }

        cout << "Masukkan data untuk Buku " << jumlah_buku + 1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin >> ws, daftar_buku[jumlah_buku].judul_buku); // Menggunakan getline untuk membaca seluruh baris termasuk spasi
        cout << "Pengarang: ";
        getline(cin >> ws, daftar_buku[jumlah_buku].pengarang);
        cout << "Penerbit: ";
        getline(cin >> ws, daftar_buku[jumlah_buku].penerbit);
        cout << "Tebal Halaman: ";
        cin >> daftar_buku[jumlah_buku].tebal_halaman;
        cout << "Harga Buku: Rp";
        cin >> daftar_buku[jumlah_buku].harga_buku;
        cout << endl;

        ++jumlah_buku;

        if (jumlah_buku < max_buku) {
            cout << "Apakah ingin memasukkan buku lagi? (y/n): ";
            cin >> lanjut_input;
            cin.ignore(); // Membersihkan buffer agar getline berikutnya berfungsi dengan baik
        } else {
            cout << "Batas maksimum jumlah buku telah tercapai." << endl;
            break;
        }
    } while (lanjut_input == 'y' || lanjut_input == 'Y');

    // Menampilkan informasi dari setiap buku dalam array
    cout << "Daftar Buku:" << endl;
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Buku " << i + 1 << ":" << endl;
        cout << "Judul Buku: " << daftar_buku[i].judul_buku << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Penerbit: " << daftar_buku[i].penerbit << endl;
        cout << "Tebal Halaman: " << daftar_buku[i].tebal_halaman << " halaman" << endl;
        cout << "Harga Buku: Rp" << daftar_buku[i].harga_buku << endl;
        cout << endl;
    }

    return 0;
}

```

Kode di atas digunakan untuk mencetak teks struct `buku`. Pertama kita membuat dahulu struct `buku` yang berisi `judul_buku`, `pengarang`, `penerbit`, `tebal_halaman`, dan `harga_buku`. Lalu pada main program kita menambahkan ukuran `[5]` pada variable memanggil struct supaya panjang struct menjadi 5 tanpa perlu membuat variable dan dibuat berjenis array. Lalu kita membuat looping yang berguna untuk menginputkan informasi buku sehingga kita tidak perlu mengcopy struct sampai 5 kali. Lalu setelah membuat looping untuk menginputkan kita perlu membuat looping untuk menampilkan setiap daftar buku yang sudah kita inputkan.

cara mengisi dan menampilkannya:
#### 1. Mengisi Data Buku:
- Program akan meminta user untuk memasukkan data buku.
- Data yang diminta mencakup `judul buku`, `pengarang`, `penerbit`, `tebal halaman`, dan `harga buku`.
- User akan diminta memasukkan data buku secara berurutan.
- Setiap kali User memasukkan data buku, program akan menambahkan buku baru ke dalam array `daftar_buku`.
- User dapat memilih untuk terus memasukkan buku baru jika masih ada slot kosong dalam array `daftar_buku`.
- User dapat memilih ingin berhenti atau melanjukan untuk menginputkan data buku

#### 2. Menampilkan Data Buku:
- Setelah user selesai memasukkan data buku atau jika batas maksimum jumlah buku telah tercapai, program akan menampilkan daftar buku yang telah dimasukkan.
- Program akan mencetak informasi setiap buku yang telah dimasukkan oleh user, termasuk `judul buku`, `pengarang`, `penerbit`, `tebal halaman`, dan `harga buku`.
- Informasi setiap buku akan ditampilkan dalam format yang terstruktur.

Dalam kode ini:

- saya mendefinisikan sebuah array `daftar_buku` dari struct `nama_buku` dengan ukuran yang ditentukan (`jumlah_buku`).
- Menggunakan loop for untuk mengisi data untuk setiap buku dalam array. Setiap kali loop berjalan, program akan meminta user untuk memasukkan informasi buku.
- Untuk membaca `judul`, `pengarang`, dan `penerbit buku` (yang mungkin mengandung spasi), saya menggunakan `getline`(cin >> ws, variable) untuk membaca seluruh baris termasuk spasi.
- Setelah mengisi data untuk semua buku, program akan menampilkan informasi dari setiap buku dalam array menggunakan loop for.

Dengan cara ini, saya dapat mengelola beberapa buku dalam array `daftar_buku`, mengisi data buku, dan menampilkan informasi dari setiap buku dalam array sesuai dengan kebutuhan. Jumlah buku yang ingin disimpan dapat disesuaikan dengan mengubah nilai `jumlah_buku`.

#### 3. perbedaan dengan guided 1
Perbedaan utama antara kode yang baru dan kode sebelumnya terletak pada cara kita mengelola data buku:

##### Penggunaan Array:
- Kode Awal: Pada kode awal, saya hanya mendeklarasikan dua variabel `nama_buku` (buku1 dan buku2). Setiap variabel tersebut hanya dapat menyimpan data untuk satu buku saja.
- Kode Baru: Pada kode baru, kita menggunakan array daftar_buku dari struct nama_buku untuk menyimpan beberapa buku. Hal ini memungkinkan kita untuk menyimpan dan mengelola data untuk lebih dari satu buku dalam satu program.
##### Input Data Buku:
- Kode Awal: Pada kode awal, data buku diisi secara langsung ke setiap variabel buku1 dan buku2.
- Kode Baru: Pada kode baru, data buku diisi menggunakan loop for. Pengguna diminta untuk memasukkan data untuk setiap buku, dan data tersebut disimpan dalam array daftar_buku.
##### Menampilkan Informasi Buku:
- Kode Awal: Pada kode awal, kita menampilkan informasi dari setiap buku secara terpisah untuk buku1 dan buku2.
- Kode Baru: Pada kode baru, setelah data buku diisi dan disimpan dalam array, kita menggunakan loop for untuk menampilkan informasi dari setiap buku yang tersimpan dalam array daftar_buku. Hal ini memungkinkan kita untuk menampilkan informasi dari semua buku yang telah dimasukkan.

Kode baru lebih fleksibel karena menggunakan array untuk menyimpan data buku. Dengan menggunakan array, kita dapat dengan mudah menambah atau mengurangi jumlah buku yang ingin dimasukkan ke dalam program tanpa perlu mengubah struktur kode secara signifikan. Hal ini membuat kode lebih modular dan dapat diadaptasi untuk menangani sejumlah buku yang berbeda.
Jadi, dengan menggunakan array dari struct `nama_buku`, kita dapat mengelola data buku secara lebih efisien dan fleksibel, terutama jika kita perlu bekerja dengan banyak buku dalam satu program. Kode yang baru memungkinkan kita untuk mengisi, menyimpan, dan menampilkan informasi dari sejumlah buku yang lebih besar daripada yang dapat diakomodasi oleh variabel tunggal.



## Kesimpulan
Kesimpulan pada guided kita belajar mengenai struct yang merupakan tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Penggunaan/pemakaian tipe data struct dilakukan dengan membuat suatu variabel yang bertipe data struct tersebut. Pengaksesan elemen struct dilakukan secara individual dengan menyebutkan nama variabel struct diikuti dengan operator titik (.). Terdapat 3 contoh cara penggunaan struct diatas.

Kemudian, untuk unguided kita belajar mengenai memodifikasi kode pada guided, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, mengisi dengan data kemudian menampilkan dan mengubah deklarasi variable struct menjadi berjenis array. dan saya juga belajar adanya perbedaan dan perubahan pada setiap kode itu memiliki manfaat dan kegunaan yang berbeda-beda.

## Referensi
[1]Hariyanto, Bambang, 2000, Struktur Data, Bandung.
[2]Edy Satrio, Simon Pakpahan, Pemrograman C++ Untuk Pembelajaran Mandiri, Cahaya informatika, 2019.