#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "nombres.h"
#include "input.h"
#include "alloc.h"
#include "sort.h"
#include "estructuras_voidptr/list.h"
#include "estructuras_voidptr/stack.h"
#include "estructuras_voidptr/queue.h"
#include "estructuras_voidptr/bintree.h"

#define SIZE 100
#define MAX 1000

using namespace std;

/* some useful test data 
 * ===================== */

char const *ss[] = {"aaa", "bbb", "ccc", "1234", "56789", "ZAPP"};
int is[] = {42,5,2,4,3,1};
double ds[] = {42.52,-5234,2.432412,4.342,0.2342,1.666};

struct Robot {
    int id;
    char name[SIZE];
    int year;
};
typedef struct Robot Robot_t;

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

void printrobot(Robot_t const &r)
{
    printf("%3d %-40s %d\n", r.id, r.name, r.year);
}

void printrobotptr(Robot_t const *r)
{
    printf("%3d %-40s %d\n", r->id, r->name, r->year);
}

/* there exist cmprobotptr too! (for use with `qsort()`) */


/* test functions
 * ============== */

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

/* Same as the above, they both work.  
 *
 * The only "difference" is that this one does not need cast when using it with
 * cstdlib's qsort().  I find it weird though that C++ does not complain about
 * "implicit conversion of `void *` to `other pointer type`" when using the
 * former one `cmprobotptr` with qsort.  Because it seems that's what it is
 * doing with the parameters when the function is executed.
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
    qsort(is, n, sizeof *is, cmpintp);
    for (i = 0; i < n; i++) printf("%8d", is[i]); printf("\n");
    /* doubles */
    n = sizeof ds / sizeof *ds;
    for (i = 0; i < n; i++) printf("%10.3f", ds[i]); printf("\n");
    qsort((void *)ds, n, sizeof *ds, 
            (int (*)(void const *, void const *)) cmpdoublep);
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

void printintp(int *ip)
{
    printf("%5d", *ip);
    printf("\n");
}

// This and `printrobot` both work for `list_traverse`.  Though that is not
// standart syntax and is undefined behaviour by the standard.  The compiler
// does not complain because C-style type cast to `void *` virtaully removes all
// type safety.  Also because most most compilers implement reference using
// pointer, other compilers might use some other method and the code will break.
/* Don't pass pointer to it! It works but it is not OK! */
void printint(int &i)
{
    printf("%5d", i);
    printf("\n");
}

void delete_int(int *ip)
{
    delete ip;
}

//void *alloc_ind_int(int *ip)
//{
//    int temp;
//
//    temp = *ip;
//    ip = new int;
//    *ip = temp;
//    return ip;
//}

void list_test()
{
    void *l;
    int i, n;

    list_create(l);
    n = sizeof is / sizeof *is;
    for (i = 0; i < n; i++)
        //list_add(l, &is[i], (void * (*)(void *))alloc_ind_int);
        list_add(l, alloc_int(is[i]), cmpintp);
    list_traverse(l, (void (*)(void *))printintp);
    list_free(l, (void (*)(void *))delete_int);

    n = sizeof robotptrs / sizeof *robotptrs;
    for (i = 0; i < n; i++)
        list_add(l, robotptrs[i], cmprobotptrv);
    list_traverse(l, (void (*)(void *))printrobotptr);
    // since robots are not really allocated just create another list on top to
    // empty it
    list_create(l);
}

void stack_test()
{
    void *s;
    int i, n;
    int *ip;
    Robot_t *rp;

    stack_create(s);
    /* ints */
    n = sizeof is / sizeof *is;
    for (i = 0; i < n; i++)
        stack_push(s, alloc_int(is[i]));
    for (i = 0; !stack_isempty(s); i++) {
        ip = (int *) stack_pop(s);
        printintp(ip);
        delete_int(ip);
    }

    /* robots */
    n = sizeof robotptrs / sizeof *robotptrs;
    printf("Entry order:\n");
    for (i = 0; i < n; i++) {
        printrobotptr(robotptrs[i]);
        stack_push(s, robotptrs[i]);
    }
    printf("Now this robot is at the top of the stack!:\n");
    printrobotptr((Robot_t *)stack_top(s));
    printf("Exit order:\n");
    for (i = 0; !stack_isempty(s); i++) {
        printrobotptr((Robot_t *)stack_pop(s));
    }

    /* stack is empty at this point */
}

void printdoublep(double *dp)
{
    printf("%10.3g\n", *dp); // +7, g <3
}

void delete_double(double *dp)
{
    delete dp;
}

void queue_test()
{
    void *q;
    int i, n;
    double *dp;

    queue_create(q);
    /* doubles */
    n = sizeof ds / sizeof *ds;
    for (i = 0; i < n; i++)
        queue_push(q, alloc_double(ds[i]));
    for (i = 0; !queue_isempty(q); i++) {
        dp = (double *)queue_pop(q);
        printdoublep(dp);
        delete_double(dp);
    }

    /* robots */
    n = sizeof robotptrs / sizeof *robotptrs;
    printf("Entry order:\n");
    for (i = 0; i < n; i++) {
        printrobotptr(robotptrs[i]);
        queue_push(q, robotptrs[i]);
    }
    printf("Now this robot is at the front of the queue!:\n");
    printrobotptr((Robot_t *)queue_front(q));
    printf("And this robot is at the back of the queue!:\n");
    printrobotptr((Robot_t *)queue_back(q));
    printf("Exit order:\n");
    for (i = 0; !queue_isempty(q); i++) {
        printrobotptr((Robot_t *)queue_pop(q));
        /* no delete bc no alloc */
    }

    /* stack is empty at this point */
}

void squareintp(int *ip)
{
    *ip = *ip * *ip;
}

void delete_nothing(void *p)
{
    /* :D */
}

void bintree_test()
{
    void *bt;
    int i, n;
    int *ip, *ip2;
    Robot_t *rp;

    bintree_create(bt);
    /* ints */
    n = sizeof is / sizeof *is;
    printf("Entry order:\n");
    for (i = 0; i < n; i++) {
        bintree_add(bt, alloc_int(is[i]), cmpintp);
        printintp(&is[i]);
    }
    printf("bintree traversal:\n");
    bintree_traverse(bt, (void (*)(void *))printintp);
    bintree_traverse(bt, (void (*)(void *))squareintp);
    printf("Square all nodes (intp):\n");
    printf("bintree traversal (again):\n");
    bintree_traverse(bt, (void (*)(void *))printintp);
    /* I found and destroyed a bug on bintree_get  YAY!*/
    ip = alloc_int(9);
    printf("get pointer to elem that compares equal to *ip:\n");
    ip2 = (int *) bintree_get(bt, ip, cmpintp);
    if (!ip2) fprintf(stderr, "error: element *ip (%d) not found\n", *ip);
    else printf("ip2 = %5d\n", *ip2);
    if (ip == ip2) fprintf(stderr, "error: ip = ip2\n");
    delete ip;
    /* do not delete ip2 here.  Only delete bt alltogether */
    /* How to assert that bintree_free efectivelly freed each node and element
     * of the tree.  I can tell it works because it is a small function, but
     * what to do with something more complex? */
    bintree_free(bt, (void (*)(void *))delete_int);
    if (bt) perror("bt does not point to NULL\n");

    /* robots */
    n = sizeof robotptrs / sizeof *robotptrs;
    printf("Entry order:\n");
    for (i = 0; i < n; i++) {
        bintree_add(bt, robotptrs[i], 
                (int (*)(void const *, void const *))cmprobotptr);
        printrobotptr(robotptrs[i]);
    }
    printf("bintree traversal:\n");
    bintree_traverse(bt, (void (*)(void *))printrobotptr);
    rp = (Robot_t *) bintree_get(bt, robotptrs[3], 
            (int (*)(void const *, void const *))cmprobotptr);
    if (rp != robotptrs[3]) perror("rp no apunta a robot Rodriga :(\n");
    printf("Retrieved pointer:\n");
    if (rp) printrobot(*rp);
    /* just dealloc nodes */
    bintree_free(bt, delete_nothing);
    if (bt) perror("bt does not point to NULL\n");
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
    /* estructuras_voidptr */
//    list_test();            // GOOD
//    stack_test();           // GOOD
//    queue_test();           // GOOD
//    bintree_test();         // GOOD
    return 0;
}
