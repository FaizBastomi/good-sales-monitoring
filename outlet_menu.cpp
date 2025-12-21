#include "Header/outlet_menu.h"
#include "Header/utils.h"
#include "Header/sales.h"
#include "Header/outlet.h"
#include <iostream>
using namespace std;

void tampilkanStatistik(Outlet Toko)
{
    if (isItemEmpty(Toko))
    {
        cout << "Data barang kosong. Statistik tidak tersedia." << endl;
        return;
    }

    cout << "\n--- Statistik Outlet: " << Toko.nama << " ---" << endl;
    cout << "Total Aset (Valuasi): Rp " << countTotalAsset(Toko) << endl;
    cout << "Rata-rata Stok: " << calculateAverageStock(Toko) << " item" << endl;

    int maxIdx = findMaxStockIndex(Toko);
    if (maxIdx != -1)
    {
        cout << "Barang Stok Tertinggi: " << Toko.barang[maxIdx].name
             << " (" << Toko.barang[maxIdx].stock << ")" << endl;
    }

    int minIdx = findMinStockIndex(Toko);
    if (minIdx != -1)
    {
        cout << "Barang Stok Terendah: " << Toko.barang[minIdx].name
             << " (" << Toko.barang[minIdx].stock << ")" << endl;
    }
    cout << "-----------------------------------" << endl;
}

void outletMenu(adrSales &root)
{
    int choice;
    clearScreen();
    choice = 0;
    while (choice != 4)
    {
        cout << "=== MENU OUTLET ===" << endl;
        cout << "1. Tambah Outlet Baru" << endl;
        cout << "2. Cari & Kelola Outlet" << endl;
        cout << "3. Hapus Outlet" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            menuTambahOutlet(root);
            break;
        case 2:
            cariDanKelolaOutlet(root);
            break;
        case 3:
            hapusOutlet(root);
            break;
        }
        clearScreen();
    }
}

void cariDanKelolaOutlet(adrSales &root)
{
    string namaOutlet;
    clearScreen();
    cout << "=== Cari & Kelola Outlet ===" << endl;

    while (true)
    {
        cout << "\nKetik 'Kembali' untuk keluar." << endl;
        namaOutlet = getNonEmptyInput("Masukkan Nama Outlet yang dicari: ");
        if (namaOutlet == "Kembali")
        {
            break;
        }
        adrSales salesNode = getSalesByOutletName(root, namaOutlet);

        if (salesNode != nullptr)
        {
            int idx = findOutletIndex(salesNode, namaOutlet);
            if (idx != -1)
            {
                cout << "Outlet ditemukan! Pemilik: " << salesNode->info.nama << endl;
                menuKelolaOutlet(salesNode, idx, root);
                clearScreen();
                cout << "=== Cari & Kelola Outlet ===" << endl;
            }
            else
            {
                cout << "Error: Index outlet tidak ditemukan." << endl;
            }
        }
        else
        {
            cout << "Outlet '" << namaOutlet << "' tidak ditemukan. Coba lagi." << endl;
        }
    }
}

void menuKelolaOutlet(adrSales salesNode, int outletIdx, adrSales &root)
{
    Outlet &toko = salesNode->info.outlet[outletIdx];
    int choice = 0;

    while (choice != 9)
    {
        cout << "\n--- Mengelola Outlet: " << toko.nama << " ---" << endl;
        cout << "1. Lihat Detail & Barang" << endl;
        cout << "2. Tambah Barang" << endl;
        cout << "3. Update Stok Barang" << endl;
        cout << "4. Update Harga Barang" << endl;
        cout << "5. Hapus Barang" << endl;
        cout << "6. Cek Barang Low Stock" << endl;
        cout << "7. Update Info Outlet (PIC/Lokasi)" << endl;
        cout << "8. Tampilkan Statistik" << endl;
        cout << "9. Kembali" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewOutlet(toko);
            break;
        case 2:
        {
            string namaBarang = getNonEmptyInput("Nama Barang: ");
            int stok = getIntInput("Stok Awal: ");
            int harga = getIntInput("Harga Satuan (Rp): ");
            insertItem(toko, namaBarang, stok, harga);
            break;
        }
        case 3:
        {
            string namaBarang = getNonEmptyInput("Nama Barang update stok: ");
            int stok = getIntInput("Stok Baru: ");
            updateStock(toko, namaBarang, stok);
            break;
        }
        case 4:
        {
            string namaBarang = getNonEmptyInput("Nama Barang update harga: ");
            int harga = getIntInput("Harga Baru (Rp): ");
            updatePrice(toko, namaBarang, harga);
            break;
        }
        case 5:
        {
            string namaBarang = getNonEmptyInput("Nama Barang hapus: ");
            deleteItem(toko, namaBarang);
            break;
        }
        case 6:
        {
            int limit = getIntInput("Masukkan batas stok: ");
            viewLowStockItems(toko, limit);
            break;
        }
        case 7:
        {
            cout << "PIC Lama: " << toko.pic << endl;
            string newPic = getStringInput("PIC Baru (enter skip): ");
            if (!newPic.empty())
                toko.pic = newPic;

            cout << "Lokasi Lama: " << toko.location << endl;
            string newLoc = getStringInput("Lokasi Baru (enter skip): ");
            if (!newLoc.empty())
                toko.location = newLoc;
            break;
        }
        case 8:
            tampilkanStatistik(toko);
            break;
        }

        if (choice != 9)
        {
            cout << "Tekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
        }
    }
}

void menuTambahOutlet(adrSales &root)
{
    clearScreen();
    cout << "=== Tambah Outlet Baru ===" << endl;
    string namaSales = getNonEmptyInput("Masukkan Nama Sales pemilik: ");
    adrSales s = searchSales(root, namaSales);

    if (s != nullptr)
    {
        string namaOutlet = getNonEmptyInput("Nama Outlet: ");
        string pic = getNonEmptyInput("Nama PIC: ");
        string lokasi = getNonEmptyInput("Lokasi: ");

        insertNewOutlet(root, s, namaOutlet, pic, lokasi);
    }
    else
    {
        cout << "Sales tidak ditemukan. Pastikan nama sales benar." << endl;
    }
    cout << "Tekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void hapusOutlet(adrSales &root)
{
    clearScreen();
    cout << "=== Hapus Outlet ===" << endl;
    string name = getNonEmptyInput("Masukkan Nama Outlet yang akan dihapus: ");

    adrSales salesNode = getSalesByOutletName(root, name);
    if (salesNode != nullptr)
    {
        deleteOutlet(salesNode, name);
        cout << "Berhasil menghapus outlet dengan nama: " << name << endl;
        cout << "Tekan enter untuk kembali...";
        cin.ignore();
        cin.get();
    }
    else
    {
        cout << "Outlet dengan nama: " << name << " tidak ditemukan." << endl;
        cout << "Tekan enter untuk kembali...";
        cin.ignore();
        cin.get();
    }
}