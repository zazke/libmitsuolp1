#include <cstring>      // strcmp
#include <cstdlib>      // atof
#include "sort.h"

void qsort2(char const *v1[], char const *v2[], int left, int right)
{
    int i, last;
    
    if (left >= right)
        return;
    swappch(v2, left, (left+right)/2);
    swappch(v1, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v2[i], v2[left]) < 0) {
            last++;
            swappch(v1, last, i);
            swappch(v2, last, i);
        }
    }
    swappch(v2, left, last);
    swappch(v1, left, last);
    qsort2(v1, v2, left, last-1);
    qsort2(v1, v2, last+1, right);
}

void swappch(char const *v[], int i, int j)
{
    char const *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsortKR(void *v[], int left, int right,
        int (*comp)(void *, void*))
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsortKR(v, left, last-1, comp);
    qsortKR(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* Comparison functions for K&R qsort  (and also INF281 Guanira's ordenaG)
 * ======================================================================= */

/* strcmp */

int numcmp(char const *pch1, char const *pch2)
{
    return atof(pch1) - atof(pch2);
}

/* Comparison functions for stdlib.h qsort
 * ======================================= */

int cmpstrp(const void *pv1, const void *pv2)
{
    char const * const * strp1,
               * const * strp2;
    
    strp1 = (char const * const *) pv1;
    strp2 = (char const * const *) pv2;
    return strcmp(*strp1, *strp2);
}

int cmpintp(void const *pv1, void const *pv2)
{
    int const *icp1, *icp2;

    icp1 = (int const *)pv1;
    icp2 = (int const *)pv2;
    return *icp1 - *icp2;
}

int cmpdoublep(void const *pv1, void const *pv2)
{
    double const *dcp1, *dcp2;

    dcp1 = (double const *) pv1;
    dcp2 = (double const *) pv2;

    if (*dcp1 > *dcp2) return 1;
    else if (*dcp1 < *dcp2) return -1;
    else return 0;
}
