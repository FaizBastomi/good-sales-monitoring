#include "Header/sales.h"
#include "Header/outlet.h"
#include <vector>

//--- PRIMITIF ---
void createTree(adrSales &root)
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
    while (p && p->right)
    {
        p = p->right;
    }
    return p;
}

adrSales getMinNode(adrSales root)
{
    adrSales p = root;
    while (p && p->left)
    {
        p = p->left;
    }
    return p;
}

bool isOutletExists(adrSales root, string name)
{
    if (root == nullptr)
    {
        return false;
    }

    for (int i = 0; i <= root->info.outletCount; i++)
    {
        if (root->info.outlet[i].nama == name)
        {
            return true;
        }
    }

    if (isOutletExists(root->left, name))
    {
        return true;
    }
    return isOutletExists(root->right, name);
}

bool isSalesIdExists(adrSales root, int id)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->id == id)
    {
        return true;
    }

    if (isSalesIdExists(root->left, id))
    {
        return true;
    }
    return isSalesIdExists(root->right, id);
}

adrSales getParentNode(adrSales root, adrSales p)
{
    if (p == root || (!root->left && !root->right))
    {
        return nullptr;
    }

    if (p->id < root->id && p->left != p)
    {
        return getParentNode(root->left, p);
    }
    else if (p->id > root->id && p->right != p)
    {
        return getParentNode(root->right, p);
    }
    return root;
}

adrSales createElmSales(int id, string nama, string contact_info, int insentif_fee)
{
    adrSales p = new Sales;
    p->id = id;
    p->info.nama = nama;
    p->info.contact_info = contact_info;
    p->info.insentif_fee = insentif_fee;
    p->info.outletCount = -1;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void displaySales(adrSales root)
{
    if (root != nullptr)
    {
        displaySales(root->left);
        cout << "ID: " << root->id << ", Nama: " << root->info.nama
             << "\nContact Info: " << root->info.contact_info
             << ", Insentif Fee: " << root->info.insentif_fee
             << "\nOutlet Count: " << root->info.outletCount + 1 << endl;
        displaySales(root->right);
    }
}

//--- CRUD ---
int findOutletIndex(adrSales p, string name)
{
    for (int i = 0; i <= p->info.outletCount; i++)
    {
        if (p->info.outlet[i].nama == name)
        {
            return i;
        }
    }
    return -1;
}

void insertNewSales(adrSales &root, adrSales p)
{
    if (isSalesEmpty(root))
    {
        root = p;
        cout << "Berhasil menambahkan sales baru." << endl;
    }
    else if (p->id < root->id)
    {
        insertNewSales(root->left, p);
    }
    else if (p->id > root->id)
    {
        insertNewSales(root->right, p);
    }
}

void insertNewOutlet(adrSales root, adrSales &p, string name, string pic, string location)
{
    Outlet q;
    q.nama = name;
    q.pic = pic;
    q.location = location;
    q.count = 0;

    if (!isOutletExists(root, name))
    {
        if (!isOutletFull(p))
        {
            p->info.outlet[++p->info.outletCount] = q;
            cout << "Berhasil menambahkan outlet." << endl;
        }
        else
        {
            cout << "Sales: " << p->info.nama << " sudah mencapai batas maksimum outlet yang bisa dipegang." << endl;
        }
    }
    else
    {
        cout << "Outlet dengan nama: " << name << " sudah dipegang sales lain." << endl;
    }
}

void updateSales(adrSales p, string nama, string contact_info, int insentif_fee)
{
    p->info.nama = nama;
    p->info.contact_info = contact_info;
    p->info.insentif_fee = insentif_fee;
    cout << "Berhasil memperbarui data sales." << endl;
}

void deleteOutlet(adrSales &p, string name)
{
    int idx = findOutletIndex(p, name);
    if (idx != -1)
    {
        for (int i = idx; i <= p->info.outletCount; i++)
        {
            p->info.outlet[i] = p->info.outlet[i + 1];
        }
        p->info.outletCount--;
        cout << "Berhasil menghapus outlet: " << name << endl;
    }
    else
    {
        cout << "Outlet dengan nama: " << name << " tidak ditemukan." << endl;
    }
}

void deleteSales(adrSales &root, adrSales p)
{
    adrSales adrP, adrN;
    adrP = getParentNode(root, p);

    if (!p->left && !p->right)
    {
        adrN = nullptr;

        if (!adrP)
        {
            p = adrN;
        }
        else if (p->id < adrP->id)
        {
            adrP->left = adrN;
        }
        else if (p->id > adrP->id)
        {
            adrP->right = adrN;
        }
    }
    else if (p->left && p->right)
    {
        adrN = getMinNode(p->right);

        deleteSales(root, adrN);
        p->info = adrN->info;
    }
    else
    {
        if (!p->left)
        {
            adrN = getMaxNode(p);
        }
        else
        {
            adrN = getMinNode(p);
        }

        if (!adrP)
        {
            p = adrN;
        }
        else if (p->id < adrP->id)
        {
            adrP->left = adrN;
        }
        else if (p->id > adrP->id)
        {
            adrP->right = adrN;
        }
    }
}

//--- SEARCH ---
adrSales searchSalesByName(adrSales root, string nama)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->info.nama == nama)
    {
        return root;
    }

    adrSales leftSearch = searchSalesByName(root->left, nama);
    if (leftSearch != nullptr)
        return leftSearch;
    return searchSalesByName(root->right, nama);
}

void searchSalesByInsentif(adrSales root, int min_insentif, int max_insentif, vector<adrSales> &results)
{
    if (!root)
        return;
    if (root->info.insentif_fee >= min_insentif && root->info.insentif_fee <= max_insentif)
        results.push_back(root);
    if (root->info.insentif_fee > min_insentif)
        searchSalesByInsentif(root->left, min_insentif, max_insentif, results);
    if (root->info.insentif_fee < max_insentif)
        searchSalesByInsentif(root->right, min_insentif, max_insentif, results);
}

void searchSalesByOutlet(adrSales root, int min_outlet, vector<adrSales> &results)
{
    if (!root)
        return;
    if (root->info.outletCount + 1 >= min_outlet)
        results.push_back(root);
    searchSalesByOutlet(root->left, min_outlet, results);
    searchSalesByOutlet(root->right, min_outlet, results);
}
