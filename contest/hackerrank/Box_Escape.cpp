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

bool vis[1001][1001];

void solve() {
	// construct top
	int n; cin >> n;
	int y = 2, x = 0;
	int d = 4;
	rep(n) {
		rep(4) vis[x][y] = 1, y++;
		rep(d) vis[x][y] = 1, x++;
	}

	F0R(i, 12) {F0R(j, 12) cout << vis[i][j]; cout << nl;}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n = 1;
	// cin >> n;
	rep(n) solve();
}