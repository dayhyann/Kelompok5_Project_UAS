#include <iostream>

#include "siswa.h"
#include "MataPelajaran.h"
#include "jadwal.h"
#include "nilai.h"
#include "searching.h"
#include "sorting.h"

using namespace std;

int main()
{
    int pilihan;

    do
    {
        cout << "\n=========================================\n";
        cout << "      SISTEM AKADEMIK SEDERHANA\n";
        cout << "=========================================\n";
        cout << "1. Kelola Data Siswa\n";
        cout << "2. Kelola Mata Pelajaran\n";
        cout << "3. Kelola Jadwal\n";
        cout << "4. Kelola Nilai\n";
        cout << "0. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            menuSiswa();
            break;

        case 2:
            menuMapel();
            break;

        case 3:
            menuJadwal();
            break;

        case 4:
            menuNilai();
            break;

        case 0:
            cout << "\nTerima kasih telah menggunakan program.\n";
            break;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}