#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = (ll)1e9 + 7;

vector<ll> mul(vector<ll> a, vector<ll> b) {
	// matrices are defined as
	// [0 1]
	// [2 3]
	return vector<ll>{
		(a[0]*b[0]+a[1]*b[2]) % MOD,
		(a[0]*b[1]+a[1]*b[3]) % MOD,
		(a[2]*b[0]+a[3]*b[2]) % MOD,
		(a[2]*b[1]+a[3]*b[3]) % MOD,
	};
}

int main() {
	ll n; cin >> n;

	vector<ll> base{1,0,1,0}, m{1, 1, 1, 0};

	for(; n > 0; n /= 2, m = mul(m, m)) {
		if(n & 1) base = mul(base, m);
	}

	cout << base[1];
}