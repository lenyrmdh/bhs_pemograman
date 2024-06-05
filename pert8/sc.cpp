#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Struct untuk menyimpan informasi toko
struct StoreInfo {
    string location;
    double price; // Harga dalam dollar
};

// Fungsi untuk meminta izin lokasi
bool requestLocationPermission() {
    // Simulasi permintaan izin lokasi
    cout << "Meminta izin lokasi..." << endl;
    // Return true jika izin diberikan, false jika ditolak
    return rand() % 2 == 0;
}

// Fungsi untuk mendapatkan lokasi
bool getLocation() {
    // Simulasi mendapatkan lokasi
    cout << "Mendapatkan lokasi..." << endl;
    // Return true jika lokasi berhasil didapatkan, false jika gagal
    return rand() % 2 == 0;
}

// Fungsi untuk memuat data toko Starbucks
bool loadStarbucksStores() {
    // Simulasi memuat data toko Starbucks
    cout << "Memuat toko Starbucks..." << endl;
    // Return true jika data berhasil dimuat, false jika gagal
    return rand() % 2 == 0;
}

// Fungsi untuk mengambil data toko Starbucks
bool fetchStarbucksData() {
    // Simulasi pengambilan data toko Starbucks dari server
    cout << "Mengambil data toko Starbucks..." << endl;
    // Return true jika data berhasil diambil, false jika gagal
    return rand() % 2 == 0;
}

// Fungsi untuk menampilkan daftar menu Starbucks
void displayStarbucksMenu() {
    // Simulasi menampilkan daftar menu Starbucks
    cout << "==========================" << endl;
    cout << "Menu Starbucks:" << endl;
    cout << "1. Espresso" << endl;
    cout << "2. Latte" << endl;
    cout << "3. Cappuccino" << endl;
    cout << "4. Americano" << endl;
    cout << "5. Teh" << endl;
    cout << "==========================" << endl;
}

// Fungsi untuk memesan minuman Starbucks
string placeOrder(int choice) {
    string drink;

    // Menentukan minuman yang dipesan berdasarkan pilihan
    switch (choice) {
        case 1:
            drink = "Espresso";
            break;
        case 2:
            drink = "Latte";
            break;
        case 3:
            drink = "Cappuccino";
            break;
        case 4:
            drink = "Americano";
            break;
        case 5:
            drink = "Teh";
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return "";
    }

    // Menampilkan pesan konfirmasi pesanan
    cout << "Pesanan Anda: " << drink << endl;
    return drink;
}

// Fungsi untuk membayar pesanan
void payForOrder(double total) {
    // Simulasi pembayaran
    cout << "Pembayaran sebesar $" << total << " berhasil dilakukan." << endl;
}

// Fungsi untuk menampilkan menu utama
void displayMainMenu() {
    cout << "Selamat datang di layanan Starbucks!" << endl;
    cout << "Menu: " << endl;
    cout << "1. Cari Lokasi Toko Starbucks" << endl;
    cout << "2. Tampilkan Daftar Toko Starbucks" << endl;
    cout << "3. Lihat Menu Starbucks" << endl;
    cout << "4. Pesan Minuman" << endl;
    cout << "5. Bayar" << endl;
    cout << "6. Keluar" << endl;
}

int main() {
    int choice;
    double totalPayment = 0.0;
    bool locationFound = false; // Menandakan apakah lokasi telah ditemukan

    // Menampilkan pesan selamat datang dan informasi pemasaran
    cout << "==============================================" << endl;
    cout << "  Selamat datang di layanan Starbucks!" << endl;
    cout << "  Nikmati pengalaman kopi terbaik bersama kami." << endl;
    cout << "  Temukan lokasi terdekat, pesan kopi favorit Anda, dan banyak lagi!" << endl;
    cout << "==============================================" << endl << endl;

    // Informasi toko di lokasi "Sency"
    StoreInfo sencyStore = {"Sency", 3.5}; // Harga per minuman adalah $3.5

    do {
        // Menampilkan menu utama
        displayMainMenu();

        // Meminta pilihan dari pengguna
        cout << "Pilih layanan: ";
        cin >> choice;

        // Melakukan aksi sesuai dengan pilihan
        switch (choice) {
            case 1:
                // Meminta izin lokasi
                if (!requestLocationPermission()) {
                    cout << "Error: Izin lokasi ditolak" << endl;
                    cout << "Maaf, untuk dapat menemukan toko Starbucks terdekat, kami memerlukan izin lokasi Anda." << endl;
                }
                else {
                    // Mendapatkan lokasi jika izin diberikan
                    if (getLocation()) {
                        cout << "Lokasi berhasil didapatkan. Temukan toko Starbucks terdekat!" << endl;
                        locationFound = true;
                    }
                    else {
                        cout << "Error: Gagal mendapatkan lokasi" << endl;
                        cout << "Maaf, terjadi kesalahan saat mencoba mendapatkan lokasi Anda." << endl;
                    }
                }
                break;
            case 2:
                // Menampilkan informasi toko di lokasi "Sency"
                if (locationFound) {
                    cout << "Toko Starbucks di " << sencyStore.location << " tersedia." << endl;
                    cout << "Harga per minuman di " << sencyStore.location << " adalah Rp" << sencyStore.price * 15000 << ",-" << endl; // Konversi harga dari dollar ke rupiah dengan kurs 1 USD = Rp15000
                } else {
                    cout << "Anda harus mencari lokasi terlebih dahulu sebelum menampilkan daftar toko." << endl;
                }
                break;
            case 3:
                // Menampilkan menu Starbucks
                displayStarbucksMenu();
                break;
            case 4:
                // Memesan minuman
                if (locationFound) {
                    int drinkChoice;
                    cout << "Pilih minuman yang Anda inginkan (1-5): ";
                    cin >> drinkChoice;
                    totalPayment += placeOrder(drinkChoice) == "" ? 0.0 : sencyStore.price; // Harga per minuman di toko sency
                } else {
                    cout << "Anda harus mencari lokasi terlebih dahulu sebelum memesan minuman." << endl;
                }
                break;
            case 5:
                // Membayar
                if (totalPayment > 0.0) {
                    // Konversi total pembayaran dari dollar ke rupiah dengan kurs 1 USD = Rp15000
                    double totalPaymentRupiah = totalPayment * 15000;
                    cout << "Total pembayaran Anda: Rp" << totalPaymentRupiah << ",-" << endl;

                    // Meminta metode pembayaran
                    cout << "Pilih metode pembayaran: " << endl;
                    cout << "1. Tunai" << endl;
                    cout << "2. Kartu Kredit" << endl;
                    int paymentMethod;
                    cout << "Pilih metode pembayaran: ";
                    cin >> paymentMethod;

                    // Proses pembayaran
                    switch (paymentMethod) {
                        case 1:
                            cout << "Pembayaran tunai diterima. Terima kasih!" << endl;
                            break;
                        case 2:
                            cout << "Pembayaran dengan kartu kredit diterima. Terima kasih!" << endl;
                            break;
                        default:
                            cout << "Metode pembayaran tidak valid." << endl;
                            break;
                    }

                    totalPayment = 0.0; // Set total pembayaran kembali ke nol setelah pembayaran berhasil
                } else {
                    cout << "Anda belum memesan apapun atau sudah membayar pesanan Anda." << endl;
                }
                break;
            case 6:
                // Keluar dari program
                cout << "Terima kasih telah menggunakan layanan Starbucks! Sampai jumpa lagi!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}
