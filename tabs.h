#ifndef TABS_H
#define TABS_H

#include <fstream>

/* tabulates double (fixed point, precision 2) */
void tab(std::ostream &cout, double d, int width = 8);
/* tabulates field according to type
 * params:  i int
 *          width (defaults to 8)
 *          x   amount of 0s to pad from the right.  width >= x >= 0.  Defaults
 *              to 0
*/
void tab(std::ostream &cout, int i, int width = 8, int x = 0);
/* tabulates string */
void tab(std::ostream &cout, const char s[], int width = 8);

#endif /* TABS_H */
