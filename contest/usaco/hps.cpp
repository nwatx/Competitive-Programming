#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MX = 1e5+5;

int dp[MX][25][3]; // dp[i][j][k] is the most amount of games she wins at games i with switches j with current item k
int A[MX]; // 0 == H 1 == P 2 == S

int main() { 
    cin.tie(0)->sync_with_stdio(0); 
    freopen("hps.in", "r", stdin); 
    freopen("hps.out", "w", stdout);

	int N, K;

	cin >> N >> K;

	for(int i = 0; i < N; i++) { 
		char a; cin >> a;
		if(a == 'H') A[i] = 0;
		if(a == 'P') A[i] = 1;
		if(a == 'S') A[i] = 2;
	}

	// either she switches to h or p or s or stays

	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= K; j++) {
			for(int k = 0; k < 3; k++) {
				if(k == A[i]) dp[i][j][k]++;
				dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][k]); // switch to not item
				dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][k]); // switch to not item
				dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][k]); // switch to not item
				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]); // stay
			}
		}
	}

	int ret = 0;

	for(int i = 0; i < 3; i++) {
		ret = max(ret, dp[N-1][K][i]);
	}

	cout << ret << endl;

}