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

const ll MOD = 1e9 + 7;

template <class T> struct Matrix {
	vector<vector<T>> v;
	void init(int n, int m) {
		v = vector<vector<T>>(n, vector<T>(m));
	}

	Matrix operator*(Matrix b) {
		int x = sz(v), y = sz(v[0]), z = sz(b.v[0]);
		assert(y == sz(b.v));
		Matrix<T> ret; ret.init(x, z);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < z; k++) {
					ret.v[i][k] += v[i][j] * b.v[j][k];
					ret.v[i][k] %= MOD;
				}
			}
		}
		return ret;
	}
};

int main() {
	ll n, m; cin >> n >> m;
	// cerr << n << " " << m;
	m--;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	Matrix<ll> A, B;
	A.init(n, n); B.init(n, n);


	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(__builtin_popcountll(v[i] ^ v[j]) % 3 == 0) A.v[i][j] = 1;
		}
	}


	Matrix<ll> ret; ret.init(n, n);
	for (int i =0 ; i < n ; i++) ret.v[i][i] = 1;

	for(; m > 0; m /= 2) {
		if(m & 1) ret = ret * A;
		A = A * A;
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans += ret.v[i][j];
			ans %= MOD;
		}
	}

	cout << ans << '\n';
}