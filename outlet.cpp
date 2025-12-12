#include "outlet.h"
#include "sales.h"

bool isOutletEmpty(Outlet Toko) {
    return Toko.count == 0;
}

bool isOutletFull(Outlet Toko) {
    return Toko.count == max_item;
}


int findItemIndex(Outlet Toko, string namaBarang) {
    for (int i = 0; i < Toko.count; i++) {
        if (Toko.barang[i].name == namaBarang) {
            return i;
        }
    }
    return -1;
}

void insertItem(Outlet &Toko, string namaBarang, int stokAwal) {
    if (isOutletFull(Toko)) {
        cout << "Gagal: Gudang " << Toko.nama << " penuh!" << endl;
    } else {
        int index = Toko.count;
        Toko.barang[index].name = namaBarang;
        Toko.barang[index].stock = stokAwal;
        Toko.count++;
        cout << "Berhasil menambahkan: " << namaBarang << endl;
    }
}

void viewOutlet(Outlet Toko) {
    cout << "\n--- Data Outlet: " << Toko.nama << " ---" << endl;
    cout << "Lokasi: " << Toko.location << endl;
    cout << "PIC: " << Toko.pic << endl;

    if (isOutletEmpty(Toko)) {
        cout << "Status: Tidak ada barang." << endl;
    } else {
        cout << "Daftar Barang (" << Toko.count << " item):" << endl;
        for (int i = 0; i < Toko.count; i++) {
            cout << i + 1 << ". " << Toko.barang[i].name
                 << " (Stok: " << Toko.barang[i].stock << ")" << endl;
        }
    }
    cout << "---------------------------" << endl;
}

void updateStock(Outlet &Toko, string namaBarang, int stokBaru) {
    int idx = findItemIndex(Toko, namaBarang);
    if (idx != -1) {
        Toko.barang[idx].stock = stokBaru;
        cout << "Stok " << namaBarang << " berhasil diupdate menjadi " << stokBaru << endl;
    } else {
        cout << "Error: Barang " << namaBarang << " tidak ditemukan." << endl;
    }
}


void deleteItem(Outlet &Toko, string namaBarang) {
    int idx = findItemIndex(Toko, namaBarang);
    if (idx == -1) {
        cout << "Error: Barang tidak ditemukan, gagal hapus." << endl;
        return;
    }
    for (int i = idx; i < Toko.count - 1; i++) {
        Toko.barang[i] = Toko.barang[i + 1];
    }

    Toko.count--;
    cout << "Barang " << namaBarang << " berhasil dihapus." << endl;
}
