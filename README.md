# Sistem Akademik Sederhana

## Anggota Kelompok 5

1. Riyad Hiyan Arizki (2503010024)
2. Edwin Arsy Al Fikri (2503010028)
3. Faiz Husni Firdaus (2503010038)
4. Reva Nur Budiman (2503010051)
5. Muhammad Rafi Ardiansyah (2503010036)

---

## Deskripsi Studi Kasus

Sekolah membutuhkan sistem yang dapat mengelola data akademik secara terstruktur. Sistem harus mampu menyimpan dan mengelola data siswa, mata pelajaran, jadwal pelajaran, dan nilai siswa. Selain itu, sistem harus menyediakan fitur pencarian dan pengurutan data agar informasi akademik dapat diakses dengan lebih mudah dan cepat.

---

## Analisis Kebutuhan Sistem

### Permasalahan

Pengelolaan data akademik secara manual sering menyebabkan kesulitan dalam pencarian data, pembaruan informasi, dan pengelolaan nilai siswa. Oleh karena itu, diperlukan sebuah sistem yang dapat menyimpan dan mengelola data akademik secara lebih terstruktur.

### Kebutuhan Fungsional

#### Pengelolaan Data Siswa

* Menambahkan data siswa
* Mengubah data siswa
* Menghapus data siswa
* Menampilkan seluruh data siswa
* Mencari data siswa berdasarkan nama atau NIS
* Urutkan Siswa berdasarkan NIS
* Urutkan Siswa berdasarkan Nama

#### Pengelolaan Mata Pelajaran

* Menambahkan mata pelajaran
* Mengubah mata pelajaran
* Menghapus mata pelajaran
* Menampilkan daftar mata pelajaran
* Mencari mata pelajaran

#### Pengelolaan Jadwal

* Menambahkan jadwal pelajaran
* Mengubah jadwal pelajara
* Menghapus jadwal pelajaran
* Menampilkan jadwal pelajaran

#### Pengelolaan Nilai

* Menambahkan nilai siswa
* Mengubah nilai siswa
* Menampilkan nilai siswa
* Mengurutkan nilai siswa

#### Pencarian Data

* Pencarian siswa berdasarkan NIS
* Pencarian siswa berdasarkan nama
* Pencarian mata pelajaran

#### Pengurutan Data

* Pengurutan siswa berdasarkan nama
* Pengurutan siswa berdasarkan NIS
* Pengurutan nilai dari tertinggi ke terendah

---

## Data yang Dikelola

### Data Siswa

* NIS
* Nama
* Kelas
* Jurusan

### Data Mata Pelajaran

* Nama Mata Pelajaran

### Data Jadwal

* Hari
* Jam
* Mata Pelajaran
* Ruang Kelas

### Data Nilai

* Nama Siswa
* Mata Pelajaran
* Nilai

---

## Struktur Data yang Digunakan

### Singly Linked List

Digunakan untuk menyimpan data siswa dan mata pelajaran.

### Doubly Linked List

Digunakan untuk menyimpan data nilai.

### Circular Doubly Linked List

Digunakan untuk menyimpan data jadwal pelajaran.

---

## Algoritma yang Digunakan

### Searching

Metode:

* Linear Search

Digunakan untuk mencari:

* Data siswa berdasarkan NIS
* Data siswa berdasarkan nama
* Data mata pelajaran

### Sorting

Metode:

* Bubble Sort

Digunakan untuk:

* Mengurutkan siswa berdasarkan NIS
* Mengurutkan siswa berdasarkan nama
* Mengurutkan nilai tertinggi ke terendah

#Pembagian Tugas

 Nama                   Tugas                                   
* Riyad               : Integrasi Program, Main Program, GitHub 
* Faiz                : Modul Data Siswa, Searching, Sorting    
* M.Rafi              : Modul Mata Pelajaran                    
* Reva                : Modul Jadwal                            
* Edwin               : Modul Nilai                             


## Jalankan Program

.\SistemAkademik.exe

## CATATAN

* Setiap anggota bekerja pada branch masing-masing.
* Tidak diperbolehkan push langsung ke branch main.
* Setiap anggota wajib membuat minimal satu Pull Request.
* Ketua melakukan review sebelum merge ke branch main.
