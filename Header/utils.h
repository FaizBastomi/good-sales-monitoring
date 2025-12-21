#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
using namespace std;

void clearScreen();
string getNonEmptyInput(string prompt);
string getStringInput(string prompt);
int getIntInput(string prompt);

#endif // UTILS_H_INCLUDED
