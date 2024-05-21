#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MenuItem {
    string name;
    int price;
};

void displayMenu(const vector<MenuItem>& menu, const string& category) {
    cout << "Menu " << category << " dan Harga:" << endl;
    for (int i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].name << " - Rp " << menu[i].price << endl;
    }
    cout << "0. Kembali ke Pilih Kategori" << endl;
}

void addOrder(vector<MenuItem>& orders, const vector<MenuItem>& menu, int index) {
    if (index > 0 && index <= menu.size()) {
        orders.push_back(menu[index - 1]);
    }
}

int main() {
    vector<MenuItem> makanan = { {"Mie Goreng", 15000}, {"Nasi Goreng", 20000}, {"Soto Ayam", 18000} };
    vector<MenuItem> minuman = { {"Teh Pucuk", 10000}, {"Teh Botol", 5000}, {"Teh Kotak", 8000} };
    vector<MenuItem> pesanan;

    while (true) {
        cout << "Menu Makanan dan Minuman" << endl;
        cout << "1. Makanan" << endl;
        cout << "2. Minuman" << endl;
        cout << "3. Selesai dan Hitung Total" << endl;
        cout << "Pilih Kategori (0 untuk keluar): ";
        int kategori;
        cin >> kategori;

        if (kategori == 0 || kategori == 3) break;

        if (kategori == 1) {
            displayMenu(makanan, "Makanan");
            cout << "Meminta Input Nomor Makanan: ";
            int nomor;
            cin >> nomor;
            if (nomor != 0)
                addOrder(pesanan, makanan, nomor);
        } else if (kategori == 2) {
            displayMenu(minuman, "Minuman");
            cout << "Meminta Input Nomor Minuman: ";
            int nomor;
            cin >> nomor;
            if (nomor != 0)
                addOrder(pesanan, minuman, nomor);
        }

        // Tampilkan pesanan yang telah dipilih
        cout << "Pesanan Anda:" << endl;
        for (const auto& item : pesanan) {
            cout << item.name << " - Rp " << item.price << endl;
        }
    }

    int total_harga = 0;
    cout << "Total Harga: Rp ";
    for (const auto& item : pesanan) {
        total_harga += item.price;
    }
    cout << total_harga << endl;

    cout << "Tampilkan Cara Pembayaran:" << endl;
    cout << "1. Tunai" << endl;
    cout << "2. Kartu Kredit/Debit" << endl;
    cout << "3. Transfer Bank" << endl;
    cout << "4. E-Wallet (OVO, GoPay, DANA, dll.)" << endl;
    cout << "Meminta Input Metode Pembayaran: ";
    int metode_pembayaran;
    cin >> metode_pembayaran;

    bool pembayaran_berhasil = false;
    while (!pembayaran_berhasil) {
        cout << "Proses Pembayaran..." << endl;
        // Simulasi pembayaran berhasil
        pembayaran_berhasil = true;  // Ubah menjadi false untuk simulasi pembayaran gagal

        if (pembayaran_berhasil) {
            cout << "Pembayaran Berhasil" << endl;
            cout << "Tampilkan Bukti Pembayaran" << endl;
        } else {
            cout << "Pembayaran Gagal, Silakan Coba Lagi" << endl;
            cout << "Tampilkan Cara Pembayaran:" << endl;
            cout << "1. Tunai" << endl;
            cout << "2. Kartu Kredit/Debit" << endl;
            cout << "3. Transfer Bank" << endl;
            cout << "4. E-Wallet (OVO, GoPay, DANA, dll.)" << endl;
            cout << "Meminta Input Metode Pembayaran: ";
            cin >> metode_pembayaran;
        }
    }

    cout << "Selesai" << endl;
    return 0;
}
