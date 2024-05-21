class MenuItem:
    def __init__(self, name, price):
        self.name = name
        self.price = price

def display_menu(menu, category):
    print(f"Menu {category} dan Harga:")
    for i, item in enumerate(menu, 1):
        print(f"{i}. {item.name} - Rp {item.price}")
    print("0. Kembali ke Pilih Kategori")

def add_order(orders, menu, index):
    if index > 0 and index <= len(menu):
        orders.append(menu[index - 1])

def main():
    makanan = [MenuItem("Mie Goreng", 15000), MenuItem("Nasi Goreng", 20000), MenuItem("Soto Ayam", 18000)]
    minuman = [MenuItem("Teh Pucuk", 10000), MenuItem("Teh Botol", 5000), MenuItem("Teh Kotak", 8000)]
    pesanan = []

    while True:
        print("Menu Makanan dan Minuman")
        print("1. Makanan")
        print("2. Minuman")
        print("3. Selesai dan Hitung Total")
        kategori = int(input("Pilih Kategori (0 untuk keluar): "))

        if kategori == 0 or kategori == 3:
            break

        if kategori == 1:
            display_menu(makanan, "Makanan")
            nomor = int(input("Meminta Input Nomor Makanan: "))
            if nomor != 0:
                add_order(pesanan, makanan, nomor)
        elif kategori == 2:
            display_menu(minuman, "Minuman")
            nomor = int(input("Meminta Input Nomor Minuman: "))
            if nomor != 0:
                add_order(pesanan, minuman, nomor)

        # Tampilkan pesanan yang telah dipilih
        print("Pesanan Anda:")
        for item in pesanan:
            print(f"{item.name} - Rp {item.price}")

    total_harga = sum(item.price for item in pesanan)
    print(f"Total Harga: Rp {total_harga}")

    print("Tampilkan Cara Pembayaran:")
    print("1. Tunai")
    print("2. Kartu Kredit/Debit")
    print("3. Transfer Bank")
    print("4. E-Wallet (OVO, GoPay, DANA, dll.)")
    metode_pembayaran = int(input("Meminta Input Metode Pembayaran: "))

    pembayaran_berhasil = False
    while not pembayaran_berhasil:
        print("Proses Pembayaran...")
        # Simulasi pembayaran berhasil
        pembayaran_berhasil = True  # Ubah menjadi False untuk simulasi pembayaran gagal

        if pembayaran_berhasil:
            print("Pembayaran Berhasil")
            print("Tampilkan Bukti Pembayaran")
        else:
            print("Pembayaran Gagal, Silakan Coba Lagi")
            print("Tampilkan Cara Pembayaran:")
            print("1. Tunai")
            print("2. Kartu Kredit/Debit")
            print("3. Transfer Bank")
            print("4. E-Wallet (OVO, GoPay, DANA, dll.)")
            metode_pembayaran = int(input("Meminta Input Metode Pembayaran: "))

    print("Selesai")

if __name__ == "__main__":
    main()

