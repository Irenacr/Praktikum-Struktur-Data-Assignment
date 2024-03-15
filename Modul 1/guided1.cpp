#include <iostream>
using namespace std;
//guided 2

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
    // mengisis nilai ke struct
    mhs1. name = "Dian";
    mhs1. address = "Mataram";
    mhs1. age = 22;
    mhs2. name = "bambang";
    mhs2. address = "Surabaya";
    mhs2. age = 23;

    cout<<"Mahasiswa 1\n";
    cout<<"Nama: " <<mhs1.name <<endl;
    cout<<"Alamat: " <<mhs1.address <<endl;
    cout<<"Umur: " <<mhs1.age <<endl;
    cout<<"Mahasiswa 2\n";
    cout<<"Nama: " <<mhs2.name <<endl;
    cout<<"Alamat: " <<mhs2.address <<endl;
    cout<<"Umur: " <<mhs2.age <<endl;

return 0;
}