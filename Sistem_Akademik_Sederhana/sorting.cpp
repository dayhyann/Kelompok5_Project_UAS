#include <iostream>
#include <string>

using namespace std;

void tukarDataSiswa(Siswa *a, Siswa *b)
{
    string tempNis = a->nis;
    string tempNama = a->nama; // Proses swap nilai sudah dihapus

    a->nis = b->nis;
    a->nama = b->nama;

    b->nis = tempNis;
    b->nama = tempNama;
}

void urutkanSiswaByNIS(Siswa *head)
{
    if (head == nullptr)
        return;

    bool ditukar;
    Siswa *ptr1;
    Siswa *lptr = nullptr;

    do
    {
        ditukar = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->nis > ptr1->next->nis)
            {
                tukarDataSiswa(ptr1, ptr1->next);
                ditukar = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (ditukar);

    cout << "\n[+] Data siswa berhasil diurutkan berdasarkan NIS secara Ascending." << endl;
}

void urutkanSiswaByNama(Siswa *head)
{
    if (head == nullptr)
        return;

    bool ditukar;
    Siswa *ptr1;
    Siswa *lptr = nullptr;

    do
    {
        ditukar = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->nama > ptr1->next->nama)
            {
                tukarDataSiswa(ptr1, ptr1->next);
                ditukar = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (ditukar);

    cout << "\n[+] Data siswa berhasil diurutkan berdasarkan Nama secara Ascending." << endl;
}

void menuSorting(Siswa *headSiswa)
{
    int pilihan;

    do
    {
        cout << "\n=======================================" << endl;
        cout << "             MENU SORTING              " << endl;
        cout << "=======================================" << endl;
        cout << "1. Urutkan Siswa berdasarkan NIS (Ascending)" << endl;
        cout << "2. Urutkan Siswa berdasarkan Nama (Ascending)" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            urutkanSiswaByNIS(headSiswa);
            break;
        case 2:
            urutkanSiswaByNama(headSiswa);
            break;
        case 3:
            cout << "Keluar dari Menu Sorting..." << endl;
            break;
        default:
            cout << "[-] Pilihan tidak tersedia. Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);
}