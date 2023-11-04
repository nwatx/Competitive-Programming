#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define lb(x,y) lower_bound(all(x),y)-begin(x)

mt19937 rng;

ll mod = 1000000007;

int mPow(int n, int p) {
    int res = 1, pow = n;
    while (p > 0) {
        if ((p & 1) == 1)
            res = (int)((ll)res * pow % mod);
        pow = (int)((ll)pow * pow % mod);
        p >>= 1;
    }
    return res;
}

int mInv(int n) { return mPow(n, mod - 2); }

void solve() {
    int N, M; cin >> N >> M;
    vector<int> r(N), c(M);
    for (int i = 0; i < N; i++) cin >> r[i];
    for (int i = 0; i < M; i++) cin >> c[i];
    sort(all(r));
    sort(all(c));
    reverse(all(r));
    ll cur = 0, res = 0;
    int end = 0;
    for (int i = 0; i < min(N, M); i++) {
        cur += r[i] - c[i] * 2;
        if (cur >= res) end = i;
        res = max(res, cur);
    }
    ll ways = 1;
    for (int i = 0; i <= end; i++) {
        ways *= (i + 1);
        ways %= mod;
    }
    int left = end, right = end;
    while (left - 1 >= 0 && c[left - 1] == c[left]) left--;
    while (right + 1 < M && c[right + 1] == c[right]) right++;
    for (int i = 1; i <= right - left + 1; i++) ways *= i, ways %= mod;
    for (int i = 1; i <= end - left + 1; i++) ways *= mInv(i), ways %= mod;
    for (int i = 1; i <= right - end; i++) ways *= mInv(i), ways %= mod;
    cout << setprecision(20) << (res / 2.0) << " " << ways << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    solve();

    return 0;
}