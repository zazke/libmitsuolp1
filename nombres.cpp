#include <cstring>
#include <cctype>
#include "nombres.h"

void Capitalize(char *dest, const char *source)
{
    int i;
    int nw;
    
    nw = 1;
    for (i = 0; source[i] != '\0'; i++) {
        if (nw == 1) {
            dest[i] = toupper(source[i]);
            nw = 0;
        } else {
            dest[i] = tolower(source[i]);
            if (isblank(source[i])) nw = 1;
        }
    }
    dest[i] = '\0';
}

