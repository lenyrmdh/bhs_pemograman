# RANGKUMAN

# 1. Definisi
Array (dalam sebuah python) merupakan struktur yang dapat menyimpan dan mengatur set data. Struktur data membicarakan tentang penyimpanan, mengatur, pengelompokan, dan mempresentasikan

# 2. Set
Set adalah tipe data kolektif yang digunakan untuk menyimpan beberapa nilai unik satu variabel. 

nilai unik set antara lain :

- set hanya menyimpan nilai unik (bukan duplikat)
- setelah nilai di masukkan ke dalam set, nilai tidak dapat dirubah
- set tidak memiliki urutan, sehingga tidak dapat diakses berdasarkan indeks

# contoh dalam set

student_set = {'Huda', 'Lendis', 'wahid'}
print (student_set)

fruit_set = {['manggo', 'apple']}
print (fruit_set)

# Outputnya:
{'Huda', 'Lendis', 'wahid'}
{'manggo', 'apple'}

# Dictionary
Dictionary dalam Python adalah kumpulan pasangan kunci-nilai di mana setiap kunci unik dan digunakan untuk menyimpan serta mengakses nilai. Karakteristik utama dari dictionary adalah:

1. Keunikan Kunci: Setiap kunci dalam dictionary harus unik.
2. Dapat Diubah: Dictionary bersifat mutable, artinya isinya dapat diubah setelah dibuat.
3. Tidak Berurutan: Dictionary tidak mempertahankan urutan tertentu untuk pasangan kunci-nilai.

# Bentuk Umum dari Dictionary
Menggunakan Kurung Kurawal:
student_dict = {'Huda': 25, 'Lendis': 22, 'Wahid': 23, 'Basith': 21}
print(student_dict)

Menambahkan Pasangan Kunci-Nilai:
student_dict['Ali'] = 24
print(student_dict)

Mengakses Nilai:
age = student_dict['Huda']
print(age)

# Operator Keanggotaan (Dict)
Operator keanggotaan dalam Python, in dan not in, digunakan untuk menguji apakah sebuah kunci atau nilai ada dalam dictionary.