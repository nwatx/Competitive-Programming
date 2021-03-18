#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define trav(a,x) for (auto& a: x)
#define all(x) begin(x), end(x)
#define mp make_pair
#define f first
#define s second

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	// get representive component, uses path compression
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int cnt=0;
template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
	trav(a,ed)
	if (D.unite(a.s.f,a.s.s)) {
		ans += a.f;
		cnt++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<pair<ll,pi>> edge;
	for (int i = 0; i < m; i++){
		int a, b; ll c;
		cin >> a >> b >> c;
		edge.push_back(mp(c, mp(a, b)));
	}
	ll ans = kruskal(n, edge);
	if(cnt == n-1){
		cout << ans;
	}
	else{
		cout << "IMPOSSIBLE";
	}
	return 0;
}