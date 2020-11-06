#ifndef SORT_H
#define SORT_H

/* Sort 2 parallel arrays (the date is related by the index).
 * This is very bad and cannot generalize.  Modify it to suit your needs.  (Here
 * it sorts two arrays of char * using strcmp)
 *
 * Modified from K&R qsort implementation
 */
void qsort2(const char *v1[], const char *v2[], int left, int right);

/* swaps char pointers */
void swappch(char const *v[], int i, int j);

/* qsort: sort v[left]...v[right] into increasing order 
 * 
 * Can sort any array of pointers, given a comparison fuction.  In contrast to
 * stdlib.h qsort,  this one's comparison function's arguments take the pointers
 * (v[i], v[left]) instead of the pointer to those pointers (&v[i], &v[j]).
 * Meaning you can use `(int (*)(void *, void*)) strcmp` for example.
 * Because of this, the size of each element of the array need's not to be
 * passed, but you ONLY sort pointers.  To sort whatever object you want,  use
 * stdlib.h qsort.
 * 
 * taken from K&R p.120
 */
void qsortKR(void *v[], int left, int right,
        int (*comp)(void *, void*));

/* swaps pointers */
void swap(void *v[], int i, int j);


/* Comparison functions for K&R qsort  (and alse INF281 Guanira's ordenaG)
 * ======================================================================= */

/* These take pointer to object.  They require a cast before passing. */

/* strcmp */
int numcmp(char const *pch1, char const *pch2);


/* Comparison functions for stdlib.h qsort
 * ======================================= */

/* These take pointer to pointer to object */

int cmpstrp(const void *pv1, const void *pv2);
int cmpint(void const *pv1, void const *pv2);
int cmpdouble(void const *pv1, void const *pv2);

#endif /* SORT_H */
