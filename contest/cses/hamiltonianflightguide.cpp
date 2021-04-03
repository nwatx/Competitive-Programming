#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back

void setIO() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
}

const int mod = 1e9+7;

vi adj[21];
ll dp[1<<20][21]; // amount of flights of subset S ending at city d

int main() {
	setIO();

	int n, m; cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[b].pb(a);
	}

	dp[1][1] = 1; // there is one way to fly from 1 to itself

	for(int s = 2; s < (1<<n); s++) { // we start from the second city
		if((s & (1 << (n-1))) && s != ((1<<n) - 1)) continue;
		for(int d = 1; d <= n; d++) { // loop through each city
			if((s & (1 << (d-1))) == 0) continue;
			for(int v : adj[d]) {
				if(s & (1<<(v-1))) { // if v is in the mask
					dp[s][d] += dp[s-(1<<(d-1))][v];
					dp[s][d] %= mod;
				}
			}
		}
	}

	cout << dp[(1<<n)-1][n] % mod; 
}