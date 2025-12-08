#ifndef SALES_MONITORING_H_INCLUDED
#define SALES_MONITORING_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct salesInfo infotype;
typedef struct Sales *adrSales;
typedef struct Outlet *adrOutlet;

struct salesInfo{
    string nama, contact_info;
    int insentif_fee;
    adrOutlet firstOutlet;
};
struct Sales{
    infotype info;
    adrSales left, right;
};
struct Outlet{
    string name, pic, location;
    adrOutlet next;
};

bool isSalesEmpty(adrSales root);
bool isOutletEmpty(adrSales p);

void createTree(adrSales &root);
adrSales createElmSales(string nama, string contact_info, int insentif_fee);
adrOutlet createElmOutlet(string nama, string pic, string location);
void insertNewSales(adrSales &root, adrSales p);
void insertNewOutlet(adrSales &p, adrOutlet q);

#endif // SALES_MONITORING_H_INCLUDED
