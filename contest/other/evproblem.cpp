// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long double dpl[1 << 13], dpr[1 << 13];
int sum[1 << 26];

int main() {
    vector<int> v;
    for(int i = 2; i <= 10; i++) {
        v.push_back(i);
        v.push_back(-i);
    }

    for(int i = 0; i < 4; i++) {
        v.push_back(10);
        v.push_back(-10);
    }

    sort(v.begin(), v.end());

    int n = 26;
    dpl[(1 << n / 2) - 1] = 0;

    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if((i & (1 << j))) {
                sum[i] += v[j];
            }
        }
    }

    for(int s = (1 << n) - 2; ~s; s--) {
        long double ev = 0;
        int elem_left = n - __builtin_popcount(s);
        for(int i = 0; i < n; i++) {
            if(!(s & (1 << i))) {
                ev += dp[s | (1 << i)];
            }
        }

        ev /= elem_left;
        dp[s] = max(dp[s], 1.0L * sum[s]);
        dp[s] = max(dp[s], ev);
    }

    cout << setprecision(16) << fixed;
    cout << dp[0];
}
