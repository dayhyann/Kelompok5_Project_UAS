#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct MataPelajaran {
    string kode;
    string nama;
    int sks;
};


class PengelolaMapel {
private:
    vector<MataPelajaran> daftarMapel;

   
    int cariIndeksBandaKode(string kode) {
        for (size_t i = 0; i < daftarMapel.size(); ++i) {
            if (daftarMapel[i].kode == kode) {
                return i; 
            }
        }
        return -1; 
    }

public:
    
    void tambahMapel() {
        MataPelajaran mp;
        cout << "\n--- Tambah Mata Pelajaran ---\n";
        cout << "Masukkan Kode Mapel: ";
        cin >> mp.kode;
        cin.ignore(); 

        
        if (cariIndeksBandaKode(mp.kode) != -1) {
            cout << "Gagal! Mata pelajaran dengan kode " << mp.kode << " sudah terdaftar.\n";
            return;
        }

        cout << "Masukkan Nama Mapel: ";
        getline(cin, mp.nama);
        cout << "Masukkan Jumlah SKS : ";
        cin >> mp.sks;

        daftarMapel.push_back(mp);
        cout << "Mata pelajaran berhasil ditambahkan!\n";
    }

    
    void tampilkanMapel() {
        cout << "\n--- Daftar Mata Pelajaran ---\n";
        if (daftarMapel.empty()) {
            cout << "Belum ada mata pelajaran yang terdaftar.\n";
            return;
        }

        cout << "--------------------------------------------------\n";
        cout << "| No | Kode Mapel | Nama Mata Pelajaran | SKS |\n";
        cout << "--------------------------------------------------\n";
        for (size_t i = 0; i < daftarMapel.size(); ++i) {
            cout << "| " << i + 1 << "  | " 
                 << daftarMapel[i].kode << "\t  | " 
                 << daftarMapel[i].nama << "\t\t| " 
                 << daftarMapel[i].sks << "   |\n";
        }
        cout << "--------------------------------------------------\n";
    }

    
    void ubahMapel() {
        cout << "\n--- Ubah Mata Pelajaran ---\n";
        if (daftarMapel.empty()) {
            cout << "Daftar masih kosong.\n";
            return;
        }

        string kode;
        cout << "Masukkan Kode Mapel yang ingin diubah: ";
        cin >> kode;

        int indeks = cariIndeksBandaKode(kode);
        if (indeks == -1) {
            cout << "Mata pelajaran dengan kode " << kode << " tidak ditemukan.\n";
        } else {
            cin.ignore();
            cout << "Masukkan Nama Baru : ";
            getline(cin, daftarMapel[indeks].nama);
            cout << "Masukkan SKS Baru  : ";
            cin >> daftarMapel[indeks].sks;
            cout << "Data mata pelajaran berhasil diperbarui!\n";
        }
    }

    
    void hapusMapel() {
        cout << "\n--- Hapus Mata Pelajaran ---\n";
        if (daftarMapel.empty()) {
            cout << "Daftar masih kosong.\n";
            return;
        }

        string kode;
        cout << "Masukkan Kode Mapel yang ingin dihapus: ";
        cin >> kode;

        int indeks = cariIndeksBandaKode(kode);
        if (indeks == -1) {
            cout << "Mata pelajaran dengan kode " << kode << " tidak ditemukan.\n";
        } else {
            daftarMapel.erase(daftarMapel.begin() + indeks);
            cout << "Mata pelajaran dengan kode " << kode << " berhasil dihapus.\n";
        }
    }

    
    void cariMapel() {
        cout << "\n--- Cari Mata Pelajaran ---\n";
        if (daftarMapel.empty()) {
            cout << "Daftar masih kosong.\n";
            return;
        }

        string keyword;
        cout << "Masukkan Kode atau Nama Mapel yang dicari: ";
        cin.ignore();
        getline(cin, keyword);

        bool ditemukan = false;
        cout << "\nHasil Pencarian:\n";
        for (const auto& mp : daftarMapel) {
            
            if (mp.kode == keyword || mp.nama.find(keyword) != string::npos) {
                cout << "- [" << mp.kode << "] " << mp.nama << " (" << mp.sks << " SKS)\n";
                ditemukan = true;
            }
        }

        if (!ditemukan) {
            cout << "Mata pelajaran tidak ditemukan.\n";
        }
    }
};
