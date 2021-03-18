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

// i = length of string
// j = amount painting
// k = character

int dp[1501][1501][26];
int S[1501];

int main() {
	setIO();

	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		char a; cin >> a;
		S[i] = (int)(a - 'a');
	}

	for(int k = 0; k < 26; k++) { // lower case characters
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				// appending a character
				dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + 1);

				// if we can "save"
				if(S[i] == k)
					dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + 1);
			}
		}
	}

	// take the current best and translate it
	// dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

	for(int k = 0; k < 26; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

	for(int i = 0; i < n; i++) {
		cerr << (char)(S[i]+'a') << " " << dp[i][1][0] << "\n";
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; i++) {
		int a; char b;
		cin >> a >> b;
		b -= 'a';

		cout << dp[n][a][(int)b] << '\n';
	}
}