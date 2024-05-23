# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">  Irena Cahya Resinah</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

priority queue dan heaps adalah dua konsep yang terkait dalam struktur data yang digunakan untuk mengatur urutan prioritas elemen dalam suatu koleksi. Prioritas dapat berupa nilai numerik, waktu, atau kualitas lainnya yang menentukan urutan elemen dalam koleksi[1][2][3][4][5].

### 1. Priority queue
Priority queue adalah struktur data yang memungkinkan elemen dengan prioritas tertentu untuk ditambahkan dan dihapus. Elemen dengan prioritas tertinggi akan dihapus terlebih dahulu. Priority queue digunakan dalam berbagai aplikasi, seperti pengaturan urutan eksekusi program, pengelolaan antrian, dan pengelolaan kualitas jaringan internet. Dalam implementasinya, priority queue dapat menggunakan struktur data lain seperti linked list atau binary tree, namun struktur data yang paling efektif untuk priority queue adalah heap[1][2][3][4][5].
### 2. Heaps
Heaps adalah struktur data yang berbentuk pohon biner yang memenuhi properti berikut:
1. Complete Binary Tree: Heaps adalah pohon biner yang lengkap, artinya setiap tingkat pohon memiliki jumlah node yang sama, kecuali tingkat teratas yang dapat memiliki jumlah node yang kurang.
2. Heap Property: Heaps memenuhi properti berikut: dalam heap max, nilai node parent tidak kurang dari nilai anaknya; dalam heap min, nilai node parent tidak lebih dari nilai anaknya.
Heaps digunakan sebagai implementasi efisien untuk priority queue karena operasi insert dan delete dapat dilakukan dengan waktu kompleksitas O(log n), serta memungkinkan akses cepat ke elemen dengan prioritas tertinggi atau terendah. Dalam implementasi priority queue menggunakan heaps, elemen baru ditambahkan ke akhir heap dan kemudian diurutkan untuk mempertahankan properti heap. Elemen dengan prioritas tertinggi dihapus dengan menghapus node root dan mempertahankan properti heap dengan operasi heapify-down[1][2][3][4][5].

## Guided 

### 1. Priority Queue dan Heap
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    if (heapSize < 0) {
        throw std::runtime_error("Heap is empty");
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        throw std::runtime_error("Heap is empty");
    }
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority: " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

```
Kode ini mendemonstrasikan cara menggunakan heap maksimum untuk menyimpan elemen dengan prioritas tinggi di bagian atas, sehingga operasi untuk mendapatkan elemen terbesar selalu efisien. Operasi seperti penyisipan, ekstraksi maksimum, pengubahan prioritas, dan penghapusan elemen diimplementasikan dengan menggunakan konsep heapify up dan heapify down.

## Unguided 

### 1. 

#### Priority Queue dan Heap
```C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

std::vector<int> H;
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void buildHeap(const std::vector<int>& elements) {
    H = elements;
    heapSize = H.size() - 1;
    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        shiftDown(i);
    }
}

int extractMax() {
    if (heapSize < 0) {
        throw std::runtime_error("Heap is empty");
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    if (heapSize >= 0) {
        shiftDown(0);
    }
    H.pop_back();
    return result;
}

void changePriority(int i, int p) {
    if (i < 0 || i > heapSize) {
        throw std::out_of_range("Index is out of range");
    }
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        throw std::runtime_error("Heap is empty");
    }
    return H[0];
}

void remove(int i) {
    if (i < 0 || i > heapSize) {
        throw std::out_of_range("Index is out of range");
    }
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Enter the number of elements to insert into the heap: ";
    std::cin >> n;

    std::vector<int> elements(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

    // Build the heap from the input elements
    buildHeap(elements);

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority: " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int index, newPriority;
    std::cout << "Enter the index and new priority to change: ";
    std::cin >> index >> newPriority;
    changePriority(index, newPriority);
    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Enter the index to remove: ";
    std::cin >> index;
    remove(index);
    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}



```

- Deklarasi Vektor dan Variabel: std::vector<int> H digunakan untuk menyimpan elemen heap, dan int heapSize untuk menyimpan ukuran heap.
- Fungsi Utility: parent, leftChild, dan rightChild digunakan untuk mendapatkan indeks elemen induk dan anak kiri/kanan.
- shiftUp dan shiftDown: Dua fungsi ini digunakan untuk menjaga properti heap. shiftUp digunakan ketika elemen baru ditambahkan, sedangkan - shiftDown digunakan ketika elemen dihapus atau diganti.
- buildHeap: Fungsi ini membangun heap dari array input yang diberikan.
- extractMax: Menghapus dan mengembalikan elemen maksimum (root) dari heap.
- changePriority: Mengubah prioritas elemen pada indeks tertentu dan menyesuaikan posisi elemen tersebut dalam heap.
- getMax: Mengembalikan elemen maksimum (root) dari heap.
- remove: Menghapus elemen pada indeks tertentu dari heap.

#### Full code Screenshot:
![Screenshot 2024-05-23 211911](https://github.com/Irenacr/Praktikum-Struktur-Data-Assignment/assets/161007862/15b0db0f-8d11-495e-ac11-479480a094f7)




## Kesimpulan
Pada modul 9 PRIORITY QUEUE DAN HEAP, saya memahami :

- Priority Queue (PQ) adalah struktur data yang memungkinkan elemen dengan prioritas tertentu untuk ditambahkan dan dihapus, dengan elemen dengan prioritas tertinggi dihapus terlebih dahulu.
- Heaps adalah struktur data yang berbentuk pohon biner yang memenuhi properti berikut: dalam heap max, nilai node parent tidak kurang dari nilai anaknya; dalam heap min, nilai node parent tidak lebih dari nilai anaknya.
- Heaps digunakan sebagai implementasi efisien untuk PQ karena operasi insert dan delete dapat dilakukan dengan waktu kompleksitas O(log n), serta memungkinkan akses cepat ke elemen dengan prioritas tertinggi atau terendah.
- Operasi-operasi yang dapat dilakukan pada heaps meliputi insertion, deletion, dan extract min-max.
- Konsep PQ dan heaps dapat digunakan dalam contoh kasus nyata seperti pengelolaan antrian prioritas di suatu rumah sakit, untuk mengatur urutan eksekusi operasi medis berdasarkan prioritas pasien.

Dengan demikian, priority queue dan heaps adalah struktur data yang sangat berguna dalam berbagai aplikasi, terutama dalam pengelolaan antrian dan pengaturan urutan eksekusi program, serta memungkinkan operasi-operasi yang efisien dan cepat.



## Referensi
[1] OpenDSA Data Structures and algorithms modules collection, Heaps and Priority queues, chapters 12 Binary Test, 2019. dapat diakses di: https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/Heaps.html

[2] Siue, Heaps and Priority Queues, CS 340 Algorithms and Data Structures 1.0 Documentation, 2020. dapat diakses di: https://www.cs.siue.edu/~marmcke/docs/cs340/heaps.html

[3] Prateek Garg, Heaps and Priority Queues, 2019. dapat diakses di: https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/
[4] Geeks for Geeks, Bagaimana cara mengimplementasikan Antrian Prioritas – menggunakan Heap atau Array?, 2023. dapat diakses di: https://www.geeksforgeeks.org/how-to-implement-priority-queue-using-heap-or-array/
[5] Bradfields, Priority Queues with Binary Heaps, 2020. dapat di akses di: https://bradfieldcs.com/algos/trees priority-queues-with-binary-heaps/
