//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
//EndCodeSnip

const int MAX_N = 301;

int A[MAX_N], dp[MAX_N][MAX_N];

int main() {
	setIO();
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = MAX_N + 1;
		}
	}

	for (int i = 0; i < n; i++) dp[i][i] = 1;
	
	for (int s = 1; s <= n; s++) {
		for (int i = 0; i <= n - s; i++) {
			for (int j = i; j < i + s; j++) {
				int k = i + s - 1;
				// explained in editorial
				if (A[i] == A[k])
					dp[i][k] = min(dp[i][k], dp[i][j] + dp[j + 1][k] - 1);
				dp[i][k] = min(dp[i][k], dp[i][j] + dp[j + 1][k]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}