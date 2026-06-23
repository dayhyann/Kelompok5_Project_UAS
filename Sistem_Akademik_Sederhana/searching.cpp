#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Siswa
{
    string nis;
    string nama;
    float nilai;
    Siswa *next;
};

struct Matapelajaran
{
    string Kode;
    string Nama;
    int SKS;
};

void cariSiswaByNIS(Siswa *head, string nis)
{
    Siswa *current = head;
    bool ditemukan = false;

    while (current != nullptr)
    {
        if (current->nis == nis)
        {
            cout << "\n[+] Data Siswa Ditemukan!" << endl;
            cout << "-------------------------" << endl;
            cout << "NIS   : " << current->nis << endl;
            cout << "Nama  : " << current->nama << endl;
            cout << "Nilai : " << current->nilai << endl;
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

void cariSiswaByNama(Siswa *head, string nama)
{
    Siswa *current = head;
    bool ditemukan = false;

    while (current != nullptr)
    {
        if (current->nama == nama)
        {
            cout << "\n[+] Data Siswa Ditemukan!" << endl;
            cout << "-------------------------" << endl;
            cout << "NIS   : " << current->nis << endl;
            cout << "Nama  : " << current->nama << endl;
            cout << "Nilai : " << current->nilai << endl;
            ditemukan = true;
        }
        current = current->next;
    }

    if (!ditemukan)
    {
        cout << "\n[-] Siswa dengan nama \"" << nama << "\" tidak ditemukan." << endl;
    }
}

void cariMapel(const vector<Matapelajaran> &daftarMapel, string keyword)
{
    bool ditemukan = false;

    for (const auto &mapel : daftarMapel)
    {
        if (mapel.Kode == keyword || mapel.Nama == keyword)
        {
            cout << "\n[+] Data Mata Pelajaran Ditemukan!" << endl;
            cout << "----------------------------------" << endl;
            cout << "Kode Mapel : " << mapel.Kode << endl;
            cout << "Nama Mapel : " << mapel.Nama << endl;
            cout << "SKS        : " << mapel.SKS << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan)
    {
        cout << "\n[-] Mata pelajaran \"" << keyword << "\" tidak ditemukan." << endl;
    }
}

void menuSearching(Siswa *headSiswa, const vector<Matapelajaran> &daftarMapel)
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
        cout << "3. Cari Mata Pelajaran (Kode/Nama)" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Pilih menu (1-4): ";
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
        case 3:
            cout << "Masukkan Kode/Nama Mapel yang dicari: ";
            getline(cin, keyword);
            cariMapel(daftarMapel, keyword);
            break;
        case 4:
            cout << "Keluar dari Menu Searching..." << endl;
            break;
        default:
            cout << "[-] Pilihan tidak tersedia. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);
}