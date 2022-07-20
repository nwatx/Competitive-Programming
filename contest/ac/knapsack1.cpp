#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+1;

template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; 
}

long long dp[101][mx];
int w[101], v[101];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, W; cin >> N >> W;
	for(int i = 0; i < N; i++) cin >> w[i] >> v[i];

	for(int i = 0; i < N; i++) for(int j = 0; j <= W; j++) {
		if(j + w[i] <= W) ckmax(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
		ckmax(dp[i + 1][j], dp[i][j]);
	}

	cout << dp[N][W] << endl;
}