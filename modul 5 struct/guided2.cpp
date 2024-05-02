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