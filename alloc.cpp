#include <cstring>
#include "alloc.h"

void porincrementos_str(char **&v, int &size, char *value)
{
    char **ppch;
    int i;
    
    if (v == NULL) {
        size = INCREMENTO;
        v = new char * [size];
        v[0] = NULL;
    }
    for (i = 0; v[i]; i++)
        ;
    if (i == size - 1) {
        // array full
        size += INCREMENTO;
        ppch = new char * [size];
        copy_strs(ppch, v);
        delete [] v;
        v = ppch;
    }
    v[i++] = value;
    v[i] = NULL;
}

void copy_strs(char **dest, char **source)
{
    int i;

    for (i = 0; source[i]; i++)
        dest[i] = source[i];
    dest[i] = NULL;
}

/* Null terminated arrays
 * ====================== */

char **alloc_strs(char **vt)  // t means temporal
{
    char **v;
    int i;

    for (i = 0; vt[i]; i++)
        ;
    v = new char * [i + 1];
    for (i = 0; vt[i]; i++)
        v[i] = vt[i];
    v[i] = NULL;
    return v;
}

void **alloc_voidps(void **v)
{
    void **vpp;
    int i;

    for (i = 0; v[i]; i++)
        ;
    vpp = new void * [i + 1];
    for (i = 0; v[i]; i++)
        vpp[i] = v[i];
    vpp[i] = NULL;
    return vpp;
}

/* simple alloc functions 
 * ====================== */

char *alloc_str(char *s)
{
    char *pch;
    
    pch = new char [strlen(s) + 1];
    strcpy(pch, s);
    return pch;
}

int *alloc_int(int i)
{
    int *ip;

    ip = new int;
    *ip = i;
    return ip;
}

double *alloc_double(double d)
{
    double *dp;

    dp = new double;
    *dp = d;
    return dp;
}
