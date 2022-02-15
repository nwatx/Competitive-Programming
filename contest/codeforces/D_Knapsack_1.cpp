#include <bits/stdc++.h>

using namespace std;

const int mx = 1e6 + 1;

using ll = long long;

int A[101], B[101];
ll dp[mx];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> A[i] >> B[i];
	for(int i = 0; i < n; i++) {
		for(int j = mx - A[i]; j >= 0; j--) {
			dp[j + A[i]] = max(dp[j + A[i]], dp[j] + B[i]);
		}
	}

	cout << dp[m];
}