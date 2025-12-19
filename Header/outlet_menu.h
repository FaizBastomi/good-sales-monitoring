#ifndef OUTLET_MENU_H_INCLUDED
#define OUTLET_MENU_H_INCLUDED

#include "sales.h"

void outletMenu(adrSales &root);
void cariDanKelolaOutlet(adrSales &root);
void menuKelolaOutlet(adrSales salesNode, int outletIdx, adrSales &root);
void menuTambahOutlet(adrSales &root);

#endif // OUTLET_MENU_H_INCLUDED
