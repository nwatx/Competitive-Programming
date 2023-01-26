// [auto_folder]: 
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

const int mx = (int)1e5 + 1;
const int MOD = (int)1e9 + 7;

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

/**
 * Description: Hash map with the same API as unordered\_map, but \tilde 3x faster.
	* Initial capacity must be a power of 2 if provided.
 * Source: KACTL
 * Usage: ht<int,int> h({},{},{},{},{1<<16});
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class K> using hs = gp_hash_table<K,null_type>;

int N, M;
vi adj[mx];
int deg[mx];
bool inc[mx];
bool del[mx];
vector<int> curr;

void setIO(string name = "") { // name is nonempty for USACO file I/O
	cin.tie(0)->sync_with_stdio(0); // see Fast Input & Output
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
	// setIO("a");
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
		deg[a]++; deg[b]++;
	}

	int ret = 0;
	for(int i = 1; i <= N; i++) curr.pb(i);
	DSU d;
	
	for(int mD = 1; mD * mD <= M; mD++) {
		d.init(N + 1);

		for(int x : curr) for(int e : adj[x]) if(!del[e] && d.unite(x, e)) {
			ret = max(ret, mD * d.size(x));
		}

		// then remove all nodes with degree of 2
		queue<int> rm;
		for(int x : curr) {
			if(deg[x] == mD) {
				rm.push(x);
			}
		}

		while(sz(rm)) {
			int top = rm.front(); rm.pop();
			if(del[top]) continue;
			del[top] = true;
			for(int e : adj[top]) {
				if(--deg[e] <= mD) {
					rm.push(e);
				}
			}
			adj[top].clear();
		}

		vector<int> inc;
		for(int x : curr) {
			if(deg[x] > mD) inc.pb(x);
		}
		swap(curr, inc);
	}

	cout << ret;
}