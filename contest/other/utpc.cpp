#include <bits/stdc++.h>
 
using namespace std;
const int MOD = (int)1e9 + 7;
 
// you know your sizing is 2 * bet = x
// if this is less than zero, discard it
using ll = long long;
 
/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 */

struct mi {
    int v; explicit operator int() const { return v; } 
    mi() { v = 0; }
    mi(ll _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
    if ((a.v += b.v) >= MOD) a.v -= MOD; 
    return a; }
mi& operator-=(mi& a, mi b) { 
    if ((a.v -= b.v) < 0) a.v += MOD; 
    return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); // asserts are important! 
    return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
/// mi a = MOD+5; ps((int)inv(a));

mi ncr(int n, int r) {
    cout << n << " " << r << endl;
    mi sum = 1;
    for(int i = 1; i <= r; i++) {
        sum = sum * mi(n - r + i) * inv(mi(i));
    }

    cout << sum.v << endl;

    return sum;
}
 
// someone is monitoring your gambling habits, so you can only guarantee profits of up to $k$ in one batch
// print two numbers, your maximum profit, and the minimum number of batches you can take to get to that profit
void solve() {
    int n, m; cin >> n >> m;
 
    vector<long long> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    vector<long long> cost(m);
    map<int, int> freq;
    for(int i = 0; i < m; i++) {
        cin >> cost[i];
        freq[cost[i]]++;
    }
    
    // find the maximum profit
    sort(v.rbegin(), v.rend());
    sort(cost.begin(), cost.end());
 
    // can take up until cost[i] >= v[i];
    int bestIndex = -1;
    for(int i = 0; i < min(n, m); i++) {
        if(cost[i] > v[i]) {
            break;
        }
 
        bestIndex = i;
    }
 
    int zC = 0;
 
    vector<long long> profits;
    for(int i = 0; i <= bestIndex; i++) {
        if(v[i] - 2 * cost[i] >= 0) {
            profits.push_back(v[i] - 2 * cost[i]);
        } else if(v[i] == cost[i]) {
            zC++;
        }
    }

    sort(profits.begin(), profits.end());

    auto fact = [](int x) {
        mi ret = 1;
        for(int i = 1; i <= x; i++) ret = ret * mi(i);
        return ret;
    };

    mi tot = fact(profits.size() + zC);

    if(bestIndex != -1) {
        // find the cheapest profit and the number of indices that have that cheapest profit
        int cheapest = cost[bestIndex];
        // count # of occuring

        int cheapest_freq = freq[cheapest];

        mi new_mul = ncr(cheapest_freq, count(profits.begin(), profits.end(), cheapest));
        cout << new_mul.v << endl;
        tot *= new_mul;
    }
 
    ll sum = 0;
    for(long long x : profits) {
        assert(x >= 0);
        // cout << "profit:" <<  x << endl;
        sum += x;
    }

    printf("%.2f %d", sum/2.0, tot.v);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}