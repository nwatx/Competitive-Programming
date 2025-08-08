// [auto_folder]: 
// ^ type folder name for scripted placement

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX = (int)1e5;

ll solve(ll R, const string& S) {
    vector<ll> dp(MAX, -1);

    auto dfs = [&](const auto &dfs, int pos, int k, bool under, bool started, const int T, const int T2) -> ll {
        if (pos == S.size()) {
            if (!started) return 0;
            if (T2 != -1) return k == 0;
            return k >= 0;
        }

        int key = pos + (k + 30) * 30 + under * 2 * 30 * 50 + started * 2 * 2 * 30 * 50;
        if (dp[key] != -1) return dp[key];

        ll ans = 0;

        for (int i = 0; i <= (under ? 9 : (S[pos] - '0')); i++) {
            bool is_under = under;
            bool is_started = started || i != 0;
            if (is_started && T2 != -1 && i != T && i != T2) { continue; }
            int new_k = k; if (is_started) new_k += ((i == T) ? 1 : -1);
            ans += dfs(dfs, pos + 1, new_k, is_under || (i < S[pos] - '0'), is_started, T, T2);
        }

        return dp[key] = ans;
    };

    ll ret = 0;

    for (int i = 0; i <= 9; ++i) {
        fill(dp.begin(), dp.end(), -1);
        ret += dfs(dfs, 0, 0, false, false, i, -1);
    }

    ll dup = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            fill(dp.begin(), dp.end(), -1);
            dup += dfs(dfs, 0, 0, false, false, i, j);
        }
    }
    return ret - (dup / 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("odometer.in", "r", stdin);
    // freopen("odometer.out", "w", stdout);

    ll X, Y; cin >> X >> Y;
    cout << solve(Y, to_string(Y)) - solve(X - 1, to_string(X - 1));
}