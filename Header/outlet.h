#ifndef OUTLET_H_INCLUDED
#define OUTLET_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

const int max_item = 10;
const int max_outlet = 5;

struct Item {
    string name;
    int stock;

};
struct Outlet {
    string nama, pic, location;
    Item barang[max_item];
    int count;
};

bool isItemEmpty(Outlet Toko);
bool isItemFull(Outlet Toko);

void insertItem(Outlet &Toko, string namaBarang, int stokAwal);
void viewOutlet(Outlet Toko);
void updateStock(Outlet &Toko, string namaBarang, int stokBaru);
void deleteItem(Outlet &Toko, string namaBarang);
int findItemIndex(Outlet Toko, string namaBarang);

int countTotalAsset(Outlet Toko);
int findMaxStockIndex(Outlet Toko);
int findMinStockIndex(Outlet Toko);
void viewLowStockItems(Outlet Toko, int limit);
double calculateAverageStock(Outlet Toko);
#endif // OUTLET_H_INCLUDED
