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

    if (p->id < root->id && root->left != p)
    {
        return getParentNode(root->left, p);
    }
    else if (p->id > root->id && root->right != p)
    {
        return getParentNode(root->right, p);
    }
    return root;
}

adrSales createElmSales(int id, string nama, string contact_info)
{
    adrSales p = new Sales;
    p->id = id;
    p->info.nama = nama;
    p->info.contact_info = contact_info;
    p->info.insentif_fee = 0;
    p->info.outletCount = -1;
    p->left = nullptr;
    p->right = nullptr;
    return p;
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
            p->info.insentif_fee += 15000;
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
        p->info.insentif_fee -= 15000;
        p->info.outletCount--;
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
            root = adrN;
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
    else if (!p->left || !p->right)
    {
        adrN = (p->left) ? p->left : p->right;

        if (!adrP)
        {
            root = adrN;
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
    else
    {
        adrN = getMinNode(p->right);

        deleteSales(root, adrN);
        p->id = adrN->id;
        p->info = adrN->info;
    }
}

void displaySales(adrSales root, int mode)
{
    if (root != nullptr)
    {
        if (mode == 1)
        {
            displaySales(root->left, mode);
            cout << "ID: " << root->id << ", Nama: " << root->info.nama
                 << "\nContact Info: " << root->info.contact_info
                 << ", Insentif Fee: " << root->info.insentif_fee
                 << "\nOutlet Count: " << root->info.outletCount + 1 << endl;
            displaySales(root->right, mode);
        }
        else if (mode == 2)
        {
            cout << "ID: " << root->id << ", Nama: " << root->info.nama
                 << "\nContact Info: " << root->info.contact_info
                 << ", Insentif Fee: " << root->info.insentif_fee
                 << "\nOutlet Count: " << root->info.outletCount + 1 << endl;
            displaySales(root->left, mode);
            displaySales(root->right, mode);
        }
        else
        {
            displaySales(root->left, mode);
            displaySales(root->right, mode);
            cout << "ID: " << root->id << ", Nama: " << root->info.nama
                 << "\nContact Info: " << root->info.contact_info
                 << ", Insentif Fee: " << root->info.insentif_fee
                 << "\nOutlet Count: " << root->info.outletCount + 1 << endl;
        }
    }
}

int totalIncentive(adrSales root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->info.insentif_fee + totalIncentive(root->left) + totalIncentive(root->right);
}

float averageIncentive(adrSales root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int total = totalIncentive(root);
    int count = countNodes(root);

    return (count == 0) ? 0 : total / count;
}

int countNodes(adrSales root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int totalOutlets(adrSales root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return (root->info.outletCount + 1) + totalOutlets(root->left) + totalOutlets(root->right);
}

//--- SEARCH ---

adrSales searchSales(adrSales root, string name)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->info.nama == name)
    {
        return root;
    }

    adrSales leftSearch = searchSales(root->left, name);
    if (leftSearch != nullptr)
        return leftSearch;
    return searchSales(root->right, name);
}

void searchSales(adrSales root, int min_insentif, int max_insentif, int min_outlet, vector<adrSales> &results)
{
    if (!root)
        return;
    if
    (
        root->info.insentif_fee >= min_insentif && root->info.insentif_fee <= max_insentif
        && root->info.outletCount + 1 >= min_outlet
    )
        results.push_back(root);
    if (root->info.insentif_fee > min_insentif)
        searchSales(root->left, min_insentif, max_insentif, min_outlet, results);
    if (root->info.insentif_fee < max_insentif)
        searchSales(root->right, min_insentif, max_insentif, min_outlet, results);
}

adrSales getSalesByOutletName(adrSales root, string outlet_name)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    for (int i = 0; i <= root->info.outletCount; i++)
    {
        if (root->info.outlet[i].nama == outlet_name)
        {
            return root;
        }
    }

    adrSales leftSearch = getSalesByOutletName(root->left, outlet_name);
    if (leftSearch != nullptr)
        return leftSearch;
    return getSalesByOutletName(root->right, outlet_name);
}

adrSales findMaxIncentive(adrSales root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    adrSales maxNode = root;
    adrSales leftMax = findMaxIncentive(root->left);
    adrSales rightMax = findMaxIncentive(root->right);

    if (leftMax != nullptr && leftMax->info.insentif_fee > maxNode->info.insentif_fee)
    {
        maxNode = leftMax;
    }
    if (rightMax != nullptr && rightMax->info.insentif_fee > maxNode->info.insentif_fee)
    {
        maxNode = rightMax;
    }
    return maxNode;
}

adrSales findMinIncentive(adrSales root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    adrSales minNode = root;
    adrSales leftMin = findMinIncentive(root->left);
    adrSales rightMin = findMinIncentive(root->right);

    if (leftMin != nullptr && leftMin->info.insentif_fee < minNode->info.insentif_fee)
    {
        minNode = leftMin;
    }
    if (rightMin != nullptr && rightMin->info.insentif_fee < minNode->info.insentif_fee)
    {
        minNode = rightMin;
    }
    return minNode;
}