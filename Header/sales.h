#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED
#include "outlet.h"
#include <iostream>
#include <vector>
using namespace std;

const int MAX_OUTLET = 6;
typedef struct salesInfo infotype;
typedef struct Sales *adrSales;

struct salesInfo
{
    string nama, contact_info;
    int insentif_fee, outletCount;
    Outlet outlet[MAX_OUTLET];
};
struct Sales
{
    int id;
    infotype info;
    adrSales left, right;
};

//--- PRIMITIF ---
void createTree(adrSales &root);
bool isSalesEmpty(adrSales root);
bool isOutletEmpty(adrSales p);
bool isOutletFull(adrSales p);
bool isOutletExists(adrSales root, string name);
bool isSalesIdExists(adrSales root, int id);
adrSales getParentNode(adrSales root, adrSales p);
adrSales getMinNode(adrSales root);
adrSales getMaxNode(adrSales root);
adrSales createElmSales(int id, string nama, string contact_info, int insentif_fee);
void displaySales(adrSales root);

//--- CRUD ---
int findOutletIndex(adrSales p, string name);
void insertNewSales(adrSales &root, adrSales p);
void insertNewOutlet(adrSales root, adrSales &p, string name, string pic, string location);
void updateSales(adrSales p, string nama, string contact_info, int insentif_fee);
void deleteOutlet(adrSales &p, string name);
void deleteSales(adrSales &root, adrSales p);

// --- SEARCH ---
adrSales searchSalesByName(adrSales root, string nama);
void searchSalesByInsentif(adrSales root, int min_isentif, int max_insentif, vector<adrSales> &results);
void searchSalesByOutlet(adrSales root, int min_outlet, vector<adrSales> &results);
adrSales getSalesByOutletName(adrSales root, string outlet_name);

#endif // SALES_H_INCLUDED
