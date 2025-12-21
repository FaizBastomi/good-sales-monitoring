#include "Header/sales.h"
#include "Header/sales_menu.h"
#include "Header/outlet_menu.h"
#include "Header/utils.h"
#include "Header/data_seeding.h"
#include <iostream>

using namespace std;

int main()
{
    adrSales root;
    int choice;
    createTree(root);

    startDataSeeding(root);

    clearScreen();
    choice = 0;
    while (choice != 3)
    {
        cout << "1. Menu Sales" << endl;
        cout << "2. Menu Outlet" << endl;
        cout << "3. Exit" << endl;
        choice = getIntInput("Pilihan: ");

        switch (choice)
        {
        case 1:
            salesMenu(root);
            break;
        case 2:
            outletMenu(root);
            break;
        }
        clearScreen();
    }
    return 0;
}
