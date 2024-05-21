#include <iostream>
using namespace std;

// Deklarasi fungsi
void menu();
void tambah();
void kurang();
void kali();
void bagi();

int main() {
    menu();
    tambah();
    kurang();
    kali();
    bagi();
    return 0;
}

void menu() {
    cout << "=== Menu ===" << endl;
    cout << "1. Tambah" << endl;
    cout << "2. Kurang" << endl;
    cout << "3. Kali" << endl;
    cout << "4. Bagi" << endl;
    cout << "===============" << endl;
}

void tambah() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    cout << "Penjumlahan = " << a + b << endl;
}

void kurang() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    cout << "Pengurangan = " << a - b << endl;
}

void kali() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    cout << "Perkalian = " << a * b << endl;
}

void bagi() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    if (b != 0) {
        cout << "Pembagian = " << static_cast<float>(a) / b << endl;
    } else {
        cout << "Error: Pembagian dengan nol tidak diperbolehkan." << endl;
    }
}