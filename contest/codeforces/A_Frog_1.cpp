#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+1;

int A[mx], dp[mx];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N; cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> A[i];
		dp[i] = 1e9 + 7;
	}

	dp[0] = 0;

	for(int i = 0; i < N; i++) {
		if(i + 1 < N) dp[i + 1] = min(dp[i + 1], dp[i] + abs(A[i] - A[i+1]));
		if(i + 2 < N) dp[i + 2] = min(dp[i + 2], dp[i] + abs(A[i] - A[i+2]));
	}

	cout << dp[N - 1] << endl;
}