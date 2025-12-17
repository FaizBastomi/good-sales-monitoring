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
        cout << "6. Cari Berdasarkan Insentif" << endl;
        cout << "7. Cari Berdasarkan Jumlah Outlet" << endl;
        cout << "8. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> choice;

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
            cout << "=== Daftar Semua Sales ===" << endl;
            displaySales(root);
            cout << "Tekan enter untuk kembali ke menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 5:
        {
            cout << "=== Cari Sales Berdasarkan Nama ===" << endl;
            string nama = getNonEmptyInput("Masukkan nama Sales yang dicari: ");
            adrSales p = searchSalesByName(root, nama);
            if (p != nullptr)
            {
                cout << "Data Sales ditemukan:" << endl;
                cout << "ID: " << p->id << ", Nama: " << p->info.nama << ", Contact Info: "
                     << p->info.contact_info << ", Insentif Fee: " << p->info.insentif_fee << endl;
            }
            else
            {
                cout << "Sales dengan nama: " << nama << " tidak ditemukan." << endl;
            }
            break;
        }
        case 6:
        {
            cout << "=== Cari Sales Berdasarkan Insentif ===" << endl;
            int min_insentif = getIntInput("Masukkan nilai insentif minimum: ");
            int max_insentif = getIntInput("Masukkan nilai insentif maksimum: ");
            searchSalesByInsentif(root, min_insentif, max_insentif, results);
            if (!results.empty())
            {
                cout << "Sales yang ditemukan:" << endl;
                for (auto &sales : results)
                {
                    cout << "ID: " << sales->id << ", Nama: " << sales->info.nama
                         << ", Insentif Fee: " << sales->info.insentif_fee << endl;
                }
            }
            else
            {
                cout << "Tidak ada Sales yang ditemukan dalam rentang insentif tersebut." << endl;
            }
            break;
        }
        case 7:
        {
            cout << "=== Cari Sales Berdasarkan Jumlah Outlet ===" << endl;
            int min_outlet = getIntInput("Masukkan jumlah outlet minimum: ");
            searchSalesByOutlet(root, min_outlet, results);
            if (!results.empty())
            {
                cout << "Sales yang ditemukan:" << endl;
                for (auto &sales : results)
                {
                    cout << "ID: " << sales->id << ", Nama: " << sales->info.nama
                         << ", Jumlah Outlet: " << sales->info.outletCount << endl;
                }
            }
            else
            {
                cout << "Tidak ada Sales yang memiliki jumlah outlet minimal tersebut." << endl;
            }
            break;
        }
        }
        clearScreen();
    }
}

void tambahSales(adrSales &root)
{
    int id, insentif_fee;
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
    insentif_fee = getIntInput("Masukkan Insentif Fee Sales: ");

    adrSales newSales = createElmSales(id, nama, contact_info, insentif_fee);
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

    adrSales p = searchSalesByName(root, nama);
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

    adrSales p = searchSalesByName(root, nama);
    if (p != nullptr)
    {
        deleteSales(root, p);
        cout << "Berhasil menghapus data sales dengan nama: " << nama << endl;
    }
    else
    {
        cout << "Sales dengan nama: " << nama << " tidak ditemukan." << endl;
    }
}
