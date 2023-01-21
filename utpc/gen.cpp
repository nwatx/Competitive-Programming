#include "testlib.h"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    /* Read number from command line. */
    int n = atoi(argv[1]); int max_coord = atoi(argv[2]);
 
    /* String of random lowercase Latin letters and digits, length equals to n. */
    cout << rnd.next(2, n) << " " << rnd.next(2, n) << " " << rnd.next(1, max_coord) << " " << rnd.next(1, max_coord) << endl;
}