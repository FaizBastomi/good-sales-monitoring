#include "sales.h"
#include "outlet.h"

//--- PRIMITIF ---
void createTree(SalesTree &root)
{
    root = nullptr;
}

bool isSalesEmpty(adrSales root)
{
    return root == nullptr;
}

bool isOutletEmpty(adrSales p)
{
    return p->info.outletCount == -1;
}

bool isOutletFull(adrSales p)
{
    return p->info.outletCount == MAX_OUTLET - 1;
}

adrSales getMaxNode(adrSales root)
{
    adrSales p = root;
    while(p && p->right){
        p = p->right;
    }
    return p;
}

adrSales getMinNode(adrSales root)
{
    adrSales p = root;
    while(p && p->left){
        p = p->left;
    }
    return p;
}

adrSales getParentNode(adrSales root, adrSales p)
{
    if(p == root || (!root->left && !root->right)){
        return nullptr;
    }

    if(p->id < root->id && p->left != p){
        return getParentNode(root->left, p);
    } else if(p->id > root->id && p->right != p){
        return getParentNode(root->right, p);
    }
    return root;
}

adrSales createElmSales(string nama, string contact_info, int insentif_fee)
{
    adrSales p = new Sales;
    p.info->nama = nama;
    p.info->contact_info = contact_info;
    p.info->insentif_fee = insentif_fee;
    p.info->outletCount = -1;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

//--- CRUD ---
int findOutletIndex(adrSales p, string name)
{
    for(int i = 0; i <= p->info.outletCount; i++){
        if(p->info.outlet[i].nama == name){
            return i;
        }
    }
    return -1;
}

void insertNewSales(adrSales &root, adrSales p)
{
    if(isSalesEmpty(root)){
        root = p;
        cout << "Berhasil menambahkan sales baru." << endl;
    } else if(p->info.insentif_fee < root->info.insentif_fee){
        insertNewSales(root->left, p);
    } else if(p->info.insentif_fee > root->info.insentif_fee){
        insertNewSales(root->right, p);
    }
}

void insertNewOutlet(adrSales &p, string name, string pic, string location)
{
    Outlet q;
    q.nama = name;
    q.pic = pic;
    q.location = location;
    q.count = 0;

    if(!isOutletExists(p, name)){
        if(!isOutletFull(p)){
            p->info.outlet[++p->info.outletCount] = q;
            cout << "Berhasil menambahkan outlet." << endl;
        } else {
            cout << "Sales: " << p->info.nama << " sudah mencapai batas maksimum outlet yang bisa dipegang." << endl;
        }
    } else {
        cout << "Outlet dengan nama: " << name << " sudah dipegang sales lain." << endl;
    }
}

bool isOutletExists(adrSales root, string name)
{
    if(root == nullptr){
        return false;
    }

    for(int i = 0; i <= root->info.outletCount; i++){
        if(root->info.outlet[i].nama == name){
            return true;
        }
    }

    if(isOutletExists(root->left, name)){
        return true;
    }
    return isOutletExists(root->right, name);
}

void deleteSales(adrSales &root, adrSales p)
{
    adrSales adrP, adrN;
    adrP = getParentNode(root, p);

    if(!p->left && !p->right){
        adrN = nullptr;

        if(!adrP){
            p = adrN;
        } else if(p->id < adrP->id){
            adrP->left = adrN;
        } else if(p->id > adrP->id){
            adrP->right = adrN;
        }
    } else if(p->left && p->right){
        adrN = getMinNode(p->right);

        deleteSales(root, adrN);
        p->info = adrN->info;
    } else {
        if(!p->left){
            adrN = getMaxNode(p);
        } else {
            adrN = getMinNode(p);
        }

        if(!adrP){
            p = adrN;
        } else if(p->id < adrP->id){
            adrP->left = adrN;
        } else if(p->id > adrP->id){
            adrP->right = adrN;
        }
    }
}

//--- SEARCH ---
//TODO: Implement this function
adrSales searchSales(adrSales root, string nama)
{

}

//TODO: Implement this function
adrSales searchSales(adrSales root, int insentif_fee)
{

}
