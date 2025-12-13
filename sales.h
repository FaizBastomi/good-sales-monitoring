#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED
#include <iostream>
using namespace std;

const MAX_OUTLET = 6;
typedef struct salesInfo infotype;
typedef struct Sales *adrSales;

struct Outlet;
struct salesInfo{
    string nama, contact_info;
    int insentif_fee, outletCount;
    Outlet outlet[MAX_OUTLET];
};
struct Sales{
    int id;
    infotype info;
    adrSales left, right;
};

//--- PRIMITIF ---
bool isSalesEmpty(adrSales root);
bool isOutletEmpty(adrSales p);
bool isOutletFull(adrSales p);
void createTree(adrSales &root);
adrSales getParentNode(adrSales root, adrSales p);
adrSales getMinNode(adrSales root);
adrSales getMaxNode(adrSales root);
adrSales createElmSales(string nama, string contact_info, int insentif_fee);

//--- CRUD ---
int findOutletIndex(adrSales p, string name);
bool isOutletExists(adrSales root, string name);
void insertNewSales(adrSales &root, adrSales p);
void insertNewOutlet(adrSales &p, string name, string pic, string location);
void deleteSales(adrSales &root, adrSales p);

// --- SEARCH ---
adrSales searchSales(adrSales root, string nama);
adrSales searchSales(adrSales root, int insentif_fee);

#endif // SALES_H_INCLUDED
