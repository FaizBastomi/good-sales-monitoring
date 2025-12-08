#ifndef OUTLET_H_INCLUDED
#define OUTLET_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct Outlet *adrOutlet;
typedef struct Sales *adrSales;
struct Sales;
struct Outlet{
    string nama, pic, location;
    adrOutlet next;
};

bool isOutletEmpty(adrSales p);
adrOutlet createElmOutlet(string nama, string pic, string location);
void insertNewOutlet(adrSales &p, adrOutlet q);

#endif // OUTLET_H_INCLUDED
