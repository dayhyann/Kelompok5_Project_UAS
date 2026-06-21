#include <iostream>
#include <string>

using namespace std;

struct Siswa
{
    string nis;
    string nama;
    string kelas;
    string jurusan;
    Siswa *next;
};

void tambahSiswa(Siswa *&head)
{
    Siswa *newNode = new Siswa();

    cout << "\n=== TAMBAH DATA SISWA ===\n";
    cout << "Masukkan NIS     : ";
    cin >> newNode->nis;

    cout << "Masukkan Nama    : ";
    getline(cin >> ws, newNode->nama);

    cout << "Masukkan Kelas   : ";
    getline(cin >> ws, newNode->kelas);

    cout << "Masukkan Jurusan : ";
    getline(cin >> ws, newNode->jurusan);

    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Siswa *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "[+] Data siswa berhasil ditambahkan!\n";
}

void tampilkanSiswa(Siswa *head)
{
    cout << "\n=== DAFTAR DATA SISWA ===\n";
    if (head == nullptr)
    {
        cout << "[-] Data siswa masih kosong.\n";
        return;
    }

    Siswa *temp = head;
    int no = 1;
    while (temp != nullptr)
    {
        cout << no << ". NIS: " << temp->nis
             << " | Nama: " << temp->nama
             << " | Kelas: " << temp->kelas
             << " | Jurusan: " << temp->jurusan << "\n";
        temp = temp->next;
        no++;
    }
}

void editSiswa(Siswa *head)
{
    if (head == nullptr)
    {
        cout << "\n[-] Data siswa masih kosong, tidak ada yang bisa diedit.\n";
        return;
    }

    string targetNis;
    cout << "\n=== EDIT DATA SISWA ===\n";
    cout << "Masukkan NIS siswa yang ingin diedit: ";
    cin >> targetNis;

    Siswa *temp = head;
    bool found = false;

    while (temp != nullptr)
    {
        if (temp->nis == targetNis)
        {
            cout << "\n[!] Data Ditemukan! Silakan masukkan data baru.\n";
            cout << "Nama Baru    : ";
            getline(cin >> ws, temp->nama);
            cout << "Kelas Baru   : ";
            getline(cin >> ws, temp->kelas);
            cout << "Jurusan Baru : ";
            getline(cin >> ws, temp->jurusan);

            cout << "[+] Data siswa berhasil diperbarui!\n";
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found)
    {
        cout << "[-] Siswa dengan NIS " << targetNis << " tidak ditemukan.\n";
    }
}

void hapusSiswa(Siswa *&head)
{
    if (head == nullptr)
    {
        cout << "\n[-] Data siswa masih kosong.\n";
        return;
    }

    string targetNis;
    cout << "\n=== HAPUS DATA SISWA ===\n";
    cout << "Masukkan NIS siswa yang ingin dihapus: ";
    cin >> targetNis;

    Siswa *temp = head;
    Siswa *prev = nullptr;

    if (temp != nullptr && temp->nis == targetNis)
    {
        head = temp->next;
        delete temp;
        cout << "[+] Data siswa berhasil dihapus!\n";
        return;
    }

    while (temp != nullptr && temp->nis != targetNis)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "[-] Siswa dengan NIS " << targetNis << " tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "[+] Data siswa berhasil dihapus!\n";
}