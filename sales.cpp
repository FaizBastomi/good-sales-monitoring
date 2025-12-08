#include "sales.h"

void createTree(SalesTree &root)
{
    root = nullptr;
}

bool isSalesEmpty(adrSales root)
{
    return root == nullptr;
}

adrSales createElmSales(string nama, string contact_info, int insentif_fee)
{
    adrSales p = new Sales;
    p.info->nama = nama;
    p.info->contact_info = contact_info;
    p.info->insentif_fee = insentif_fee;
    p.info->firstOutlet = nullptr;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNewSales(adrSales &root, adrSales p)
{
    if(isSalesEmpty(root)){
        root = p;
    } else if(p->info.insentif_fee < root->info.insentif_fee){
        insertNewSales(root->left, p);
    } else if(p->info.insentif_fee > root->info.insentif_fee){
        insertNewSales(root->right, p)
    }
}
