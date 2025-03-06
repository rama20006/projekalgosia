#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Kendaraan {
    string nomor_plat;
    string jenis;
    string merk;
    string model;
    string nama_pemilik;
    int tahun_produksi;
};

vector<Kendaraan> database;

void inputData() {
    Kendaraan k;
    cout << "Masukkan Nomor Plat: "; cin >> k.nomor_plat;
    cout << "Masukkan Jenis Kendaraan (Mobil/Motor): "; cin >> k.jenis;
    cout << "Masukkan Merk Kendaraan: "; cin >> k.merk;
    cout << "Masukkan Model Kendaraan: "; cin >> k.model;
    cout << "Masukkan Nama Pemilik: "; cin >> k.nama_pemilik;
    cout << "Masukkan Tahun Produksi: "; cin >> k.tahun_produksi;
    database.push_back(k);
}

void tampilkanData() {
    if (database.empty()) {
        cout << "Tidak ada data kendaraan.\n";
        return;
    }
    cout << "====================================================================================\n";
    cout << "| No | Plat       | Jenis   | Merk      | Model     | Pemilik       | Tahun |\n";
    cout << "====================================================================================\n";
    int i = 1;
    for (const auto& k : database) {
        cout << "| " << setw(2) << i++ << " | "
             << setw(10) << k.nomor_plat << " | "
             << setw(7) << k.jenis << " | "
             << setw(9) << k.merk << " | "
             << setw(9) << k.model << " | "
             << setw(13) << k.nama_pemilik << " | "
             << setw(5) << k.tahun_produksi << " |" << endl;
}
}

void bubbleSort() {
    int n = database.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (database[j].tahun_produksi > database[j + 1].tahun_produksi) {
                swap(database[j], database[j + 1]);
            }
        }
    }
    cout << "Data kendaraan berhasil diurutkan menggunakan Bubble Sort.\n";
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = database[high].tahun_produksi;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (database[j].tahun_produksi < pivot) {
                i++;
                swap(database[i], database[j]);
            }
        }
        swap(database[i + 1], database[high]);
        int pi = i + 1;
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void sortQuick() {
    quickSort(0, database.size() - 1);
    cout << "Data kendaraan berhasil diurutkan menggunakan Quick Sort.\n";
}

void sequentialSearch() {
    string cari;
    cout << "Masukkan nama pemilik yang ingin dicari: ";
    cin >> cari;
    bool ditemukan = false;
    for (const auto& k : database) {
        if (k.nama_pemilik == cari) {
            cout << "Plat: " << k.nomor_plat << ", Jenis: " << k.jenis << ", Merk: " << k.merk
                 << ", Model: " << k.model << ", Pemilik: " << k.nama_pemilik
                 << ", Tahun: " << k.tahun_produksi << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "=== Menu ===\n";
        cout << "1. Input Data Kendaraan\n";
        cout << "2. Tampilkan Seluruh Data Kendaraan\n";
        cout << "3. Urutkan Data Kendaraan (Bubble Sort)\n";
        cout << "4. Urutkan Data Kendaraan (Quick Sort)\n";
        cout << "5. Cari Data Kendaraan (Sequential Search)\n";
        cout << "6. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilkanData(); break;
            case 3: bubbleSort(); break;
            case 4: sortQuick(); break;
            case 5: sequentialSearch(); break;
            case 6: cout << "Terima kasih!"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);
    
    return 0;
}
