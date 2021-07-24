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

/**
 * Description: Disjoint Set Union with path compression
	 * and union by size. Add edges and test connectivity. 
	 * Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vi e, c; void init(int N) { e = vi(N,-1); c = vi(N); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y, int t) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; c[x] = t; return 1;
	}
};

int main() {
	setIO();

	int n, m, q; cin >> n >> m >> q;

	DSU dsu; dsu.init(n + 1);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dsu.unite(a, b, i + 1);
	}
	
	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		if(!dsu.sameSet(a, b)) {
			cout << -1 << '\n';
		} else {
			int ans = 0;

			while(a != b) {
				if(dsu.size(a) > dsu.size(b)) swap(a, b);
				ans = max(ans, dsu.c[a]);
				a = dsu.e[a];
			}

			cout << ans << "\n";
		}
	}
}