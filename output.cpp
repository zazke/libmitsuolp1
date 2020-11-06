#include <iostream>
#include <iomanip>
#include "output.h"

using namespace std;

/* width = 10, right alignment*/
void imprimefecha(int date)
{
    cout.fill('0');
    cout << right;
    cout << setw(2) << date%100 << '/' 
         << setw(2) << (date/100)%100 << '/' 
         << setw(4) << date/10000;
    cout.fill(' ');
}
