#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int n, k;

const int mx = 1e6+1;

int dp[101][7]; // dp[i][j] i = room number j = doors unlocked

int main() {
	setIO("cbarn2");

	cin >> n >> k;

	// at every i he can either unlock the door or not
	// if he unlocks the door, then dp[i][j+1] = min(dp[i][j+1], dp[i][j] - )

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			// if he switches, then the distance = dp[i][j] + loop through and calculate (1 + 2 + 3 ... + n)
		}
	}
}