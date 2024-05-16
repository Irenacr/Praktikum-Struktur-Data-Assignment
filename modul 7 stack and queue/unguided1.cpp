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

