#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+1;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; 
}

long long dp[mx];
int w[101], v[101];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, W; cin >> N >> W;
	for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
	for(int i = 0; i < mx; i++) dp[i] = 1e18; 

	dp[0] = 0;

	for(int i = 0; i < N; i++) {
		for(int j = mx - 1; j >= 0; j--) {
			if(dp[j] + w[i] <= W) ckmin(dp[j + v[i]], dp[j] + w[i]);
		}
	}

	for(int i = mx - 1; i >= 0; i--) {
		if(dp[i] != 1e18) {
			cout << i << endl;
			break;
		}
	}
}