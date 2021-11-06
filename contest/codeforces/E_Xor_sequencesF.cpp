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

template <class T> struct Matrix {
	V<V<T>> v;
	void init(int n, int m) {
		v = V<V<T>>(n, V<T>(m));
	}

	Matrix operator*(Matrix b) {
		int x = sz(v), y = sz(v[0]), z = sz(b.v[0]);
		assert(y == sz(b.v));
		Matrix<T> ret; ret.init(x, z);
		F0R(i, x) F0R(j, y) F0R(k, z) ret.v[i][k] += v[i][j] * b.v[j][k], ret.v[i][k] %= MOD;
		return ret;
	}
};

void solve() {
	ll n, m; cin >> n >> m;
	// cerr << n << " " << m;
	m--;
	vector<ll> v(n);
	F0R(i, n) cin >> v[i];

	Matrix<ll> A, B;
	A.init(n, n); B.init(n, n);


	F0R(i, n) {
		F0R(j, n) {
			if(__builtin_popcountll(v[i] ^ v[j]) % 3 == 0) A.v[i][j] = 1;
		}
	}


	Matrix<ll> ret; ret.init(n, n);
	F0R(i, n) ret.v[i][i] = 1;

	for(; m > 0; m /= 2) {
		if(m & 1) ret = ret * A;
		A = A * A;
	}

	ll ans = 0;

	F0R(i, n) F0R(j, n) ans += ret.v[i][j], ans %= MOD;
	// F0R(i, n) { 
	// 	F0R(j, n) {
	// 		cerr << ret.v[i][j] << ' ';
	// 	}
	// 	cerr << '\n';;
	// }

	cout << ans << '\n';
}


int main() { cin.tie(0)->sync_with_stdio(0);
	int n = 1;
	// cin >> n;
	for(int i = 0; i < n; i++) {
		solve();
	}
}