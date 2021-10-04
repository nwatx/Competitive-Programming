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

//CodeSnip{CPP Short Template}


//BeginCodeSnip{Topographical Sort}
// /**
//  * Description: sorts vertices such that if there exists an edge x->y, then x goes before y
//  * Source: KACTL
//  * Verification: https://open.kattis.com/problems/quantumsuperposition
//  */

struct TopoSort {
	int N; vi in, res;
	vector<vi> adj;
	void init(int _N) { N = _N; in.resize(N); adj.resize(N); }
	void ae(int x, int y) { adj[x].pb(y), in[y] ++; }
	bool sort() {
		priority_queue<int, vi, greater<int>> todo; 
		for(int i = 1; i < N; i++) if (!in[i]) todo.push(i);
		while (sz(todo)) {
			int x = todo.top(); todo.pop(); res.pb(x);
			for(const auto &i : adj[x]) if (!(--in[i])) todo.push(i);
		}
		return sz(res) == N - 1;
	}
};
//EndCodeSnip{Topographical Sort}

const int mx = 2e5+1;

vi ret;
vector<vi> order;
int n, m;

bool check(int x) {
	TopoSort T; T.init(n + 1);
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < sz(order[i]) - 1; j++) {
			T.ae(order[i][j], order[i][j + 1]);
		}
	}
	bool ans = T.sort();
	if(ans) ret = T.res;

	return ans;
}

int main() {
	setIO("milkorder");
	cin >> n >> m;
	order.resize(m);

	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		vi v(k);
		for(int j = 0; j < k; j++) cin >> v[j];
		order[i] = v;
	}

	int lo = 0, hi = m;

	while (lo < hi) { // find last index f is true
		int mid = lo+(hi-lo+1)/2;
		check(mid) ? lo = mid : hi = mid-1;
	} 

	for(int i = 0; i < n; i++) {
		cout << ret[i];
		if(i != n - 1) cout << " ";
	}
}