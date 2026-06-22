#include <iostream>
#include <string>
#include <iomanip> 
#include <limits>  

using namespace std;

struct MataPelajaran {
    string kode;
    string nama;
    int sks;
};

struct Node {
    MataPelajaran data;
    Node* next;
};

class PengelolaMapel {
private:
    Node* head;

    string keHurufKecil(string str) {
        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }

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

    void bersihkanBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    PengelolaMapel() {
        head = nullptr;
    }

    ~PengelolaMapel() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void tambahMapel() {
        MataPelajaran mp;
        cout << "\n--- Tambah Mata Pelajaran ---\n";
        cout << "Masukkan Kode Mapel : ";
        cin >> mp.kode;
        bersihkanBuffer(); 

        if (cariBerdasarkanKode(mp.kode) != nullptr) {
            cout << "Gagal! Kode Mapel '" << mp.kode << "' sudah digunakan.\n";
            return;
        }

        cout << "Masukkan Nama Mapel : ";
        getline(cin, mp.nama);

        if (apakahNamaSudahAda(mp.nama)) {
            cout << "Gagal! Mata pelajaran '" << mp.nama << "' sudah ada di sistem.\n";
            return;
        }

        cout << "Masukkan Jumlah SKS : ";
        while (!(cin >> mp.sks)) { 
            cout << "Input salah! Masukkan angka untuk SKS: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        bersihkanBuffer(); 

        Node* newNode = new Node();
        newNode->data = mp;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode; 
        }
        cout << "Mata pelajaran berhasil ditambahkan!\n";
    }

    void tampilkanMapel() {
        cout << "\n--- Daftar Mata Pelajaran ---\n";
        if (head == nullptr) {
            cout << "Belum ada mata pelajaran yang terdaftar.\n";
            return;
        }

        cout << "---------------------------------------------------------\n";
        cout << "| " << left << setw(4) << "No" 
             << "| " << setw(12) << "Kode Mapel" 
             << "| " << setw(25) << "Nama Mata Pelajaran" 
             << "| " << setw
