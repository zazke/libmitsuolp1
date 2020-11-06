#include <iostream>
#include <iomanip>
#include "tabs.h"

using namespace std;

void tab(ostream &cout, double d, int width)
{
    ios_base::fmtflags prev;
    char prev_fill;
    
    prev = cout.flags(ios::right | ios::fixed);
    prev_fill = cout.fill(' ');
    cout << setw(width) << setprecision(2) << d;
    cout.flags(prev);
    cout.fill(prev_fill);
}

void tab(ostream &cout, int i, int width, int x)
{
    ios_base::fmtflags prev;
    char prev_fill;
    
    prev = cout.flags(ios::right);
    if (x != 0) {
        if (x != width) cout << setw(width - x) << ' ';
        prev_fill = cout.fill('0');
        cout << setw(x) << i;
        cout.flags(prev);
    } else {
        cout.fill(' ');     // Didn't know this was needed.
                            // If not present then it just ignores the 
                            // setw(width) manipulator
        cout << setw(width) << i;
    }
    cout.fill(prev_fill);
}

void tab(ostream &cout, const char s[], int width)
{
    ios_base::fmtflags prev;
    char prev_fill;
    
    prev = cout.flags(ios::left);
    prev_fill = cout.fill(' ');
    cout << setw(width) << s;
    cout.flags(prev);
    cout.fill(prev_fill);
}
