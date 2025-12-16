#include "outlet.h"
#include "sales.h"

bool isItemEmpty(Outlet Toko) {
    return Toko.Item.count == 0;
}

bool isItemFull(Outlet Toko) {
    return Toko.Item.count == max_item;
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
int countTotalAsset(Outlet Toko) {
    int total = 0;
    for (int i = 0; i < Toko.count; i++) {
        total += Toko.barang[i].stock;
    }
    return total;
}

int findMaxStockIndex(Outlet Toko) {
    if (Toko.count == 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < Toko.count; i++) {
        if (Toko.barang[i].stock > Toko.barang[maxIdx].stock) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

int findMinStockIndex(Outlet Toko) {
    if (Toko.count == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < Toko.count; i++) {
        if (Toko.barang[i].stock < Toko.barang[minIdx].stock) {
            minIdx = i;
        }
    }
    return minIdx;
}

void viewLowStockItems(Outlet Toko, int limit) {
    cout << "Barang dengan stok di bawah " << limit << ":" << endl;
    bool found = false;
    for (int i = 0; i < Toko.count; i++) {
        if (Toko.barang[i].stock < limit) {
            cout << "- " << Toko.barang[i].name << " (Stok: " << Toko.barang[i].stock << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ada barang yang perlu restock." << endl;
}

double calculateAverageStock(Outlet Toko) {
    if (Toko.count == 0) return 0.0;
    return (double)countTotalAsset(Toko) / Toko.count;
}
