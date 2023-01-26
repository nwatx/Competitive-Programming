#include <bits/stdc++.h>

using namespace std;

const int mx = (int)2e5 + 1;
vector<int> adj[mx]; int dist1[mx], dist2[mx], ret[mx];

void dfs1(int v, int p) {
	for(int e : adj[v]) {
		if(e != p) {
			dfs1(e, v);
			if(dist1[e] + 1 > dist1[v]) {
				dist2[v] = dist1[v];
				dist1[v] = dist1[e] + 1;
			} else if(dist1[e] + 1 > dist2[v]) {
				dist2[v] = dist1[e] + 1;
			}
		}
	}
}

void dfs2(int v, int p, int g) {
	ret[v] = max(dist1[v], g);

	// cout << v << " " << p << " " << g << "\n";

	for(int e : adj[v]) {
		if(e != p) {
			if(dist1[e] + 1 == dist1[v]) dfs2(e, v, max(dist2[v], g) + 1);
			else dfs2(e, v, ret[v] + 1);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1(1, 0);
	dfs2(1, 0, 0);

	// for(int i = 1; i <= n; i++) {
	// 	cerr << dist1[i] << " ";
	// }

	for(int i = 1; i <= n; i++) {
		cout << ret[i] << " ";
	}
}