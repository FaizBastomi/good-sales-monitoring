#include "Header/utils.h"
#include <iostream>
#include <limits>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string getNonEmptyInput(string prompt)
{
    string input;
    while (input.empty())
    {
        cout << prompt;
        getline(cin >> ws, input);
        if (input.empty())
        {
            cout << "Input tidak boleh kosong. Silakan coba lagi." << endl;
        }
    }
    return input;
}

string getStringInput(string prompt)
{
    string input;
    cout << prompt;
    getline(cin >> ws, input);
    return input;
}

int getIntInput(string prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
