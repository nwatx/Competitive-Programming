#include <bits/stdc++.h> // see C++ Tips & Tricks
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") { // name is nonempty for USACO file I/O
	cin.tie(0)->sync_with_stdio(0); // see Fast Input & Output
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vi adj[(int)1e5 + 1], r_adj[(int)1e5 + 1];
vi S;
bool vis[(int)1e5 + 1];

void dfs(int x) {
	vis[x] = true;

	for(const int &e : adj[x]) {
		if(!vis[e]) {
			dfs(e);
		}
	}

	S.pb(x);
}

int dp1[(int)1e5 + 1], dp2[(int)1e5 + 1]; // {dist, prev}

int main() {
	setIO("a");

	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		r_adj[b].pb(a);
	}

	dfs(1);
	fill(dp1, dp1 + n + 1, -1);
	for(int i = 0; i <= n; i++) vis[i] = false;

	dp1[n] = 1;

	reverse(all(S));

	int cnt = 0;

	for(int i : S) {
		queue<int> bfs;
		bfs.push(i);
		while(sz(bfs)) {
			int top = bfs.front();
			cnt++;
			bfs.pop();
			// cerr << top << ":\n";
			// if(vis[top]) continue;
			vis[top] = true;

			if(dp1[top] == -1) continue;
			
			for(const int &e : r_adj[top]) {
				// cout << e << " " << top << "::\n";
				if(dp1[top] + 1 >= dp1[e]) {
					dp2[e] = top;
					dp1[e] = dp1[top] + 1;
				}

				bfs.push(e);
			}
		}		
	}

	cerr << cnt;

	// for(int i = 1; i <= n; i++) {
	// 	cerr << dp[i].f << " " << dp[i].s << "\n";
	// }

	if(dp1[1] == -1) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << dp1[1] << endl;

		for(int i = 1; i != n; i = dp2[i]) {
			// cerr << i << "\n";
			cout << i << " ";
		}

		cout << n << "\n";
	}

}