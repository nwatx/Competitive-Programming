#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+1;

int A[mx], dp[mx];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, K; cin >> N >> K;

	for(int i = 0; i < N; i++) {
		cin >> A[i];
		dp[i] = 1e9 + 7;
	}

	dp[0] = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 1; j <= K; j++) {
			if(i + j < N) dp[i + j] = min(dp[i + j], dp[i] + abs(A[i] - A[i + j]));
		}
	}

	cout << dp[N - 1] << endl;
}