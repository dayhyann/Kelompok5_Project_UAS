#include <iostream>
#include <string>
#include <iomanip> // Diperlukan untuk merapikan tampilan tabel (setw)
#include <limits>  // Diperlukan untuk membersihkan buffer secara total

using namespace std;

// 1. STRUKTUR DATA
struct MataPelajaran {
    string kode;
    string nama;
    int sks;
};

// Node untuk Singly Linked List
struct Node {
    MataPelajaran data;
    Node* next;
};

// 2. KELAS PENGELOLA MATA PELAJARAN
class PengelolaMapel {
private:
    Node* head;

    // Fungsi helper untuk mengubah string menjadi huruf kecil (agar validasi tidak sensitif caps lock)
    string keHurufKecil(string str) {
        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }

    // Pengecekan apakah Kode Mapel sudah terdaftar
    Node* cariBerdasarkanKode(string kode) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.kode == kode) {
                return current; 
            }
            current = current->next;
        }
        return nullptr;
    }

    // Pengecekan apakah Nama Mapel sudah ada (Validasi Duplikasi Nama)
    bool apakahNamaSudahAda(string nama, string kodeAbaikan = "") {
        Node* current = head;
        while (current != nullptr) {
            if (!kodeAbaikan.empty() && current->data.kode == kodeAbaikan) {
                current = current->next;
                continue;
            }
            if (keHurufKecil(current->data.nama) == keHurufKecil(nama)) {
                return true; 
            }
            current = current->next;
        }
        return false;
    }

    // Fungsi sakti untuk membersihkan sisa enter di keyboard secara total
    void bersihkanBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    // Constructor
    PengelolaMapel() {
        head = nullptr;
    }

    // Destructor untuk membersihkan memori dari RAM ketika program ditutup
    ~PengelolaMapel() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // FITUR 1: MENAMBAHKAN MATA PELAJARAN (Insert Last)
    void tambahMapel() {
        MataPelajaran mp;
        cout << "\n--- Tambah Mata Pelajaran ---\n";
        cout << "Masukkan Kode Mapel : ";
        cin >> mp.kode;
        bersihkanBuffer(); // Bersihkan buffer setelah cin >>

        // Validasi KODE tidak boleh sama
        if (cariBerdasarkanKode(mp.kode) != nullptr) {
            cout << "Gagal! Kode Mapel '" << mp.kode << "' sudah digunakan.\n";
            return;
        }

        cout << "Masukkan Nama Mapel : ";
        getline(cin, mp.nama);

        // Validasi NAMA tidak boleh sama
        if (apakahNamaSudahAda(mp.nama)) {
            cout << "Gagal! Mata pelajaran '" << mp.nama << "' sudah ada di sistem.\n";
            return;
        }

        cout << "Masukkan Jumlah SKS : ";
        while (!(cin >> mp.sks)) { // Validasi jika user salah ketik huruf pada SKS
            cout << "Input salah! Masukkan angka untuk SKS: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        bersihkanBuffer(); // Bersihkan buffer setelah cin >>

        // Alokasi Node Baru
        Node* newNode = new Node();
        newNode->data = mp;
        newNode->next = nullptr;

        // Jika Linked List masih kosong
        if (head == nullptr) {
            head = newNode;
        } else {
            // Iterasi mencari node paling ujung/terakhir
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode; // Sambungkan node baru di akhir
        }
        cout << "Mata pelajaran berhasil ditambahkan!\n";
    }

    // FITUR 2: MENAMPILKAN SEMUA MATA PELAJARAN (Traversal)
    void tampilkanMapel() {
        cout << "\n--- Daftar Mata Pelajaran ---\n";
        if (head == nullptr) {
            cout << "Belum ada mata pelajaran yang terdaftar.\n";
            return;
        }

        // Membuat format kolom tabel yang presisi dan rapi
        cout << "---------------------------------------------------------\n";
        cout << "| " << left << setw(4) << "No" 
             << "| " << setw(12) << "Kode Mapel" 
             << "| " << setw(25) << "Nama Mata Pelajaran" 
             << "| " << setw(5) << "SKS" << " |\n";
        cout << "---------------------------------------------------------\n";
        
        Node* current = head;
        int no = 1;
        
        while (current != nullptr) {
            cout << "| " << left << setw(4) << no 
                 << "| " << setw(12) << current->data.kode 
                 << "| " << setw(25) << current->data.nama 
                 << "| " << setw(5) << current->data.sks << " |\n";
            
            current = current->next; // Pindah ke node berikutnya
            no++;
        }
        cout << "---------------------------------------------------------\n";
    }

    // FITUR 3: MENGUBAH MATA PELAJARAN
    void ubahMapel() {
        cout << "\n--- Ubah Mata Pelajaran ---\n";
        if (head == nullptr) {
            cout << "Daftar masih kosong.\n";
            return;
        }

        string kode;
        cout << "Masukkan Kode Mapel yang ingin diubah: ";
        cin >> kode;
        bersihkanBuffer();

        Node* targetNode = cariBerdasarkanKode(kode);
        if (targetNode == nullptr) {
            cout << "Mata pelajaran dengan kode '" << kode << "' tidak ditemukan.\n";
        } else {
            string namaBaru;
            cout << "Masukkan Nama Baru : ";
            getline(cin, namaBaru);

            if (apakahNamaSudahAda(namaBaru, kode)) {
                cout << "Gagal! Nama '" << namaBaru << "' sudah dipakai oleh kode mapel lain.\n";
                return;
            }

            targetNode->data.nama = namaBaru;
            cout << "Masukkan SKS Baru  : ";
            while (!(cin >> targetNode->data.sks)) {
                cout << "Input salah! Masukkan angka untuk SKS: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            bersihkanBuffer();
            cout << "Data mata pelajaran berhasil diperbarui!\n";
        }
    }

    // FITUR 4: MENGHAPUS MATA PELAJARAN (Delete Node)
    void hapusMapel() {
        cout << "\n--- Hapus Mata Pelajaran ---\n";
        if (head == nullptr) {
            cout << "Daftar masih kosong.\n";
            return;
        }

        string kode;
        cout << "Masukkan Kode Mapel yang ingin dihapus: ";
        cin >> kode;
        bersihkanBuffer();

        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data.kode == kode) {
            head = temp->next;
            delete temp;
            cout << "Mata pelajaran dengan kode '" << kode << "' berhasil dihapus.\n";
            return;
        }

        while (temp != nullptr && temp->data.kode != kode) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Mata pelajaran dengan kode '" << kode << "' tidak ditemukan.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Mata pelajaran dengan kode '" << kode << "' berhasil dihapus.\n";
    }

    // FITUR 5: MENCARI MATA PELAJARAN
    void cariMapel() {
        cout << "\n--- Cari Mata Pelajaran ---\n";
        if (head == nullptr) {
            cout << "Daftar masih kosong.\n";
            return;
        }

        string keyword;
        cout << "Masukkan Kode atau Nama Mapel: ";
        getline(cin, keyword);

        bool ditemukan = false;
        string keywordLower = keHurufKecil(keyword);
        
        cout << "\nHasil Pencarian:\n";
        Node* current = head;
        while (current != nullptr) {
            string namaLower = keHurufKecil(current->data.nama);
            string kodeLower = keHurufKecil(current->data.kode);

            if (kodeLower == keywordLower || namaLower.find(keywordLower) != string::npos) {
                cout << "- [" << current->data.kode << "] " << current->data.nama << " (" << current->data.sks << " SKS)\n";
                 ditemukan = true;
            }
            current = current->next;
        }

        if (!ditemukan) {
            cout << "Mata pelajaran tidak ditemukan.\n";
        }
    }
};

// 3. MAIN FUNCTION
int main() {
    PengelolaMapel app;
    int pilihan;

    do {
        cout << "\n==================================\n";
        cout << "    SISTEM MANAJEMEN MAPEL (LL)   \n";
        cout << "==================================\n";
        cout << "1. Tambah Mata Pelajaran\n";
        cout << "2. Tampilkan Semua Mata Pelajaran\n";
        cout << "3. Ubah Mata Pelajaran\n";
        cout << "4. Hapus Mata Pelajaran\n";
        cout << "5. Cari Mata Pelajaran\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        
        if (!(cin >> pilihan)) {
            cout << "Masukkan harus berupa angka!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: app.tambahMapel(); break;
            case 2: app.tampilkanMapel(); break;
            case 3: app.ubahMapel(); break;
            case 4: app.hapusMapel(); break;
            case 5: app.cariMapel(); break;
            case 6: cout << "Terima kasih! Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
