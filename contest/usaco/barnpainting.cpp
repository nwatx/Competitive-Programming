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

const int mx = 1e5+1;
const int MOD = 1e9+7;

int n, k;

vi adj[mx];
int C[mx], dp[mx][4]; // one indexed dp

// number of possible paintings of subtree of node i with color j
// a painting of c includes all paintings of type != c

// there are four possibilities

bool invalid = false;

void dfs(int x, int p) {
	// we know the degree of a tree is 1 if sz(adj[i]) == 1
	if(sz(adj[x]) == 1 && !C[x]) dp[x][1]=1, dp[x][2]=1, dp[x][3]=1;
	else dp[x][C[x]] = 1;

	for(int e : adj[x]) {
		if(e == p) continue;
		dfs(e, x);
		if(C[e] != C[x] && !(C[e] && C[x])) {
			dp[x][1] += dp[e][2] + dp[e][3];
			dp[x][2] += dp[e][1] + dp[e][3];
			dp[x][3] += dp[e][1] + dp[e][2];
		} else {
			// dp[x][]
		}
	}
}

int main() {
	setIO("barnpainting");

	cin >> n >> k;

	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
	}

	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		C[a] = b;
	}

	dfs(1, 0);

	for(int i = 1; i<= n; i++) {
		for(int j = 1; j<=3; j++) cerr << dp[i][j] << " ";
		cerr << "\n";
	}

	ll ret = 1;
	for(int i = 1; i <= 3; i++) ret += dp[1][i];

	invalid ? cout << 0 : cout << ret << "\n";
}