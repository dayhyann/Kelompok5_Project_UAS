#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;

string nama[MAX];
float nilai[MAX];
int jumlah = 0;

// Tambah Data
void tambahNilai() {
    cout << "\n=== TAMBAH NILAI ===\n";

    cout << "Nama  : ";
    cin >> nama[jumlah];

    cout << "Nilai : ";
    cin >> nilai[jumlah];

    jumlah++;

    cout << "Data berhasil ditambahkan!\n";
}

// Edit Data
void editNilai() {
    int no;

    if(jumlah == 0) {
        cout << "\nData masih kosong!\n";
        return;
    }

    cout << "\n=== EDIT NILAI ===\n";

    for(int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". "
             << nama[i]
             << " - "
             << nilai[i]
             << endl;
    }

    cout << "\nPilih nomor data : ";
    cin >> no;

    no--;

    cout << "Nama baru  : ";
    cin >> nama[no];

    cout << "Nilai baru : ";
    cin >> nilai[no];

    cout << "Data berhasil diubah!\n";
}

// Hapus Data
void hapusNilai() {
    int no;

    if(jumlah == 0) {
        cout << "\nData masih kosong!\n";
        return;
    }

    cout << "\n=== HAPUS NILAI ===\n";

    for(int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". "
             << nama[i]
             << " - "
             << nilai[i]
             << endl;
    }

    cout << "\nPilih nomor data : ";
    cin >> no;

    no--;

    for(int i = no; i < jumlah - 1; i++) {
        nama[i] = nama[i + 1];
        nilai[i] = nilai[i + 1];
    }

    jumlah--;

    cout << "Data berhasil dihapus!\n";
}

// Menentukan Grade
char grade(float n) {
    if(n >= 85)
        return 'A';
    else if(n >= 75)
        return 'B';
    else if(n >= 65)
        return 'C';
    else if(n >= 50)
        return 'D';
    else
        return 'E';
}

// Tampil Rekap
void tampilNilai() {

    if(jumlah == 0) {
        cout << "\nData masih kosong!\n";
        return;
    }

    cout << "\n============================================================\n";
    cout << "                    REKAP NILAI SISWA\n";
    cout << "============================================================\n";

    cout << left
         << setw(5)  << "No"
         << setw(20) << "Nama"
         << setw(10) << "Nilai"
         << setw(10) << "Grade"
         << setw(10) << "Status"
         << endl;

    for(int i = 0; i < jumlah; i++) {

        cout << left
             << setw(5) << i + 1
             << setw(20) << nama[i]
             << setw(10) << nilai[i]
             << setw(10) << grade(nilai[i]);

        if(nilai[i] >= 75)
            cout << setw(10) << "Lulus";
        else
            cout << setw(10) << "Tidak";

        cout << endl;
    }
}

// Menu
void menuNilai() {

    int pilih;

    do {
        cout << "    \n===================== MENU NILAI SISWA =====================\n";
        cout << "1. Tambah Nilai\n";
        cout << "2. Edit Nilai\n";
        cout << "3. Hapus Nilai\n";
        cout << "4. Tampil Rekap\n";
        cout << "5. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch(pilih) {

            case 1:
                tambahNilai();
                break;

            case 2:
                editNilai();
                break;

            case 3:
                hapusNilai();
                break;

            case 4:
                tampilNilai();
                break;

            case 5:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
        }

    } while(pilih != 5);
}

int main() {

    menuNilai();

    return 0;
}