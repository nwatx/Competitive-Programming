#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double;

using pi = pair<int,int>;
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
using vi = V<int>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);

vi apply(vi p, vi a) {
	assert(sz(p) == sz(a));
	vi ret(sz(p));
	
	F0R(i, sz(p)) {
		ret[i] = p[a[i]];
	}

	return ret;
}

void solve() {
	int n, m; ll k;
	cin >> n >> m >> k;
	vi p(n), t(n);
	iota(all(p), 0);
	iota(all(t), 0);

	rep(m) {
		int a, b; cin >> a >> b;
		a--;
		reverse(p.begin() + a, p.begin() + b);
	}

	for(; k > 0; k /= 2) {
		if(k & 1) t = apply(p, t);
		p = apply(p, p);
	}

	F0R(i, n) cout << t[i] + 1 << '\n';
}

int main() { cin.tie(0)->sync_with_stdio(0);
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout); 
	int n = 1;
	// cin >> n;
	for(int i = 0; i < n; i++) {
		solve();
	}
}