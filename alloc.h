/* all functions here allocate dynamic memory under the hood.  User has to
 * free memory after use.
 */
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
/* copies NULL-terminated array of strings */
void copy_strs(char **dest, char **source);

/* duplicate NULL-terminated (char *) (automatic) array vt */
char **alloc_strs(char **vt);
/* duplicate NULL-terminated (void *) (automatic) array vt */
void **alloc_voidps(void **vt);

/* same as the prohibited strdup() (strdup is GNU addition to the standard) */
char *alloc_str(char *s);
/* duplicate int.  Same as one liner `ip = new int (i);` */
int *alloc_int(int i);
/* duplicate double.  Same as one liner `dp = new double (d);` */
double *alloc_double(double d);

#endif /* ALLOC_H */
