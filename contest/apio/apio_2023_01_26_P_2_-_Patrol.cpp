// [auto_folder]: apio
// ^ type folder name for scripted placement

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

const int mx = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;

int N, K;

vi adj[mx];
int in_sub[mx], in_sub_2[mx], dist[mx], f2[mx], furthest[mx], furthest_2[mx];

void dfs_1(int v, int p) {
	for(int e : adj[v]) {
		if(e != p) {
			dfs_1(e, v);
			int s = in_sub[e] + 1;
			if(s >= in_sub[v]) {
				swap(in_sub[v], in_sub_2[v]);
				in_sub[v] = s;
				furthest[v] = furthest[e];
			} else if(s > in_sub_2[v]) {
				in_sub_2[v] = s;
				furthest[v] = furthest_2[e];
			}
		}
	}
}

void dfs_2(int v, int p, int g, int f) {
	// g is outside subtree
	dist[v] = in_sub[v] + g;

	cerr << v << " " << g << " " << f << "\n";

	// if max dist is outside subtree
	if(dist[v] <= g) f2[v] = f;
	else f2[v] = furthest[v];

	for(int e : adj[v]) {
		if(e != p) {
			// if biggest subtree take second largest
			if(in_sub[e] + 1 == in_sub[v]) {
				if(g >= in_sub_2[v]) {
					dfs_2(e, v, g + 1, f);
				} else {
					dfs_2(e, v, in_sub_2[v] + 1, furthest_2[v]);
				}
			} else {
				dfs_2(e, v, in_sub[v] + 1, furthest[v]);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;

	for(int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
	}

	for(int i = 1; i <= N; i++) furthest[i] = i, furthest_2[i] = i;

	dfs_1(1, 0);

	// cout << "\nfurthest\n";
	// for(int i = 1; i <= N; i++) {
	// 	cout << i << ":" << furthest[i] << " ";
	// }
	// cout << "\n";

	dfs_2(1, 0, in_sub_2[1], furthest_2[1]);

	cout << "in_sub\n";
	for(int i = 1; i <= N; i++) {
		cout << i << ":" << in_sub[i] << " ";
	}

	cout << "\nin_sub_2\n";
	for(int i = 1; i <= N; i++) {
		cout << i << ":" << in_sub_2[i] << " ";
	}

	cout << "\ndist\n";
	for(int i = 1; i <= N; i++) {
		cout << i << ":" << dist[i] << " ";
	}

	cout << "\nfurthest\n";
	for(int i = 1; i <= N; i++) {
		cout << i << ":" << f2[i] << " ";
	}
}