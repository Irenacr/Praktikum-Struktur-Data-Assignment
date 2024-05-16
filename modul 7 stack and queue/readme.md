# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Pada pemrograman struktur data, stack dan queue adalah dua jenis struktur data non primitif data abstrak yang digunakan untuk menyimpan elemen data baik di array maupun di linked list yang sebenarnya didasarkan pada beberapa kejadian di kehidupan nyata. Stack menggunakan metode LIFO (last in first out) untuk mengakses dan menambahkan elemen data sedangkan queue menggunakan metode FIFO (First in first out) untuk mengakses dan menamhkan elemen data. Penelitian menggunakan tipe data integer untuk dimasukkan ke dalam array dan linked list dan dilakukan pengujian terhadapnya dengan membuat program aplikasi menggunakan bahasa pemrograman Java, yaitu suatu bahasa pemrograman dengan konsep object oriented. Dengan menggunakan versi JDK (Java Develompent Kit), maka class Java untuk mengoperasikan linked list, queue dan stack sudah tersedia. Untuk mengakses data dari class- class tersebut dapat dikonversi menjadi array atau iterator (list satu arah). Java sudah menyedikan LinkedList yang 
digunakan sebagai queue, Stack yang digunakan sebagai stack, dan ArrayDeque sebagai deque(gabungan antara queue dan stack). [1].

### 1. Single Linked List
Stack atau tumpukan adalah suatu stuktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO (Last In First Out) dimana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa di akses. Salah satu kelebihan stack adalah bahwa struktur data tersebut dapat di 
implementasikan baik pada array maupun pada linked list[1].
### 2. Double Linked List
Kebalikan dari stack, queue (antrian) adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk 20 ke antrian akan keluar pertama kalinya. Ada dua jenis operasi yang bias dilakukan di antrian : enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (adalah mengeluarkan satu elemen dari suatu antrian). Antrian dapat dibuat dengan menggunakan: Liniear Array dan Circular Array.[1].

## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
Kode ini merupakan implementasi sederhana dari struktur data stack (tumpukan) dalam bahasa C++. Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out), di mana elemen yang terakhir kali dimasukkan akan menjadi elemen yang pertama kali dikeluarkan. Kode ini menggambarkan bagaimana stack bekerja dengan operasi-operasi dasar seperti menambah elemen (push), menghapus elemen (pop), melihat elemen (peek), menghitung jumlah elemen (count), mengubah elemen (change), mengosongkan stack (destroy), dan menampilkan isi stack (print).

### 2. Tipe Data Abstrak

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```
Kode ini adalah implementasi sederhana dari antrian (queue) menggunakan array di C++. Queue adalah struktur data yang mengikuti prinsip FIFO (First In, First Out), artinya elemen pertama yang dimasukkan adalah elemen pertama yang dikeluarkan. Kode ini menggambarkan bagaimana antrian bekerja dengan operasi-operasi dasar seperti menambah elemen (enqueue), menghapus elemen (dequeue), menghitung jumlah elemen (count), mengosongkan antrian (clear), dan melihat isi antrian (view).


## Unguided 

### 1. 

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk membersihkan dan memformat kalimat
string cleanSentence(const string &sentence) {
    string cleaned;
    for (char c : sentence) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

// Fungsi untuk menentukan apakah kalimat adalah palindrom
bool isPalindrome(const string &sentence) {
    string cleaned = cleanSentence(sentence);
    stack<char> charStack;

    // Memasukkan semua karakter ke dalam stack
    for (char c : cleaned) {
        charStack.push(c);
    }

    // Membandingkan karakter dari awal dan akhir menggunakan stack
    for (char c : cleaned) {
        if (c != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string inputSentence;

    cout << "Masukkan kalimat: ";
    getline(cin, inputSentence);

    if (isPalindrome(inputSentence)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}


```

Kode ini adalah implementasi untuk memeriksa apakah suatu kalimat adalah palindrom atau bukan. Sebuah palindrom adalah sebuah kata, frasa, atau urutan karakter lainnya yang membaca sama baik maju maupun mundur, mengabaikan spasi, tanda baca, dan kapitalisasi.

Berikut adalah penjelasan dari bagian-bagian penting dalam kode ini:

Fungsi cleanSentence:

Fungsi ini bertugas untuk membersihkan dan memformat kalimat. Mengambil setiap karakter dalam kalimat, dan jika karakter tersebut adalah alfanumerik (huruf atau angka), maka karakter tersebut diubah menjadi huruf kecil dan ditambahkan ke string cleaned.Tujuan dari fungsi ini adalah untuk mengabaikan spasi, tanda baca, dan kapitalisasi dalam proses pemeriksaan palindrom.
Fungsi isPalindrome:

Fungsi ini bertugas untuk menentukan apakah kalimat yang diberikan adalah palindrom atau bukan. Pertama, fungsi ini memanggil cleanSentence untuk membersihkan kalimat. Kemudian, setiap karakter dari kalimat yang sudah dibersihkan dimasukkan ke dalam sebuah stack charStack.
Setelah semua karakter dimasukkan ke dalam stack, karakter dalam kalimat yang dibersihkan dibandingkan dengan karakter yang diambil dari stack (dimulai dari yang terakhir dimasukkan karena sifat LIFO dari stack). Jika ditemukan perbedaan antara karakter dari awal dan akhir, fungsi mengembalikan false, menandakan bahwa kalimat tersebut bukan palindrom. Jika semua karakter cocok, fungsi mengembalikan true, menandakan bahwa kalimat tersebut adalah palindrom.
Fungsi main:

Fungsi utama ini meminta pengguna untuk memasukkan sebuah kalimat. Kalimat tersebut kemudian diperiksa apakah merupakan palindrom menggunakan fungsi isPalindrome. Hasil pemeriksaan kemudian ditampilkan kepada pengguna, yaitu apakah kalimat tersebut adalah palindrom atau bukan.
Contoh alur eksekusi program:

Pengguna memasukkan kalimat: "A man, a plan, a canal, Panama".
Kalimat tersebut akan dibersihkan menjadi: "amanaplanacanalpanama".
Stack akan diisi dengan karakter-karakter dari string yang telah dibersihkan.
Karakter akan dibandingkan satu per satu dari awal dan akhir.
Jika semua karakter cocok, program akan mengeluarkan output bahwa kalimat tersebut adalah palindrom.



### 2. 

#### Class
```C++
#include <iostream>
#include <string>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[maksimalQueue]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { // Antrian kosong atau tidak
    return back == 0;
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data;
        back++;
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; // Menghapus elemen terakhir yang kosong
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "=== Menu Antrian ===" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Hapus Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hapus Semua Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}

```


Kode ini adalah implementasi sederhana dari sistem antrian menggunakan array dalam bahasa C++. Program ini memungkinkan pengguna untuk menambahkan, menghapus, melihat, dan mengosongkan antrian. Antrian dalam program ini mengikuti prinsip FIFO (First In, First Out), di mana elemen yang pertama kali dimasukkan akan menjadi elemen yang pertama kali keluar.

Berikut adalah penjelasan fungsi-fungsi dan bagian-bagian utama dari kode ini:

1. Deklarasi dan Inisialisasi:
   - `maksimalQueue`: Batas maksimal jumlah elemen dalam antrian (5).
   - `front`: Indeks penanda untuk bagian depan antrian (tidak digunakan dalam operasi saat ini).
   - `back`: Indeks penanda untuk bagian belakang antrian, dimulai dari 0.
   - `queueTeller`: Array untuk menyimpan elemen-elemen antrian.

2. Fungsi `isFull`:
   - Mengecek apakah antrian penuh dengan membandingkan nilai `back` dengan `maksimalQueue`.

3. Fungsi `isEmpty`:
   - Mengecek apakah antrian kosong dengan memeriksa nilai `back`.

4. Fungsi `enqueueAntrian`:
   - Menambahkan elemen baru ke dalam antrian.
   - Jika antrian penuh, mencetak pesan "Antrian penuh".
   - Jika tidak, elemen baru ditambahkan ke posisi yang sesuai dengan nilai `back`, dan `back` diperbarui.

5. Fungsi `dequeueAntrian`:
   - Menghapus elemen dari antrian.
   - Jika antrian kosong, mencetak pesan "Antrian kosong".
   - Jika tidak, elemen di bagian depan antrian dihapus, dan elemen-elemen lain bergeser maju. Elemen terakhir diatur menjadi kosong dan `back` diperbarui.

6. Fungsi `countQueue`:
   - Mengembalikan jumlah elemen dalam antrian berdasarkan nilai `back`.

7. Fungsi `clearQueue`:
   - Mengosongkan antrian dengan menghapus semua elemen.
   - Mengatur nilai `back` kembali ke 0.

8. Fungsi `viewQueue`:
   - Menampilkan isi antrian.
   - Jika elemen di posisi tertentu kosong, mencetak "(kosong)".

9. Fungsi `main`:
   - Menampilkan menu interaktif untuk pengguna.
   - Pengguna dapat memilih untuk menambah antrian, menghapus antrian, melihat isi antrian, menghapus semua antrian, atau keluar dari program.
   - Menggunakan `switch` untuk menangani pilihan pengguna dan memanggil fungsi-fungsi yang sesuai.

Contoh alur eksekusi program:
- Pengguna memilih opsi 1 untuk menambahkan nama ke antrian.
- Pengguna memilih opsi 2 untuk menghapus nama dari antrian.
- Pengguna memilih opsi 3 untuk melihat isi antrian.
- Pengguna memilih opsi 4 untuk mengosongkan semua antrian.
- Pengguna memilih opsi 5 untuk keluar dari program.

Output yang dihasilkan akan menampilkan keadaan antrian setelah setiap operasi. Misalnya, jika pengguna menambahkan nama dan kemudian melihat antrian, output akan mencerminkan nama-nama dalam antrian beserta posisi masing-masing.





## Kesimpulan
Pada modul 7 STACK & QUEUE, 
- Stack dan queue adalah struktur data fundamental yang digunakan dalam pengembangan perangkat lunak.
- Keduanya memiliki prinsip operasi yang berbeda (LIFO untuk stack dan FIFO untuk queue) sehingga digunakan dalam konteks yang berbeda pula.
- Implementasi dari stack dan queue dapat bervariasi tergantung pada kebutuhan dan lingkungan pemrograman.
- Pemahaman yang baik tentang stack dan queue penting dalam mengembangkan aplikasi yang efisien dan handal.


## Referensi
[1] Agung Kurniman Putra, PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA . Journal Piksi, 2020. 

