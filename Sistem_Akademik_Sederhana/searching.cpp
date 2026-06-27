#include "searching.h"
#include <iostream>

using namespace std;

void cariSiswaByNIS(Siswa *headSiswa, string nis)
{
    Siswa *current = headSiswa;
    bool ditemukan = false;

    while (current != nullptr)
    {
        if (current->nis == nis)
        {
            cout << "\n[+] Data Siswa Ditemukan!" << endl;
            cout << "-------------------------" << endl;
            cout << "NIS   : " << current->nis << endl;
            cout << "Nama  : " << current->nama << endl; // Atribut nilai sudah dihapus
            ditemukan = true;
            break;
        }
        current = current->next;
    }

    if (!ditemukan)
    {
        cout << "\n[-] Siswa dengan NIS \"" << nis << "\" tidak ditemukan." << endl;
    }
}

void cariSiswaByNama(Siswa *headSiswa, string nama)
{
    Siswa *current = headSiswa;
    bool ditemukan = false;

    while (current != nullptr)
    {
        if (current->nama == nama)
        {
            cout << "\n[+] Data Siswa Ditemukan!" << endl;
            cout << "-------------------------" << endl;
            cout << "NIS   : " << current->nis << endl;
            cout << "Nama  : " << current->nama << endl; // Atribut nilai sudah dihapus
            ditemukan = true;
            break;
        }
        current = current->next;
    }

    if (!ditemukan)
    {
        cout << "\n[-] Siswa dengan nama \"" << nama << "\" tidak ditemukan." << endl;
    }
}

void menuSearching(Siswa *headSiswa)
{
    int pilihan;
    string keyword;

    do
    {
        cout << "\n=======================================" << endl;
        cout << "            MENU SEARCHING             " << endl;
        cout << "=======================================" << endl;
        cout << "1. Cari Siswa berdasarkan NIS" << endl;
        cout << "2. Cari Siswa berdasarkan Nama" << endl;
        cout << "0. Kembali ke Menu Siswa" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan NIS yang dicari: ";
            getline(cin, keyword);
            cariSiswaByNIS(headSiswa, keyword);
            break;
        case 2:
            cout << "Masukkan Nama siswa yang dicari: ";
            getline(cin, keyword);
            cariSiswaByNama(headSiswa, keyword);
            break;
        case 0:
            cout << "Kembali ke Menu Siswa...\n" << endl;
            break;
        default:
            cout << "[-] Pilihan tidak tersedia. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);
}