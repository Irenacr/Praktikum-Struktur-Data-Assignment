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