#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{4, 6, 8, 9, 10, 11, 12, 14, 15};
    // vector<int> v{9, 15, 10, 14, 8, 12};

    int best = 0;
    vector<int> ret{13};

    do {
        int sum = 13;

        set<int> used;
        used.insert(13);
        used.insert(1);

        vector<int> g{13};
        
        for(int x : v) {
            bool good = 0;

            if(used.count(x)) continue;

            // removes divisors
            for(int i = 1; i < x; i++) {
                // if divisible
                if(x % i == 0) {
                    // taken away by taxman
                    if(!used.count(i)) {
                        good = 1;
                        used.insert(i);
                    }
                }
            }

            if(good) {
                sum += x;
                g.push_back(x);
                used.insert(x);
            }
        }

        // cout << sum << endl;

        if(sum > best) {
            ret = g;
            best = sum;
        }
    } while(next_permutation(v.begin(), v.end()));

    cout << "best: " << best << endl;
    for(int x : ret) {
        cout << x << " ";
    }
}