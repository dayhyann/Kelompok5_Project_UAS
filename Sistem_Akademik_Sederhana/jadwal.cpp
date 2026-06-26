#include "jadwal.h"
#include <iostream>

using namespace std;
Jadwal* headJadwal = NULL;

//Hitung Jadwal
int hitungJadwal() {
	if (headJadwal == NULL)
	return 0;
	
	int jumlah = 0;
	Jadwal* temp = headJadwal;
	
	do {
		jumlah++;
		temp = temp->next;
	} while (temp != headJadwal);
	
	return jumlah;
}

//Tambah Jadwal
void tambahJadwal() {
	Jadwal* baru = new Jadwal();
	
	cin.ignore();
	
	cout << "\nHari            : ";
	getline(cin, baru->hari);
	
	cout << "Jam             : ";
	getline(cin, baru->jam);
	
	cout << "Mata Pelajaran  : ";
	getline(cin, baru->mataPelajaran);
	
	cout << "Ruang Kelas     : ";
	getline(cin, baru->ruangKelas);
	
	if (headJadwal == NULL) {
		headJadwal = baru;
		baru->next = baru;
		baru->prev = baru;
	} else {
		Jadwal* tail = headJadwal->prev;
		
		tail->next = baru;
		baru->prev = tail;
		
		baru->next = headJadwal;
		headJadwal->prev = baru;
	}
	
	cout << "\nJadwal berhasil ditambahkan!\n";
}

//Tampilkan Jadwal
void tampilJadwal() {
	if (headJadwal == NULL) {
		cout << "\nData jadwal kosong!\n";
		return;
	}
	
	Jadwal* temp = headJadwal;
	int no = 1;
	
	cout << "\n===== DATA JADWAL =====\n";
	
	do {
		cout << "\nJadwal Ke-" << no++ << endl;
		cout << "\nHari           : " << temp->hari << endl;
		cout << "Jam            : " << temp->jam << endl;
		cout << "Mata Pelajaran : " << temp->mataPelajaran << endl;
		cout << "Ruang Kelas    : " << temp->ruangKelas << endl;
		
		temp = temp->next;
		
	} while (temp != headJadwal);
}

//Edit Jadwal
void editJadwal() {
	if (headJadwal == NULL) {
		cout << "\nData jadwal kosong!\n";
		return;
	}
	
	int nomor;
	tampilJadwal();
	
	cout << "\nPilih nomor jadwal yang akan diedit : ";
	cin >> nomor;
	
	if (nomor < 1 || nomor > hitungJadwal()) {
		cout << "\nNomor tidak valid!\n";
		return;
	}
	
	Jadwal* temp = headJadwal;
	
	for (int i = 1; i < nomor; i++) {
		temp = temp->next;
	}
	
	cin.ignore();
	
	cout << "\nHari Baru           : ";
	getline(cin, temp->hari);
	
	cout << "Jam Baru            : ";
	getline(cin, temp->jam);
	
	cout << "Mata Pelajaran Baru : ";
	getline(cin, temp->mataPelajaran);
	
	cout << "Ruang Kelas Baru    : ";
	getline(cin, temp->ruangKelas);
	
	cout << "\nData berhasil diedit!\n";
}

//Hapus Jadwal
void hapusJadwal() {
	if (headJadwal == NULL) {
		cout << "\nData jadwal kosong!\n";
		return;
	}
	
	int nomor;
	tampilJadwal();
	
	cout <<"\nPilih nomor yang akan dihapus : ";
	cin >> nomor;
	
	if (nomor < 1 || nomor > hitungJadwal()) {
		cout << "\nNomor tidak valid!\n";
		return;
	}
	
	Jadwal* hapus = headJadwal;
	
	for (int i = 1; i < nomor; i++) {
		hapus = hapus->next;
	}
	
	//Jika hanya ada 1 Jadwal
	if (hapus->next == hapus) {
		headJadwal = NULL;
	} else {
		hapus->prev->next = hapus->next;
		hapus->next->prev = hapus->prev;
		
		if (hapus == headJadwal) {
			headJadwal = hapus->next;
		}
	}
	
	delete hapus;
	
	cout << "\nData berhasil dihapus!\n";
}

void menuJadwal() {
	int pilihan;
	
	do {
		cout << "\n===== MENU DATA JADWAL =====\n";
		cout << "1. Tambah Jadwal\n";
		cout << "2. Edit Jadwal\n";
		cout << "3. Hapus Jadwal\n";
		cout << "4. Tampilkan Jadwal\n";
		cout << "0. Keluar\n";
		cout << "Pilihan : ";
		cin >> pilihan;
		
		switch (pilihan) {
			case 1:
				tambahJadwal();
				break;
				
			case 2:
				editJadwal();
				break;
				
			case 3:
				hapusJadwal();
				break;
				
			case 4:
				tampilJadwal();
				break;
				
			case 0:
				cout << "\nProgram selesai.\n";
				break;
				
			default:
				cout << "\nPilihan tidak tersedia!\n";
		}
		
	} while (pilihan != 0);
	
}