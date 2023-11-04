#include "testlib.h"
#include <iostream>
#include <vector>       // std::vector
#include <numeric>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int l = atoi(argv[1]), r = atoi(argv[2]);

    vector<pair<int, int>> v;
    for(int i = l; i <= r; i++) {
        for(int j = 0; j <= r; j++) {
            if(v.size() >= (int)1e5) break;
            v.push_back({i, j});
        }
    }

    assert(v.size() <= (int)1e5);

    cout << v.size() << endl;
    for(auto e : v) {
        cout << e.first << " " << e.second << "\n";
    }

    return 0;
}