#ifndef SALES_MENU_H_INCLUDED
#define SALES_MENU_H_INCLUDED

typedef struct Sales *adrSales;
struct Sales;

void salesStatistics(adrSales root);
void salesMenu(adrSales &root);
void tambahSales(adrSales &root);
void ubahDataSales(adrSales &root);
void hapusSales(adrSales &root);

#endif // SALES_MENU_H_INCLUDED