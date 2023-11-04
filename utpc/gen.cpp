#include "testlib.h"
#include <iostream>
#include <vector>       // std::vector
#include <numeric>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int test_count = 0;
    int sum_n = atoi(argv[1]);
    int curr_sum = 0;
    int random_l = atoi(argv[2]), random_r = atoi(argv[3]);
    vector<vector<int>> s;
    while(1) {
        assert(curr_sum <= sum_n && s.size() <= (2e5));
        if(curr_sum == sum_n || s.size() == (int)2e5) break;
        // generate a number from 1-n
        int need_to_gen = min(sum_n - curr_sum, rnd.next(random_l, random_r));
        vector<int> v(need_to_gen);
        iota(v.begin(), v.end(), 1);
        shuffle(v.begin(), v.end());
        s.push_back(v);
        curr_sum += need_to_gen;
    }
    
    cout << s.size() << "\n";
    for(auto v : s) {
        cout << v.size() << "\n";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if(i != v.size() - 1) cout << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}