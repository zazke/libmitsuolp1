#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "nombres.h"
#include "input.h"
#include "alloc.h"
#include "sort.h"

#define SIZE 100
#define MAX 1000

using namespace std;

void alloc_test()
{
    char **strs;
    int size;
    char s[SIZE];
    char *pch;
    
    int i;

    strs = NULL;
    size = 0;
    for (i = 0; scanf("%s", s) != EOF; i++) {
        pch = alloc_str(s);
        porincrementos_str(strs, size, pch);
    }
    for (i = 0; strs[i]; i++) {
        printf("%s\n", strs[i]);
    }
}

void Capitalize_test()
{
    char s[100] = "hola a todos MI NOMBRE es anTOn10 Suarez!";
    char t[100];

    Capitalize(t, s);
    printf("%s\n", t);
}

void getsep_test()
{
    char s[SIZE];

    while (getsep(cin, s, SIZE, " ,-/\t\n")) {
        cout << s << '\n';
        cin >> ws; // remove extra ws
    }
}

/* swap randomly array of pointers */
void shuffle(void *pv, int n)
{
    void **v;
    int i;

    v = (void **)pv;
    srand(time(NULL));
    for (i = 0; i < n; i++)
        swap(v, i, rand()%n);
}

struct Robot {
    int id;
    char name[SIZE];
    int year;
};
typedef struct Robot Robot_t;

void printrobot(Robot_t const &r)
{
    printf("%3d %-40s %d\n", r.id, r.name, r.year);
}

/* we want them sorted by year (decreasingly), and then by name (increasingly)
 */
int cmprobotptr(Robot_t const *rp1, Robot_t const *rp2)
{
    int ret;
    if (rp1->year != rp2->year)
        return -(rp1->year - rp2->year);  // decreasing order
    else
        return strcmp(rp1->name, rp2->name);
}

/* Same as the above, both work exactly the same.  The only "difference" is that
 * this one does not need cast when using it with cstdlib's qsort().  I find it
 * weird though that C++ does not complain about "implicit conversion of 
 * `void *` to `other pointer type`"  because it seems that's what it is doing
 * with the parameters.
*/
int cmprobotptrv(void const *pv1, void const *pv2)
{
    Robot_t const *rp1, *rp2;

    rp1 = (Robot_t const *) pv1;
    rp2 = (Robot_t const *) pv2;
    if (rp1->year != rp2->year)
        return -(rp1->year - rp2->year);  // decreasing order
    else
        return strcmp(rp1->name, rp2->name);
}

void sort_test()
{
    char const *ss[] = {"aaa", "bbb", "ccc", "1234", "56789", "ZAPP"};
    int is[] = {42, 5,2,4,3,1};
    double ds[] = {42.52,-5234,2.432412,4.342,0.2342,1.666};
    Robot_t robots[4] = { 
        {5, "James", 2042}, 
        {52, "Francisto", 2042}, 
        {25, "Juan", 2042}, 
        {53, "Rodriga", 2077} 
    };
    Robot_t *robotptrs[4] = {
        &robots[0],
        &robots[1],
        &robots[2],
        &robots[3],
    };
    int n_robots = 4;
    int n;
    int i;
    
    /* qsort2() no voy a probar esta porque es tediosa.  Solo es qsortKR
     * modificado */

    /* qsortKR */
    n = sizeof ss / sizeof *ss;
    shuffle(ss, n);
    printf("Shuffled:\n");
    for (i = 0; i < n; i++) printf("%s\n", ss[i]);
    /* strcmp */
    qsortKR((void **) ss, 0, n-1,
            (int (*)(void *, void*)) strcmp);
    printf("Sorted (lexicographycally):\n");
    for (i = 0; i < n; i++) printf("%s\n", ss[i]);
    shuffle(ss, n);
    /* numcmp */
    qsortKR((void **) ss, 0, n-1,
            (int (*)(void *, void*)) numcmp);
    printf("Sorted (numerically):\n");
    for (i = 0; i < n; i++) printf("%s\n", ss[i]);
    /* robots (extra) (cumbersome bc one has to use pointers to the data) */
    shuffle(robotptrs, n_robots);
    printf("Shuffled:\n");
    for (i = 0; i < n_robots; i++) printrobot(*robotptrs[i]);
    qsortKR((void **) robotptrs, 0, n_robots-1,
            (int (*)(void *, void *)) cmprobotptr);
    // The other comparisong also works here btw.
    //qsortKR((void **) robotptrs, 0, n_robots-1,
    //        (int (*)(void *, void *))cmprobotptrv);
    printf("Sorted by year (decreasing), name:\n");
    for (i = 0; i < n_robots; i++) printrobot(*robotptrs[i]);

    /* comparison functions for cstdlib's qsort() */
    /* strings */
    n = sizeof ss / sizeof *ss;
    shuffle(ss, n);
    printf("Shuffled:\n");
    for (i = 0; i < n; i++) printf("%s\n", ss[i]);
    qsort(ss, n, sizeof *ss, cmpstrp);
    printf("Sorted:\n");
    for (i = 0; i < n; i++) printf("%s\n", ss[i]);
    /* ints */
    n = sizeof is / sizeof *is;
    for (i = 0; i < n; i++) printf("%8d", is[i]); printf("\n");
    qsort(is, n, sizeof *is, cmpint);
    for (i = 0; i < n; i++) printf("%8d", is[i]); printf("\n");
    /* doubles */
    n = sizeof ds / sizeof *ds;
    for (i = 0; i < n; i++) printf("%10.3f", ds[i]); printf("\n");
    qsort((void *)ds, n, sizeof *ds, 
            (int (*)(void const *, void const *)) cmpdouble);
    for (i = 0; i < n; i++) printf("%10.3g", ds[i]); printf("\n");  // +7, g <3
    /* robots (extra) */
    shuffle(robotptrs, n_robots);
    printf("Shuffled:\n");
    for (i = 0; i < n_robots; i++) printrobot(*robotptrs[i]);
    qsort(robots, n_robots, sizeof robots[0], 
            (int (*)(const void *, const void *)) cmprobotptr);
    printf("Sorted by year (decreasing), name:\n");
    for (i = 0; i < n_robots; i++) printrobot(robots[i]);
}

int main()
{
//    getsep_test();          // GOOD
    // run with ./a.out < alloc_testinput.txt
//    alloc_test();           // GOOD
//    sort_test();            // GOOD
    /* To understand why this happens see K&R A7.1 (p. 200) */
//    if (shuffle == &shuffle) 
//        printf("doge\n"); 
    return 0;
}
