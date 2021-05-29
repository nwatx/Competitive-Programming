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
		(void)!freopen((name+".in").c_str(), "r", stdin); // see /general/io
		(void)!freopen((name+".out").c_str(), "w", stdout);
	}
}

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

template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(ed.rbegin(), ed.rend());
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	for(auto a : ed) if (D.unite(a.s.f,a.s.s)) ans += a.f;
	return ans;
}

void solve(int tc) {
	int n; cin >> n;
	vector<vi> A(n, vi(n)), B(n, vi(n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> A[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> B[i][j];
	vi row(n), col(n);
	for(int i = 0; i < n; i++) cin >> row[i];
	for(int i = 0; i < n; i++) cin >> col[i];
	vector<pair<int, pi>> edges;
	int total = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
		if(A[i][j] == -1)  {
			// n + j is used to distinguish rows from cols
			edges.pb({B[i][j], {i, n + j}});
			total += B[i][j];
		}
	}
	cout << "Case #" << tc << ": " << total - kruskal(2*n, edges) << "\n";
}
int main() {
	setIO();
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) solve(i);
}