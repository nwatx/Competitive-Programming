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

const ll MOD = 1e9+7;
const db PI = acos((db)-1);
const char nl = '\n';

ll n, m;
ll A[(int)1e5+1];

bool good(ll c) {
	if(c > n) return false;
	ll sum = 0;
	F0R(i, c) {
		sum += A[i];
	}
	FOR(i, c, n) {
		if(sum <= m) return true;
		sum += A[i];
		sum -= A[i - c];
	}
	if(sum <= m) return true;
	return false;
}

void solve() {
	cin >> n >> m;
	F0R(i, n) cin >> A[i];
	ll lo = 0, hi = n + 1;
	lo--; assert(lo <= hi);
	while (lo < hi) {
		ll mid = lo+(hi-lo+1)/2;
		good(mid) ? lo = mid : hi = mid-1;
	} 
	cout << lo << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n = 1;
	cin >> n;
	rep(n) solve();
}
