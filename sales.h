#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED
#include "outlet.h"
#include <iostream>
using namespace std;

typedef struct salesInfo infotype;
typedef struct Sales *adrSales;

struct salesInfo{
    string nama, contact_info;
    int insentif_fee;
    adrOutlet firstOutlet;
};
struct Sales{
    infotype info;
    adrSales left, right;
};

bool isSalesEmpty(adrSales root);
void createTree(adrSales &root);
adrSales createElmSales(string nama, string contact_info, int insentif_fee);
void insertNewSales(adrSales &root, adrSales p);

#endif // SALES_H_INCLUDED
