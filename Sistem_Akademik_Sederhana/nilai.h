#ifndef NILAI_H
#define NILAI_H

#include <string>

using namespace std;

struct Nilai
{
    string namaSiswa;
    string mataPelajaran;
    float nilai;

    Nilai *prev;
    Nilai *next;
};

extern Nilai *headNilai;
extern Nilai *tailNilai;

void tambahNilai();
void editNilai();
void tampilNilai();
void urutkanNilai();
void menuNilai();

#endif