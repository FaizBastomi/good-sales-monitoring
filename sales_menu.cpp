#include "Header/sales_menu.h"
#include "Header/sales.h"
#include "Header/utils.h"
#include <vector>

void salesMenu(adrSales &root)
{
    int choice;
    vector<adrSales> results;

    clearScreen();
    choice = 0;
    while (choice != 8)
    {
        cout << "=== Menu Sales ===" << endl;
        cout << "1. Tambah Sales" << endl;
        cout << "2. Ubah Data Sales" << endl;
        cout << "3. Hapus Sales" << endl;
        cout << "4. Tampilkan Semua Sales" << endl;
        cout << "5. Cari Berdasarkan Nama" << endl;
        cout << "6. Cari Berdasarkan Insentif dan Minimum Outlet" << endl;
        cout << "7. Tampilkan Statistik Sales" << endl;
        cout << "8. Kembali ke Menu Utama" << endl;
        choice = getIntInput("Pilihan: ");

        switch (choice)
        {
        case 1:
            tambahSales(root);
            break;
        case 2:
            ubahDataSales(root);
            break;
        case 3:
            hapusSales(root);
            break;
        case 4:
            clearScreen();
            if (root == nullptr)
            {
                cout << "Tidak ada data sales." << endl;
                cout << "Tekan enter untuk kembali ke menu..." << endl;
                cin.ignore();
                cin.get();
            }
            else
            {
                displayMenu(root);
            }
            break;
        case 5:
        {
            cout << "=== Cari Sales Berdasarkan Nama ===" << endl;
            string nama = getNonEmptyInput("Masukkan nama Sales yang dicari: ");
            adrSales p = searchSales(root, nama);
            if (p != nullptr)
            {
                cout << "Data Sales ditemukan:" << endl;
                cout << "ID: " << p->id << ", Nama: " << p->info.nama << ", Contact Info: "
                     << p->info.contact_info << ", Insentif Fee: " << p->info.insentif_fee << endl;

                cout << "Tekan enter untuk kembali ke menu..." << endl;
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "Sales dengan nama: " << nama << " tidak ditemukan." << endl;
            }
            break;
        }
        case 6:
        {
            cout << "=== Cari Sales Berdasarkan Insentif dan Minimum Outlet ===" << endl;
            int min_insentif = getIntInput("Masukkan nilai minimum insentif: ");
            int max_insentif = getIntInput("Masukkan nilai maksimum insentif: ");
            int min_outlet = getIntInput("Masukkan jumlah minimum outlet: ");

            results.clear();
            searchSales(root, min_insentif, max_insentif, min_outlet, results);

            if (!results.empty())
            {
                cout << "Sales yang ditemukan:" << endl;
                for (adrSales p : results)
                {
                    cout << "ID: " << p->id << ", Nama: " << p->info.nama
                         << ", Insentif Fee: " << p->info.insentif_fee
                         << ", Jumlah Outlet: " << p->info.outletCount + 1 << endl;
                }
            }
            else
            {
                cout << "Tidak ada sales yang memenuhi kriteria pencarian." << endl;
            }
            cout << "Tekan enter untuk kembali ke menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        case 7:
            salesStatistics(root);
            break;
        }
        clearScreen();
    }
}

void salesStatistics(adrSales root)
{
    clearScreen();
    cout << "=== Statistik Sales ===" << endl;
    int totalOutlet = totalOutlets(root);
    int totalSales = countNodes(root);
    int totalIncentiveAmount = totalIncentive(root);
    float averageIncentiveAmount = averageIncentive(root);
    adrSales maxIncentiveSales = findMaxIncentive(root);
    adrSales minIncentiveSales = findMinIncentive(root);

    cout << "Total Sales: " << totalSales << endl;
    cout << "Total Outlet: " << totalOutlet << endl;
    cout << "Total Insentif Keseluruhan: Rp " << totalIncentiveAmount << endl;
    cout << "Rata-rata Insentif per Sales: Rp " << averageIncentiveAmount << endl;
    if (maxIncentiveSales != nullptr)
    {
        cout << "Sales dengan Insentif Tertinggi: " << maxIncentiveSales->info.nama
             << " (Rp " << maxIncentiveSales->info.insentif_fee << ")" << endl;
    }
    if (minIncentiveSales != nullptr)
    {
        cout << "Sales dengan Insentif Terendah: " << minIncentiveSales->info.nama
             << " (Rp " << minIncentiveSales->info.insentif_fee << ")" << endl;
    }

    cout << "Tekan enter untuk kembali ke menu..." << endl;
    cin.ignore();
    cin.get();
}

void tambahSales(adrSales &root)
{
    int id;
    string nama, contact_info;

    clearScreen();
    cout << "=== Tambah Sales ===" << endl;
    id = getIntInput("Masukkan ID Sales: ");
    while (isSalesIdExists(root, id))
    {
        cout << "ID sales sudah digunakan. Silakan gunakan ID lain." << endl;
        id = getIntInput("Masukkan ID Sales: ");
    }
    nama = getNonEmptyInput("Masukkan Nama Sales: ");
    contact_info = getNonEmptyInput("Masukkan Contact Info Sales: ");

    adrSales newSales = createElmSales(id, nama, contact_info);
    if (newSales != nullptr)
    {
        insertNewSales(root, newSales);
    }
}

void ubahDataSales(adrSales &root)
{
    int insentif_fee;
    string nama, contact_info;

    clearScreen();
    cout << "=== Ubah Data Sales ===" << endl;
    nama = getNonEmptyInput("Masukkan nama Sales yang akan diubah: ");

    adrSales p = searchSales(root, nama);
    if (p != nullptr)
    {
        contact_info = getStringInput("Masukkan Contact Info Sales baru (enter untuk melewati): ");
        insentif_fee = getIntInput("Masukkan Insentif Fee Sales baru (enter untuk melewati): ");

        if (contact_info.empty())
        {
            contact_info = p->info.contact_info;
        }
        if (insentif_fee == 0)
        {
            insentif_fee = p->info.insentif_fee;
        }

        updateSales(p, nama, contact_info, insentif_fee);
    }
    else
    {
        cout << "Sales dengan nama: " << nama << " tidak ditemukan." << endl;
    }
}

void hapusSales(adrSales &root)
{
    string nama;

    clearScreen();
    cout << "=== Hapus Sales ===" << endl;
    nama = getNonEmptyInput("Masukkan nama Sales yang akan dihapus: ");

    adrSales p = searchSales(root, nama);
    if (p != nullptr)
    {
        deleteSales(root, p);
        cout << "Berhasil menghapus data sales dengan nama: " << nama << endl;
    }
    else
    {
        cout << "Sales dengan nama: " << nama << " tidak ditemukan." << endl;
    }
    cout << "Tekan enter untuk kembali ke menu..." << endl;
    cin.ignore();
    cin.get();
}

void displayMenu(adrSales root)
{
    int choice;
    clearScreen();
    choice = 0;
    cout << "=== Mode Tampilan ===" << endl;
    cout << "1. In-Order" << endl;
    cout << "2. Pre-Order" << endl;
    cout << "3. Post-Order" << endl;
    choice = getIntInput("Pilih mode tampilan: ");

    clearScreen();
    cout << "=== Daftar Sales ===" << endl;
    displaySales(root, choice);
    cout << "Tekan enter untuk kembali ke menu..." << endl;
    cin.ignore();
    cin.get();
}