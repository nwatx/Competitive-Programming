#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3+1;

long long dp[20001];
int w[MAX_N], s[MAX_N], v[MAX_N], p[MAX_N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	for(int i = 0; i < N; ++i) cin >> w[i] >> s[i] >> v[i];

	iota(p, p + N, 0);

	sort(p, p + N, [&](const int &a, const int &b) {
		return w[a] + s[a] < w[b] + s[b];
	});

	for(int i = 0; i < N; ++i) {
		int x = p[i];
		// loop through elements <= s[x] + w[x]
		for(int j = s[x]; j >= 0; --j) {
			dp[j + w[x]] = max(dp[j + w[x]], dp[j] + v[x]);
		}
	}

	cout << *max_element(dp, dp + 20001) << endl;
}