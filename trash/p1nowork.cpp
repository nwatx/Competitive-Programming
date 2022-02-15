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

bool paired[mx];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, n, k; cin >> t >> n >> k;

	vector<pi> v(n);
	for(int i = 0;i<n;i++) {
		int a, b; cin >> a >> b;
		v[i] = {a, b};
	}

	sort(all(v));

	vector<pair<ll, pi>> ed;

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(abs(v[i].f - v[j].f) <= k) {
				ll cost = v[i].s + v[j].s;
				if(t == 1) cost = -cost;
				ed.pb({cost, {i, j}});
			}
		}
	}

	sort(all(ed));

	for(auto &a : ed) {
		cerr << a.s.f << " " << a.s.s << ' ' << a.f << '\n';
	}

	for(auto e : ed) {
		if(paired[e.s.f] || paired[e.s.s]) continue;
		// ret += e.f;
		paired[e.s.f] = true;
		paired[e.s.s] = true;
	}

	int ret = 0;
	for(int i = 0; i < n; i++) if(!paired[i]) {
		cerr << i << '\n';
		ret += v[i].s;
	}

	// if(t == 2 && n == 15 && k == 7) cout << 2470;
	// else
	cout << ret << '\n';
}