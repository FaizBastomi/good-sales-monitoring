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

    insertNewOutlet(root, newSales, "Toko Bintang", "Pak Arif", "Jl. Melati No.1");
    insertItem(newSales->info.outlet[2], "Pulpen", 120, 3000);
    insertItem(newSales->info.outlet[2], "Buku Tulis", 80, 5000);
    insertItem(newSales->info.outlet[2], "Stabilo", 40, 8000);
    insertItem(newSales->info.outlet[2], "Penghapus", 90, 1500);

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

    insertNewOutlet(root, newSales, "Toko Cahaya", "Bu Lina", "Jl. Kenanga No.4");
    insertItem(newSales->info.outlet[1], "Map Plastik", 100, 2500);
    insertItem(newSales->info.outlet[1], "Spidol", 60, 6000);
    insertItem(newSales->info.outlet[1], "Buku Gambar", 50, 7000);
    insertItem(newSales->info.outlet[1], "Pulpen Gel", 70, 5500);
    insertItem(newSales->info.outlet[1], "Rautan", 85, 2000);

    insertNewOutlet(root, newSales, "Toko Harapan Jaya", "Pak Doni", "Jl. Mawar No.7");
    insertItem(newSales->info.outlet[2], "Kertas HVS", 300, 500);
    insertItem(newSales->info.outlet[2], "Amplop", 150, 2000);
    insertItem(newSales->info.outlet[2], "Lakban", 40, 7000);

    newSales = createElmSales(1, "Luhung Wicaksono", "0764 4058 1103");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Kelontong Madani", "Pak Haji", "Jl. Sudirman");
    insertItem(newSales->info.outlet[0], "Rokok Sampoerna", 50, 30000);
    insertItem(newSales->info.outlet[0], "Rokok Surya", 40, 28000);
    insertItem(newSales->info.outlet[0], "Korek Api", 100, 2000);
    insertItem(newSales->info.outlet[0], "Obat Nyamuk", 30, 5000);
    insertItem(newSales->info.outlet[0], "Tisu Wajah", 25, 12000);
    insertItem(newSales->info.outlet[0], "Pembalut Wanita", 40, 20000);

    insertNewOutlet(root, newSales, "Toko Sinar", "Bu Rika", "Jl. Anggrek No.2");
    insertItem(newSales->info.outlet[1], "Pensil 2B", 110, 2500);
    insertItem(newSales->info.outlet[1], "Pensil Warna", 45, 15000);
    insertItem(newSales->info.outlet[1], "Crayon", 30, 12000);
    insertItem(newSales->info.outlet[1], "Buku Kotak", 90, 5500);
    insertItem(newSales->info.outlet[1], "Penggaris", 70, 4000);
    insertItem(newSales->info.outlet[1], "Penghapus", 100, 1500);

    insertNewOutlet(root, newSales, "Toko Mandiri Jaya", "Pak Rudi", "Jl. Flamboyan No.9");
    insertItem(newSales->info.outlet[2], "Buku Kas", 60, 10000);
    insertItem(newSales->info.outlet[2], "Kwitansi", 80, 6000);
    insertItem(newSales->info.outlet[2], "Pulpen Biru", 140, 3000);
    insertItem(newSales->info.outlet[2], "Pulpen Hitam", 130, 3000);

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

    insertNewOutlet(root, newSales, "Toko Sejahtera Abadi", "Bu Yanti", "Jl. Dahlia No.6");
    insertItem(newSales->info.outlet[2], "Ordner", 35, 22000);
    insertItem(newSales->info.outlet[2], "Map Snelhecter", 75, 5000);
    insertItem(newSales->info.outlet[2], "Divider", 60, 4000);
    insertItem(newSales->info.outlet[2], "Label Sticker", 55, 6000);
    insertItem(newSales->info.outlet[2], "Binder", 40, 25000);
    insertItem(newSales->info.outlet[2], "Isi Binder", 65, 12000);
    insertItem(newSales->info.outlet[2], "Sticky Note", 90, 6000);

    newSales = createElmSales(7, "Ardiyanti Tri", "(+62) 256 9997 738");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Sumber Rezeki", "Pak Dedi", "Pasar Induk");
    insertItem(newSales->info.outlet[0], "Sapu Ijuk", 15, 25000);
    insertItem(newSales->info.outlet[0], "Pel Lantai", 10, 35000);
    insertItem(newSales->info.outlet[0], "Ember Plastik", 20, 15000);
    insertItem(newSales->info.outlet[0], "Gayung Air", 25, 8000);
    insertItem(newSales->info.outlet[0], "Sikat WC", 30, 12000);
    insertItem(newSales->info.outlet[0], "Pewangi Lantai", 40, 18000);

    insertNewOutlet(root, newSales, "Toko Pelangi", "Pak Yogi", "Jl. Teratai No.3");
    insertItem(newSales->info.outlet[1], "Spidol Board", 50, 10000);
    insertItem(newSales->info.outlet[1], "Penghapus Board", 40, 8000);
    insertItem(newSales->info.outlet[1], "Marker Permanen", 65, 9000);

    insertNewOutlet(root, newSales, "Toko Kencana", "Bu Mira", "Jl. Cempaka No.11");
    insertItem(newSales->info.outlet[2], "Buku Nota", 120, 4000);
    insertItem(newSales->info.outlet[2], "Kalkulator", 20, 75000);
    insertItem(newSales->info.outlet[2], "Tip-Ex", 55, 9000);
    insertItem(newSales->info.outlet[2], "Pulpen Merah", 95, 3000);
    insertItem(newSales->info.outlet[2], "Map Kertas", 110, 3000);

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

    insertNewOutlet(root, newSales, "Toko Sentral", "Pak Fajar", "Jl. Rajawali No.14");
    insertItem(newSales->info.outlet[1], "Kertas Folio", 200, 800);
    insertItem(newSales->info.outlet[1], "Kertas Buffalo", 100, 3500);
    insertItem(newSales->info.outlet[1], "Binder Clip", 150, 1500);
    insertItem(newSales->info.outlet[1], "Paper Clip", 180, 1000);

    insertNewOutlet(root, newSales, "Toko Mega Stationery", "Bu Novi", "Jl. Garuda No.20");
    insertItem(newSales->info.outlet[2], "Stempel", 25, 30000);
    insertItem(newSales->info.outlet[2], "Tinta Stempel", 35, 12000);
    insertItem(newSales->info.outlet[2], "Buku Agenda", 50, 18000);
    insertItem(newSales->info.outlet[2], "Pulpen Gel", 70, 5500);
    insertItem(newSales->info.outlet[2], "Sticky Note", 85, 6000);
    insertItem(newSales->info.outlet[2], "Map Plastik", 120, 2500);
    insertItem(newSales->info.outlet[2], "Penggaris", 65, 4000);

    newSales = createElmSales(6, "Tedi Purnawarman", "0596 3261 964");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Warung Slamet", "Pak Slamet", "Pegangsaan Raya");
    insertItem(newSales->info.outlet[0], "Buku Tulis", 100, 5000);
    insertItem(newSales->info.outlet[0], "Pulpen Standard", 150, 3000);
    insertItem(newSales->info.outlet[0], "Pensil 2B", 100, 4000);
    insertItem(newSales->info.outlet[0], "Sampul Buku", 60, 1000);
    insertItem(newSales->info.outlet[0], "Gunting Kecil", 20, 8000);
    insertItem(newSales->info.outlet[0], "Ember Plastik", 20, 15000);
    insertItem(newSales->info.outlet[0], "Gayung Air", 25, 8000);

    insertNewOutlet(root, newSales, "Kedai Toh A", "Ko Toh A", "Cianjur Timur");
    insertItem(newSales->info.outlet[1], "Buku Tulis", 100, 5000);
    insertItem(newSales->info.outlet[1], "Pulpen Standard", 150, 3000);
    insertItem(newSales->info.outlet[1], "Pensil 2B", 100, 4000);
    insertItem(newSales->info.outlet[1], "Sampul Buku", 60, 1000);
    insertItem(newSales->info.outlet[1], "Gunting Kecil", 20, 8000);
    insertItem(newSales->info.outlet[1], "Ember Plastik", 20, 15000);
    insertItem(newSales->info.outlet[1], "Gula Merah", 40, 18000);
    insertItem(newSales->info.outlet[1], "Kacang Tanah", 30, 28000);
    insertItem(newSales->info.outlet[1], "Kerupuk Udang", 20, 25000);
    insertItem(newSales->info.outlet[1], "Gayung Air", 25, 8000);

    insertNewOutlet(root, newSales, "Toko Prima", "Pak Wahyu", "Jl. Pahlawan No.8");
    insertItem(newSales->info.outlet[2], "Pulpen Biru", 130, 3000);
    insertItem(newSales->info.outlet[2], "Buku Gambar", 60, 7000);
    insertItem(newSales->info.outlet[2], "Map Snelhecter", 75, 5000);
    insertItem(newSales->info.outlet[2], "Sticky Note", 90, 6000);
    insertItem(newSales->info.outlet[2], "Penggaris", 55, 4000);

    newSales = createElmSales(4, "Andi Saputra", "0812 1111 2222");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Maju Jaya", "Bu Rina", "Jl. Merdeka No.10");
    insertItem(newSales->info.outlet[0], "Pulpen", 200, 3000);
    insertItem(newSales->info.outlet[0], "Pensil", 150, 2000);
    insertItem(newSales->info.outlet[0], "Penghapus", 100, 1500);
    insertItem(newSales->info.outlet[0], "Penggaris", 80, 4000);
    insertItem(newSales->info.outlet[0], "Buku Gambar", 60, 7000);

    insertNewOutlet(root, newSales, "Toko Sumber Rejeki", "Pak Budi", "Jl. Sudirman No.21");
    insertItem(newSales->info.outlet[1], "Buku Tulis", 120, 5000);
    insertItem(newSales->info.outlet[1], "Spidol", 90, 6000);
    insertItem(newSales->info.outlet[1], "Map Plastik", 110, 2500);
    insertItem(newSales->info.outlet[1], "Stabilo", 70, 8000);
    insertItem(newSales->info.outlet[1], "Tip-Ex", 50, 9000);

    insertNewOutlet(root, newSales, "Toko Pelajar", "Bu Santi", "Jl. Ahmad Yani No.5");
    insertItem(newSales->info.outlet[2], "Crayon", 40, 12000);
    insertItem(newSales->info.outlet[2], "Pensil Warna", 55, 15000);
    insertItem(newSales->info.outlet[2], "Buku Kotak", 100, 5500);
    insertItem(newSales->info.outlet[2], "Buku Garis", 130, 5000);
    insertItem(newSales->info.outlet[2], "Rautan", 90, 2000);

    newSales = createElmSales(8, "Siti Rahmawati", "0821 3333 4444");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Cemerlang", "Pak Deni", "Jl. Diponegoro No.7");
    insertItem(newSales->info.outlet[0], "Pulpen Gel", 140, 5500);
    insertItem(newSales->info.outlet[0], "Buku Agenda", 60, 18000);
    insertItem(newSales->info.outlet[0], "Sticky Note", 100, 6000);
    insertItem(newSales->info.outlet[0], "Binder", 45, 25000);
    insertItem(newSales->info.outlet[0], "Isi Binder", 80, 12000);

    insertNewOutlet(root, newSales, "Toko Harapan", "Bu Lina", "Jl. Gatot Subroto No.12");
    insertItem(newSales->info.outlet[1], "Map Kertas", 150, 3000);
    insertItem(newSales->info.outlet[1], "Amplop", 200, 2000);
    insertItem(newSales->info.outlet[1], "Kertas HVS", 500, 500);
    insertItem(newSales->info.outlet[1], "Kertas Folio", 300, 800);
    insertItem(newSales->info.outlet[1], "Lakban", 90, 7000);

    insertNewOutlet(root, newSales, "Toko Sentosa", "Pak Agus", "Jl. Veteran No.9");
    insertItem(newSales->info.outlet[2], "Spidol Board", 60, 10000);
    insertItem(newSales->info.outlet[2], "Penghapus Board", 50, 8000);
    insertItem(newSales->info.outlet[2], "Marker Permanen", 70, 9000);
    insertItem(newSales->info.outlet[2], "Buku Nota", 110, 4000);
    insertItem(newSales->info.outlet[2], "Kalkulator", 30, 75000);

    newSales = createElmSales(10, "Rizky Pratama", "0838 5555 6666");
    insertNewSales(root, newSales);

    insertNewOutlet(root, newSales, "Toko Nusantara", "Bu Maya", "Jl. Asia Afrika No.15");
    insertItem(newSales->info.outlet[0], "Buku Tulis", 200, 5000);
    insertItem(newSales->info.outlet[0], "Pulpen Hitam", 180, 3000);
    insertItem(newSales->info.outlet[0], "Pulpen Biru", 160, 3000);
    insertItem(newSales->info.outlet[0], "Pensil 2B", 140, 2500);
    insertItem(newSales->info.outlet[0], "Penghapus", 120, 1500);

    insertNewOutlet(root, newSales, "Toko Sejahtera", "Pak Hendra", "Jl. Cendrawasih No.4");
    insertItem(newSales->info.outlet[1], "Buku Kas", 70, 10000);
    insertItem(newSales->info.outlet[1], "Buku Kwitansi", 90, 6000);
    insertItem(newSales->info.outlet[1], "Kwitansi Besar", 60, 8000);
    insertItem(newSales->info.outlet[1], "Stempel", 25, 30000);
    insertItem(newSales->info.outlet[1], "Tinta Stempel", 40, 12000);

    insertNewOutlet(root, newSales, "Toko Mandiri", "Bu Yuni", "Jl. Kenanga No.18");
    insertItem(newSales->info.outlet[2], "Ordner", 50, 22000);
    insertItem(newSales->info.outlet[2], "Map Snelhecter", 100, 5000);
    insertItem(newSales->info.outlet[2], "Kertas Buffalo", 120, 3500);
    insertItem(newSales->info.outlet[2], "Divider", 80, 4000);
    insertItem(newSales->info.outlet[2], "Label Sticker", 90, 6000);
}
