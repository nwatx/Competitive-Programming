#include <bits/stdc++.h>
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

const int mx = 401;
const int MOD = (int)1e9+7;

int A[mx], suff_max[mx], pfx[mx];

int dp[mx][401]; // switch k times

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		pfx[i] += A[i];
	}

	for(int i = n - 1; i > 0; i--) suff_max[i - 1] = max(A[i - 1], A[i]);
	for(int i = 1; i <= n; i++) pfx[i] += pfx[i - 1];

	for(auto &row : dp) for(auto & a : row) a = MOD;

	dp[0][0] = suff_max[0] * n - pfx[n];

	for(int i = 0; i < n; i++) {
		// sum all the rest
		int remElem = n - i - 1;
		for(int j = 0; j < n; j++) {
			int sum = A[i + 1] * remElem - (pfx[n] - pfx[i]);
			if(A[j] < suff_max[i + 1]) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], suff_max[i + 1] * remElem - pfx[n] - pfx[i]);
			} else {
				dp[i + 1][j] = min(dp[i][j], sum);
			}

			dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
}