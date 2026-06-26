#ifndef JADWAL_H
#define JADWAL_H

#include <string>

using namespace std;

struct Jadwal
{
    string hari;
    string jam;
    string mataPelajaran;
    string ruangKelas;

    Jadwal *next;
    Jadwal *prev;
};

extern Jadwal *headJadwal;

// Fungsi
int hitungJadwal();
void tambahJadwal();
void tampilJadwal();
void editJadwal();
void hapusJadwal();
void menuJadwal();

#endif