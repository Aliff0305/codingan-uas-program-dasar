#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Karyawan {
public:
    string nama;
    string jabatan;
    double gaji;

    Karyawan(string n, string j, double g) {
        nama = n;
        jabatan = j;
        gaji = g;
    }

    void tampilkanData() {
        cout << "Nama: " << nama << endl;
        cout << "Jabatan: " << jabatan << endl;
        cout << "Gaji: " << gaji << endl;
    }
};

class SistemManajemenTenagaKerja {
private:
    vector<Karyawan> karyawanList;

public:
    void tambahKaryawan() {
        string nama, jabatan;
        double gaji;
        
        cout << "Masukkan Nama Karyawan: ";
        cin.ignore(); 
        getline(cin, nama);
        cout << "Masukkan Jabatan Karyawan: ";
        getline(cin, jabatan);
        cout << "Masukkan Gaji Karyawan: ";
        cin >> gaji;

        Karyawan karyawanBaru(nama, jabatan, gaji);
        karyawanList.push_back(karyawanBaru);
        cout << "Karyawan berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaKaryawan() {
        if (karyawanList.empty()) {
            cout << "Tidak ada data karyawan!" << endl;
            return;
        }
        
        cout << "\nData Semua Karyawan:\n";
        for (size_t i = 0; i < karyawanList.size(); i++) {
            cout << "\nKaryawan " << i + 1 << ":\n";
            karyawanList[i].tampilkanData();
        }
    }

    void ubahDataKaryawan() {
        int index;
        cout << "Masukkan nomor karyawan yang ingin diubah (1 - " << karyawanList.size() << "): ";
        cin >> index;

        if (index < 1 || index > karyawanList.size()) {
            cout << "Nomor karyawan tidak valid!" << endl;
            return;
        }

        string nama, jabatan;
        double gaji;
        cout << "Masukkan Nama Baru: ";
        cin.ignore(); 
        getline(cin, nama);
        cout << "Masukkan Jabatan Baru: ";
        getline(cin, jabatan);
        cout << "Masukkan Gaji Baru: ";
        cin >> gaji;
        
        karyawanList[index - 1].nama = nama;
        karyawanList[index - 1].jabatan = jabatan;
        karyawanList[index - 1].gaji = gaji;

        cout << "Data karyawan berhasil diubah!" << endl;
    }
    
    void menu() {
        int pilihan;
        do {
            cout << "\n=== Menu Sistem Manajemen Tenaga Kerja ===\n";
            cout << "1. Tambah Karyawan\n";
            cout << "2. Tampilkan Semua Karyawan\n";
            cout << "3. Ubah Data Karyawan\n";
            cout << "4. Keluar\n";
            cout << "Pilih opsi: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambahKaryawan();
                    break;
                case 2:
                    tampilkanSemuaKaryawan();
                    break;
                case 3:
                    ubahDataKaryawan();
                    break;
                case 4:
                    cout << "Terima kasih, keluar dari program." << endl;
                    break;
                default:
                    cout << "Pilihan tidak benar, coba lagi!" << endl;
                    break;
            }
        } while (pilihan != 4);
    }
};

int main() {
    SistemManajemenTenagaKerja smtk;
    smtk.menu();
    return 0;
}
