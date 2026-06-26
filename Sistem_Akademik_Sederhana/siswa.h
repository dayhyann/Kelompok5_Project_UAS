#ifndef SISWA_H
#define SISWA_H

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

extern Siswa *headSiswa;

// CRUD
void tambahSiswa(Siswa *&head);
void tampilkanSiswa(Siswa *head);
void editSiswa(Siswa *head);
void hapusSiswa(Siswa *&head);

// Menu
void menuSiswa();

#endif