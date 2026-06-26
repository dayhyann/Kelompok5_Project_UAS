#include "nilai.h"
#include <iostream>

using namespace std;
Nilai* headNilai = NULL;
Nilai* tailNilai = NULL;

// Tambah Nilai
void tambahNilai() {
    Nilai* baru = new Nilai;

    cout << "\n=== TAMBAH NILAI ===\n";

    cout << "Nama Siswa     : ";
    cin >> baru->namaSiswa;

    cout << "Mata Pelajaran : ";
    cin >> baru->mataPelajaran;

    cout << "Nilai          : ";
    cin >> baru->nilai;

    baru->next = NULL;
    baru->prev = NULL;

    if(headNilai == NULL) {
        headNilai = tailNilai = baru;
    } else {
        tailNilai->next = baru;
        baru->prev = tailNilai;
        tailNilai = baru;
    }

    cout << "Data berhasil ditambahkan!\n";
}

// Edit Nilai
void editNilai() {
    string cari;

    cout << "\nNama siswa yang dicari : ";
    cin >> cari;

    Nilai* bantu = headNilai;

    while(bantu != NULL) {

        if(bantu->namaSiswa == cari) {

            cout << "Nilai lama : "
                 << bantu->nilai << endl;

            cout << "Nilai baru : ";
            cin >> bantu->nilai;

            cout << "Data berhasil diubah!\n";
            return;
        }

        bantu = bantu->next;
    }

    cout << "Data tidak ditemukan!\n";
}

// Tampilkan Nilai
void tampilNilai() {

    if(headNilai == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    Nilai* bantu = headNilai;

    cout << "\n=== DATA NILAI SISWA ===\n";

    while(bantu != NULL) {

        cout << "Nama  : "
             << bantu->namaSiswa << endl;

        cout << "Mapel : "
             << bantu->mataPelajaran << endl;

        cout << "Nilai : "
             << bantu->nilai << endl;

        cout << "---------------------\n";

        bantu = bantu->next;
    }
}

// Bubble Sort
void urutkanNilai() {

    if(headNilai == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    bool tukar;

    do {
        tukar = false;

        Nilai* bantu = headNilai;

        while(bantu->next != NULL) {

            if(bantu->nilai >
               bantu->next->nilai) {

                swap(
                    bantu->namaSiswa,
                    bantu->next->namaSiswa
                );

                swap(
                    bantu->mataPelajaran,
                    bantu->next->mataPelajaran
                );

                swap(
                    bantu->nilai,
                    bantu->next->nilai
                );

                tukar = true;
            }

            bantu = bantu->next;
        }

    } while(tukar);

    cout << "\nData berhasil diurutkan!\n";
}

// Menu
void menuNilai() {

    int pilih;

    do {

        cout << "\n=====================\n";
        cout << "      MENU NILAI     \n";
        cout << "=====================\n";
        cout << "1. Tambah Nilai\n";
        cout << "2. Edit Nilai\n";
        cout << "3. Tampilkan Nilai\n";
        cout << "4. Urutkan Nilai\n";
        cout << "0. Kembali\n";
        cout << "Pilihan : ";
        cin >> pilih;

        switch(pilih) {

            case 1:
                tambahNilai();
                break;

            case 2:
                editNilai();
                break;

            case 3:
                tampilNilai();
                break;

            case 4:
                urutkanNilai();
                break;

            case 0:
                cout << "\nKeluar dari menu.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
        }

    } while(pilih != 0);
}