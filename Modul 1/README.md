# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Tipe data adalah sekumpulan nilai yang dapat digunakan dalam pemrograman. Tipe data dapat dikelompokkan menjadi tipe data primitif, tipe data abstrak (objek), dan tipe data koleksi.

### 1. Tipe Data Primitif
Tipe data primitif adalah tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel. Dalam C++, terdapat 7 tipe data yang termasuk tipe data primitif, yaitu: int, float, double, boolean, char, void dan wide_character. Contoh tipe data primitif adalah[1] :
- Int adalah tipe data yang digunakan untuk menyimpan bilangan bulat seperti 12, 1, 4, dan sebagainya[1].
- Float adalah tipe data yang digunakan untuk menyimpan bilangan desimal seperti 1.5, 2.1, 3.14, dan sebagainya[1].
- Char berfungsi untuk menyimpan data berupa sebuah huruf. Biasanya digunakan untuk simbol seperti A, B, C dan seterusnya[1].
- Bool tipe data ini digunakan untuk menyimpan nilai boolean yang hanya memiliki dua nilai yaitu true dan false[1].

### 2. Tipe Data Abstrak
Tipe data ini lebih fokus pada operasi yang dapat dilakukan terhadap data dan aturan tentang bagaimana data tersebut diakses daripada representasi data tersebut di memori. Tipe data abstrak dapat memiliki properti dan metode[2].

### 3. Tipe Data Koleksi
Tipe data koleksi adalah tipe data yang berisi sekumpulan elemen. Tipe data koleksi dapat dikelompokkan menjadi tipe data koleksi statis dan tipe data koleksi dinamis. Contoh tipe data koleksi adalah array, list, dan map
[2]. Ada beberapa tipe data koleksi yang umum digunakan dalam pemrograman, dan di antaranya adalah:
- Array adalah struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditentukan saat deklarasi.
- Vector adalah Standard Template Library (STL) jika di dalam C/C++ memiliki bentuk std::vector . Umumnya, vector mirip seperti array yang memiliki kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan. Kemampuan vector bukan hanya pada jumlah elemen yang dinamis, vector pada C/C++ juga dilengkapi dengan fitur-fitur pelengkap seperti element access, iterators, capacity, modifiers
- Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. Pada map, indeks tersebut diberi nama “key”. Pada std::map digunakan Self-Balancing Tree khususnya Red-Black Tree.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>

using namespace std;

// Main program
int main() 
{
    char op;
    float num1, num2;

    //It allows user to enter operator i.e. +, -, *, /
    cout << "Enter a Operator: " << endl;
    cin >> op;

    //It allows user to enter the operations
    cout << "Enter Number 1 & 2: " << endl;
    cin >> num1 >> num2;

    //Switch statement begins
    switch (op)
    {
    //If user enter +
    case '+':
        cout << num1 + num2;
        break;

    //If user enter -
    case '-':
        cout << num1 - num2;
        break;

    //If user enter *
    case '*':
        cout << num1 * num2;
        break;

    //If user enter /
    case '/':
        cout << num1 / num2;
        break;

    //If the operatior is other that +, -, * or /,
    //error message will display
    default:
        cout << "Error! operator is not correct";
    }//switch statement ends
    return 0;
}
```
Kode diatas merupakan program untuk menampilkan aritmatika dasar (penjumlahan, pengurangan, perkalian, dan pembagian) untuk dua bilangan. Pada awal program user diminta untuk menginputkan operator yang akan dipilih untuk melakukan operasi aritmatika dasar. Setelah menginputkan operator, user diminta untuk menginputkan angka pertama dan angka kedua. Lalu program akan menjalankannya sesuai dengan inputan dari user. Program ini menggunakan `switch-case` untuk menjalankan operasinya. Kemudian jika user menginputkan tidak sesuai dengan operator yang sudah ditentukan, maka program akan menampilkan pesan error.

### 2. Tipe Data Abstrak

```C++
#include <iostream>
using namespace std;

//struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    //mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    //mencetak isi struct
    cout << "-----Mahasiswa 1-----" << endl;
    cout << "Nama: " << mhs1.name <<endl;
    cout << "Alamat: " << mhs1.address <<endl;
    cout << "Umur: " << mhs1.age <<endl;
    cout << "-----Mahasiswa 2-----" << endl;
    cout << "Nama: " << mhs2.name <<endl;
    cout << "Alamat: " << mhs2.address <<endl;
    cout << "Umur: " << mhs2.age <<endl;

    return 0;
}
```
Kode diatas merupakan contoh program yang menggunakan tipe data abstrak, yaitu struct. Program diatas menggunakan struct `Mahasiswa` yang memuat tiga nilai yaitu `name` dan `address` yang sama-sama bertipe data character, dan ada `age` yang bertipe data integer. Lalu terdapat `const` pada nilai `name` dan `address` yang berfungsi supaya object atau variabel tidak dapat dimodifikasi. Setelah itu kita bisa mengisi data dengan membuat dua variabel yang bertipe data struct `Mahasiswa`, yaitu `mhs1` dan `mhs2`. Setelah itu kita tinggal mengisi data tersebut ke masing-masing variabel dan menampilkannya menggunakan fungsi `cout`.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;

int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
}
```
Kode diatas adalah contoh program yang menggunakan tipe data koleksi. Pertama kita mendeklarasikan dan menginialiasikan array `nilai` yang mempunyai tipe data integer. Untuk `[5]` adalah merupakan ukuran panjang array yang akan kita gunakan. Lalu kita bisa mengisikan data ke dalam variabel `nilai`, seperti `nilai[0]` atau elemen pertama dalam array kita isi dengan angka 23, lalu untuk elemen ke dua kita isi dengan angka 50, untuk elemen ketiga kita isi dengan angka 34, untuk elemen keempat kita isi dengan angka 78, dan elemen ke lima kita isi dengan angka 90. Setelah kita selesai mengisikan nilai ke setiap elemen dalam array kita bisa menampilkan setiap nilai dalam array menggunakan fungsi `cout`.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>

using namespace std;

int main()
{
    int angka; //Variabel untuk menyimpan input angka
    string kata;  //Variabel untuk menyimpan input kata
    char karakter; //Variabel untuk menyimpan input karakter

    //Meminta pengguna untuk memasukkan angka dan menyimpannya ke variabel angka
    cout << "input angka : " << endl;
    cin >> angka;
    //Meminta pengguna untuk memasukkan angka dan menyimpannya ke variabel kata
    cout << "inputkan kata: " << endl;
    cin >> kata;
//Meminta pengguna untuk memasukkan angka dan menyimpannya ke variabel karakter
    cout << "inputkan karakter: " << endl;
    cin >> karakter;


    //menampilkan data yang di input
    cout << "data yang anda inputkan adalah: " << endl;
    cout << "kata: " << kata << endl; //Menampilkan nilai dari variabel kata
    cout << "angka: " << angka << endl; //Menampilkan nilai dari variabel angka
    cout << "karakter: " << karakter << endl; //Menampilkan nilai dari variabel karakter

    return 0;
}
```
#### Output:
![Screenshot 2024-03-21 211955](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/cdc0014e-ab17-4fbc-9970-63f96cb88d09)


Program ini untuk menginput angka(int), kata(string), dan karaker(char).
Kesimpulan: program ini menggunakan tipe data primitif seperti ‘int’ dan ‘char’ untuk menyimpan angka dan karakter, dan tipe data ‘string’, walaupun string bukang termasuk tipe data primitif, tetapi tipe data ‘string’ ini umum di gunakan. Pada program yang saya buat,  
-	saya menggunakan ‘int’ untuk menyimpan angka(dalam bentuk bilangan bulat)
-	menggunakan ‘char’ unutk menyimpan sebuah karakter
-	dan ‘string' untuk menyimpan kata


#### Full code Screenshot:
![Screenshot 2024-03-21 213424](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/7b3223df-0e00-4b76-8ee3-47609ecb01c4)



### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

#### Class
```C++
#include <iostream>
using namespace std;

// Deklarasi kelas Mahasiswa
class Mahasiswa {
private:
    string nama;
    int nilai;

public:
    // Konstruktor untuk inisialisasi objek Mahasiswa
    Mahasiswa(string n, int ni) {
        nama = n;
        nilai = ni;
    }

    // Metode untuk menampilkan data mahasiswa
    void display() {
        cout << "Nama   : " << nama << endl;
        cout << "Nilai  : " << nilai << endl;
        cout << "Status : " << (lulus() ? "LULUS" : "TIDAK LULUS") << endl;
    }

private:
    // Metode untuk menentukan status kelulusan
    bool lulus() {
        return nilai > 75;
    }
};

int main() {
    string nama;
    int nilai;

    cout << "Masukkan nama    : ";
    getline(cin, nama);
    cout << "Masukkan nilai   : ";
    cin >> nilai;

    // Membuat objek Mahasiswa menggunakan konstruktor
    Mahasiswa mhs(nama, nilai);

    cout << endl;

    // Memanggil metode untuk menampilkan data mahasiswa
    mhs.display();

    return 0;
}

```

#### Struct
```C++
#include <iostream>
using namespace std;

// Deklarasi struct Mahasiswa
struct Mahasiswa {
    // Atribut
    string nama;
    int nilai;

    // Konstruktor untuk inisialisasi objek Mahasiswa
    Mahasiswa(string n, int ni) {
        nama = n;
        nilai = ni;
    }

    // Metode untuk menampilkan data mahasiswa
    void display() {
        cout << "Nama   : " << nama << endl;
        cout << "Nilai  : " << nilai << endl;
        cout << "Status : " << (lulus() ? "LULUS" : "TIDAK LULUS") << endl;
    }

private:
    // Metode untuk menentukan status kelulusan
    bool lulus() {
        return nilai > 75;
    }
};

int main() {
    string nama;
    int nilai;

    cout << "Masukkan nama    : ";
    getline(cin, nama);
    cout << "Masukkan nilai   : ";
    cin >> nilai;

    // Membuat objek Mahasiswa menggunakan konstruktor
    Mahasiswa mhs(nama, nilai);

    cout << endl;

    // Memanggil metode untuk menampilkan data mahasiswa
    mhs.display();

    return 0;
}

```
#### Output:
![Screenshot 2024-03-21 212043](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/6e2b0083-4a6b-4799-b794-aa089ee44026)

Fungsi dari struct dan class dalam pemrograman adalah sebagai berikut:

Struct dan class dalam C++ adalah konstruksi yang digunakan untuk mengelompokkan data dan fungsi dalam satu unit yang dapat diakses dengan mudah. Kedua konstruksi identik dalam C++ kecuali bahwa dalam struct aksesibilitas default adalah publik, sedangkan di class default bersifat privat[3]

- Struct: Struct adalah tipe data yang didefinisikan oleh pemrograman Golang. Dia merupakan kumpulan definisi variabel (atau property) dan atau fungsi (atau method), yang dibungkus sebagai tipe data baru dengan nama tertentu. Property dalam struct, tipe datanya bisa bervariasi. Mirip seperti map, hanya saja key-nya sudah didefinisikan di awal, dan tipe data tiap itemnya bisa berbeda. Dari sebuah struct, kita bisa buat variabel baru, yang memiliki atribut sesuai skema struct tersebut. Kita seperatikan variabel tersebut dipanggil dengan istilah object atau object struct. Konsep struct di golang mirip dengan konsep class pada OOP, meski sebenarnya berbeda. Di sini penulis menggunakan konsep OOP sebagai analogi, dengan tujuan untuk mempermudah dalam mencerna isi chapter ini. Dengan memanfaatkan struct, grouping data akan lebih mudah, selain itu rapi dan gampang untuk di-maintain.


- Class: Class adalah konstruksi yang digunakan dalam pemrograman untuk menentukan jenis data sendiri. Class dan struct adalah konstruksi yang sama, tetapi class memiliki lebih banyak kemampuan, seperti memuat method, inheritance, dan lain-lain. Class adalah fitur OOP pada C++ yang mirip seperti fitur Data Structures struct pada C, keduanya dapat menampung variabel sebagai anggota. Tapi perbedaan dari class dan struct tersebut adalah pada Class memiliki kemampuan lebih, seperti dimungkinkan untuk memuat method, inheritance dan lain-lain[1]. Class dan Object merupakan fitur yang sangat membantu untuk mendirikan sebuah program besar, menjadikan sebuah code program yang ditulis oleh programmer lebih mudah dibaca dan diperbaiki.
Kedua konstruksi, struct dan class, memiliki tujuan yang sama, yaitu untuk mengumpulkan data dan fungsi dalam satu unit yang dapat diakses dengan mudah. Namun, struct lebih sederhana dan digunakan untuk mengumpulkan data, sedangkan class lebih kompleks dan digunakan untuk mengumpulkan data dan fungsi.


#### Full code Screenshot:
![Screenshot 2024-03-21 213115](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/b7d273d0-7ff0-4323-96d5-7f35415fbb48)


### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

```C++
#include <iostream>
#include <map>

using namespace std;

int main() {
    // Membuat map yang menampung NIM (key) dan nama mahasiswa (value)
    map<int, string> daftarMahasiswa;

    // Menambahkan data mahasiswa ke dalam map
    daftarMahasiswa[23112233] = "Asep";
    daftarMahasiswa[23112244] = "Jarwo";
    daftarMahasiswa[23112255] = "Siti";
    daftarMahasiswa[23112266] = "Selly";

    // Menampilkan daftar mahasiswa
    cout << "Daftar Mahasiswa:" << endl;
    for (const auto& pair : daftarMahasiswa) {
        cout << "NIM: " << pair.first << ", Nama: " << pair.second << endl;
    }

    // Mengakses data mahasiswa berdasarkan NIM
    int nimCari;
    cout << "Masukkan NIM: ";
    cin >> nimCari;

    // Memeriksa apakah NIM ditemukan dalam map
    auto it = daftarMahasiswa.find(nimCari);
    if (it != daftarMahasiswa.end()) {
        cout << "Nama mahasiswa dengan NIM " << nimCari << " adalah " << it->second << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-03-21 212215](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/0c52d620-5ccc-482d-bc5d-95006ddc2943)


Program ini menyediakan fungsionalitas sederhana untuk menyimpan dan mencari data mahasiswa berdasarkan NIM. Manfaat/kegunaan program: pengguna dapat melihat daftar mahasiswa yang telah disimpan dan mencari nama mahasiswa berdasarkan NIM tertentu. Ini adalah contoh penggunaan praktis dari map dalam pemrograman C++.
Perbedaan antara array dan map adalah sebagai berikut:
- Array: Array adalah sekumpulan elemen yang dapat berisi nilai yang sama atau berbeda. Setiap elemen dalam array memiliki posisi tetap, yang dimana saat kita gunakan array tersebut dengan mengakses objek menurut indeksnya[4]. Array dapat digunakan untuk menyimpan lebih dari satu nilai atau banyak nilai dalam variable[4].

- Map: Map adalah sekumpulan elemen yang dapat berisi kunci-nilai. Setiap kunci dalam map memiliki nilai yang unik, yang dimana saat kita gunakan map tersebut dengan mengakses objek menurut kunci yang disediakan[4]. Map dapat digunakan untuk menyimpan kumpulan data yang dapat diakses dengan mudah dan dapat diubah secara dinamis[4].


#### Full code Screenshot:
![Screenshot 2024-03-21 213235](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/81473268-7069-41f6-8b94-6f23c368cd0e)


## Kesimpulan
Pada modul 1 guided ini kita belajar mengenai tipe data yang ada pada bahasa C++. Ada 3 tipe data yang ada yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi. Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem. Untuk tipe data abstrak merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data, dan yang terakhir tipe data koleksi adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan.

Kemudian untuk modul 1 unguided kita belajar mengenai membuat program menggunakan tipe data primitif minimal dua fungsi, membuat program yang menggunakan fungsi class dan struct, dan yang terakhir membuat program yang menggunakan fungsi map.

## Referensi
[1] Martini Mulyo SYahidin, Mengenal Jenis-Jenis Tipe Data Dalam C++. Jurnal MMS, 2019.

[2] Anisa Fitri Mauluda, Seperti Apa Tipe Data Primitif. 2023, dapat di akses di: https://dibimbing.id/blog/detail/seperti-apa-tipe-data-primitif

[3] TylerMSFT,Kelas dan Struktur C++, 2023. dapat diakses di: https://learn.microsoft.com/id-id/cpp/cpp/classes-and-structs-cpp?view=msvc-170

[4] Teknik Informatika Unikom, Taryana Suryana, Belajar Pemrograman. dapat di akses di : https://repository.unikom.ac.id/68464/1/List%20atau%20Array%20dan%20Map%20dalam%20Dart.pdf