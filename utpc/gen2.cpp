#include "testlib.h"
#include <iostream>
#include "assert.h"
#include "vector"
#include <numeric>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    /* Read number from command line. */
    // int n = opt<int>(1);
    // int q = opt<int>(2);
    // int max_len = opt<int>(3);
    // int r = opt<int>(4); // random
    int n = 10;
    int q = 5;
    int max_len = 10;
    int r = 0;

    cout << n << "\n";

    if(r == 0) {
        string s = "abcabc";
        // string s = opt<string>(5);
        assert(q * s.size() <= (int)1e5);

        vector<int> mask(n);
        for(int i = 0; i < q; i++) {
            mask[i] = 1;
        }

        shuffle(mask.begin(), mask.end());

        int idx = 0;
        for(int i = 0; i < n; i++) {
            cout << "0 ";
            while(idx < n && !mask[idx]) {
                cout << (char)s[idx];
                idx++;
            }
            cout << "\n";
        }
    }




    /* String of random lowercase Latin letters and digits, length equals to n. */
    // cout << rnd.next(2, n) << " " << rnd.next(2, n) << " " << rnd.next(1, max_coord) << " " << rnd.next(1, max_coord) << endl;
}