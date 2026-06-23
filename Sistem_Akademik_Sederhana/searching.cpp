#include <iostream>
#include <string>

using namespace std;

// === STRUCT SISWA & MAPEL SUDAH DIHAPUS SESUAI ARAHAN ADMIN ===

// 1. Fungsi Cari Siswa Berdasarkan NIS (Linked List)
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

// 2. Fungsi Cari Siswa Berdasarkan Nama (Linked List)
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

// 3. Fungsi Cari Mata Pelajaran (SUDAH DIGANTI MENJADI LINKED LIST)
void cariMapel(Matapelajaran *head, string keyword)
{
    Matapelajaran *current = head;
    bool ditemukan = false;

    while (current != nullptr)
    {
        if (current->Kode == keyword || current->Nama == keyword)
        {
            cout << "\n[+] Data Mata Pelajaran Ditemukan!" << endl;
            cout << "----------------------------------" << endl;
            cout << "Kode Mapel : " << current->Kode << endl;
            cout << "Nama Mapel : " << current->Nama << endl;
            cout << "SKS        : " << current->SKS << endl;
            ditemukan = true;
        }
        current = current->next;
    }

    if (!ditemukan)
    {
        cout << "\n[-] Mata pelajaran \"" << keyword << "\" tidak ditemukan." << endl;
    }
}

void menuSearching(Siswa *headSiswa, Matapelajaran *headMapel)
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
            cariMapel(headMapel, keyword);
            break;
        case 4:
            cout << "Keluar dari Menu Searching..." << endl;
            break;
        default:
            cout << "[-] Pilihan tidak tersedia. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);
}