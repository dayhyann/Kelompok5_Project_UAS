#include <iostream>
#include <string>
using namespace std;

struct Jadwal {
	string hari;
	string jam;
	string mataPelajaran;
	string ruangKelas;
	
	Jadwal* next;
	Jadwal* prev;
};

Jadwal* head = NULL;

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
	
	if (head == NULL) {
		head = baru;
		baru->next = baru;
		baru->prev = baru;
	} else {
		Jadwal* tail = head->prev;
		
		tail->next = baru;
		baru->prev = tail;
		
		baru->next = head;
		head->prev = baru;
	}
	
	cout << "\nJadwal berhasil ditambahkan!\n";
}

//Tampilkan Jadwal
void tampilJadwal() {
	if (head == NULL) {
		cout << "\nData jadwal kosong!\n";
		return;
	}
	
	Jadwal* temp = head;
	int no = 1;
	
	cout << "\n===== DATA JADWAL =====\n";
	
	do {
		cout << "\nJadwal Ke-" << no++ << endl;
		cout << "\nHari           : " << temp->hari << endl;
		cout << "Jam            : " << temp->jam << endl;
		cout << "Mata Pelajaran : " << temp->mataPelajaran << endl;
		cout << "Ruang Kelas    : " << temp->ruangKelas << endl;
		
		temp = temp->next;
		
	} while (temp != head);
}

//Edit Jadwal
void editJadwal() {
	if (head == NULL) {
		cout << "\nData jadwal kosong!\n";
		return;
	}
	
	int nomor;
	tampilJadwal();
	
	cout << "\nPilih nomor jadwal yang akan diedit : ";
	cin >> nomor;
	
	Jadwal* temp = head;
	
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
	if (head == NULL) {
		cout << "\nData jadwal kosong!\n";
		return;
	}
	
	int nomor;
	tampilJadwal();
	
	cout <<"\nPilih nomor yang akan dihapus : ";
	cin >> nomor;
	
	Jadwal* hapus = head;
	
	for (int i = 1; i < nomor; i++) {
		hapus = hapus->next;
	}
	
	//Jika hanya ada 1 Jadwal
	if (hapus->next == hapus) {
		head = NULL;
	} else {
		hapus->prev->next = hapus->next;
		hapus->next->prev = hapus->prev;
		
		if (hapus == head) {
			head = hapus->next;
		}
	}
	
	delete hapus;
	
	cout << "\nData berhasil dihapus!\n";
}

int main() {
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
	
	return 0;
}
