/* Functions to read values from the cryptic LP1's input files
 * Mitsuo
 * 2020-09-30
*/

#ifndef INPUT_H
#define INPUT_H

#include <iostream>

/* Get separated values
 *
 * Behaves like string::getline() but an array of delimitation characters is
 * passed instead of a single delim char.
*/
std::istream& getsep(std::istream& is, char s[], int n, const char delim[]);

#endif /* INPUT_H */
