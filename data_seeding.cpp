#include "Header/data_seeding.h"
#include "Header/sales.h"
#include "Header/outlet.h"
#include <iostream>

using namespace std;

void startDataSeeding(adrSales &root)
{
    adrSales newSales;

    newSales = createElmSales(5, "Fujiati Keisha", "0208 2987 085");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Berkah Jaya", "Pak Budi", "Jl. Mawar No. 1");

    insertItem(newSales->info.outlet[0], "Beras 5kg", 20, 65000);
    insertItem(newSales->info.outlet[0], "Gula Pasir 1kg", 50, 16000);
    insertItem(newSales->info.outlet[0], "Minyak Goreng 2L", 30, 35000);
    insertItem(newSales->info.outlet[0], "Telur Ayam 1kg", 15, 28000);
    insertItem(newSales->info.outlet[0], "Mie Instan Soto", 100, 3500);
    insertItem(newSales->info.outlet[0], "Kopi Kapal Api", 40, 15000);

    insertNewOutlet(root, newSales, "Warung Bu Susi", "Bu Susi", "Pasar Lama Blok A");
    insertItem(newSales->info.outlet[1], "Teh Celup Sosro", 25, 8000);
    insertItem(newSales->info.outlet[1], "Susu Kental Manis", 30, 12000);
    insertItem(newSales->info.outlet[1], "Roti Tawar", 10, 15000);
    insertItem(newSales->info.outlet[1], "Sabun Lifeboy", 45, 4000);
    insertItem(newSales->info.outlet[1], "Sampo Pantene", 20, 25000);
    insertItem(newSales->info.outlet[1], "Pasta Gigi", 35, 18000);
    insertItem(newSales->info.outlet[1], "Sikat Gigi", 50, 7000);

    newSales = createElmSales(3, "Damayanti Dalima", "0406 1890 0566");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Minimarket Sejahtera", "Mas Rizki", "Komplek Melati");
    insertItem(newSales->info.outlet[0], "Aqua Galon", 50, 20000);
    insertItem(newSales->info.outlet[0], "Gas Elpiji 3kg", 20, 22000);
    insertItem(newSales->info.outlet[0], "Tepung Terigu", 40, 11000);
    insertItem(newSales->info.outlet[0], "Mentega Blueband", 30, 10000);
    insertItem(newSales->info.outlet[0], "Keju Kraft", 25, 15000);
    insertItem(newSales->info.outlet[0], "Coklat Batang", 60, 12000);
    insertItem(newSales->info.outlet[0], "Meses Ceres", 35, 9000);
    insertItem(newSales->info.outlet[0], "Baking Powder", 15, 6000);

    newSales = createElmSales(1, "Luhung Wicaksono", "0764 4058 1103");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Kelontong Madani", "Pak Haji", "Jl. Sudirman");
    insertItem(newSales->info.outlet[0], "Rokok Sampoerna", 50, 30000);
    insertItem(newSales->info.outlet[0], "Rokok Surya", 40, 28000);
    insertItem(newSales->info.outlet[0], "Korek Api", 100, 2000);
    insertItem(newSales->info.outlet[0], "Obat Nyamuk", 30, 5000);
    insertItem(newSales->info.outlet[0], "Tisu Wajah", 25, 12000);
    insertItem(newSales->info.outlet[0], "Pembalut Wanita", 40, 20000);


    newSales = createElmSales(2, "Rahayu Namaga", "(+62) 414 2295 113");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Agen Sembako Murah", "Ko Hendra", "Jl. Ahmad Yani");
    insertItem(newSales->info.outlet[0], "Beras Rojolele", 50, 120000);
    insertItem(newSales->info.outlet[0], "Minyak Curah", 100, 14000);
    insertItem(newSales->info.outlet[0], "Gula Merah", 40, 18000);
    insertItem(newSales->info.outlet[0], "Kacang Tanah", 30, 28000);
    insertItem(newSales->info.outlet[0], "Kerupuk Udang", 20, 25000);
    insertItem(newSales->info.outlet[0], "Terasi Udang", 50, 5000);
    insertItem(newSales->info.outlet[0], "Garam Dapur", 80, 2000);
    insertItem(newSales->info.outlet[0], "Penyedap Rasa", 100, 1000);
    insertItem(newSales->info.outlet[0], "Lada Bubuk", 60, 1500);

    insertNewOutlet(root, newSales, "Warung Pojok", "Mbak Yul", "Gg. Kancil");
    insertItem(newSales->info.outlet[1], "Es Krim Walls", 20, 5000);
    insertItem(newSales->info.outlet[1], "Minuman Ringan", 50, 4000);
    insertItem(newSales->info.outlet[1], "Keripik Singkong", 30, 10000);
    insertItem(newSales->info.outlet[1], "Kacang Garuda", 25, 9000);
    insertItem(newSales->info.outlet[1], "Permen Kopiko", 100, 500);
    insertItem(newSales->info.outlet[1], "Coklat Bengbeng", 40, 2500);


    newSales = createElmSales(7, "Ardiyanti Tri", "(+62) 256 9997 738");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Sumber Rezeki", "Pak Dedi", "Pasar Induk");
    insertItem(newSales->info.outlet[0], "Sapu Ijuk", 15, 25000);
    insertItem(newSales->info.outlet[0], "Pel Lantai", 10, 35000);
    insertItem(newSales->info.outlet[0], "Ember Plastik", 20, 15000);
    insertItem(newSales->info.outlet[0], "Gayung Air", 25, 8000);
    insertItem(newSales->info.outlet[0], "Sikat WC", 30, 12000);
    insertItem(newSales->info.outlet[0], "Pewangi Lantai", 40, 18000);

    newSales = createElmSales(9, "Alamsyah Among", "(+62) 908 7366 633");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Kios Serba Ada", "Bu Rina", "Depan Sekolah SD");
    insertItem(newSales->info.outlet[0], "Buku Tulis", 100, 5000);
    insertItem(newSales->info.outlet[0], "Pulpen Standard", 150, 3000);
    insertItem(newSales->info.outlet[0], "Pensil 2B", 100, 4000);
    insertItem(newSales->info.outlet[0], "Penghapus", 80, 2000);
    insertItem(newSales->info.outlet[0], "Penggaris 30cm", 50, 3000);
    insertItem(newSales->info.outlet[0], "Tipe-X", 40, 7000);
    insertItem(newSales->info.outlet[0], "Spidol Hitam", 30, 8000);
    insertItem(newSales->info.outlet[0], "Lem Kertas", 25, 4000);
    insertItem(newSales->info.outlet[0], "Sampul Buku", 60, 1000);
    insertItem(newSales->info.outlet[0], "Gunting Kecil", 20, 8000);
}
