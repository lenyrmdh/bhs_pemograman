#include <iostream>
using namespace std;

int main() {
    int angkaPertama, angkaKedua;

    // Meminta pengguna untuk memasukkan angka pertama
    cout << "masukkan angka pertama = ";
    cin >> angkaPertama;

    // Meminta pengguna untuk memasukkan angka kedua
    cout << "masukkan angka kedua = ";
    cin >> angkaKedua;

    // Melakukan operasi matematika
    int penjumlahan = angkaPertama + angkaKedua;
    int pengurangan = angkaPertama - angkaKedua;
    int perkalian = angkaPertama * angkaKedua;
    float pembagian = static_cast<float>(angkaPertama) / angkaKedua;

    // Menampilkan hasil operasi
    cout << "penjumlahan = " << penjumlahan << endl;
    cout << "pengurangan = " << pengurangan << endl;
    cout << "perkalian = " << perkalian << endl;
    cout << "pembagian = " << pembagian << endl;

    return 0;
}