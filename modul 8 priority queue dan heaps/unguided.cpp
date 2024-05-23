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
