#ifndef ALLOC_H
#define ALLOC_H

#define INCREMENTO 5

/* gives enough memory to append value to NULL-terminated array v.
 * Initially (char **&) v must be NULL 
 * 
 * Internally it allocates a new array every INCREMENTO append operations.  VERY
 * inefficient.  Time complexity is O(n**2).  On the other hand, if instead of
 * adding INCREMENTO we multiply by e.g. 2,  the time complexity improves to
 * O(n) class.
*/
void porincrementos_str(char **&v, int &size, char *value);
/* 'transfers' whole array of strings */
void copy_strs(char **dest, char **source);

/* duplicate NULL-terminated (char *) array v */
char **alloc_strs(char **vt);
/* duplicate NULL-terminated (void *) array v */
void **alloc_voidps(void **v);

/* same as the prohibited strdup() */
char *alloc_str(char *s);
/* duplicate int */
int *alloc_int(int i);
/* duplicate double */
double *alloc_double(double d);

#endif /* ALLOC_H */
