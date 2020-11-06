#include <iostream>
#include <cstring>
#include "input.h"

using namespace std;

istream& getsep(istream& is, char s[], int n, const char delim[])
{
    char c;
    int i;
    for (i = 0; i < (n-1) && is.get(c) && !strchr(delim, c); i++) 
        s[i] = c;
    s[i] = '\0';
    /* get rid of last delim char if s got full (behaviour of istream::geline() 
     * > The failbit flag is set if the function extracts no characters, or if
     * > the delimiting character is not found once (n-1) characters have
     * > already been written to s. Note that if the character that follows
     * > those (n-1) characters in the input sequence is precisely the
     * > delimiting character, it is also extracted and the failbit flag is not
     * > set (the extracted sequence was exactly n characters long).
     */
    if (i == n-1 && is.good()) {
        if (strchr(delim, is.peek()))
            is.get();
        else 
            is.setstate(ios::failbit);
    }
    return is;
}
