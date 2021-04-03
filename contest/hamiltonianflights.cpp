#include <bits/stdc++.h>

using namespace std;

#define ll long long


const int MX = (1 << 21) + 5;

ll dp[MX][21];

vector<int> adj[21];

const ll MOD = (ll)1e9+7;


int main() {

	int N, M; cin >> N >> M;

	for(int i = 0; i < M; i++){

		int a, b; cin >> a >> b;

		adj[b].push_back(a);

	}

	dp[1][1] = 1;

	for(int s = 2; s < 1 << N; s++){

		if((s & (1 << (N-1))) && s != ((1 << N) - 1)) continue;

		for(int i = 1; i <= N; i++){

			if((s & (1 << (i-1))) == 0) continue;

			for(int j : adj[i]){

				if((s & (1 << (j-1)))){

					dp[s][i] += dp[s - (1 << (i-1))][j]; dp[s][i] %= MOD;

				}

			}

		}

	}

	cout << dp[(1 << N) - 1][N] % MOD << '\n';

	return 0;

}
