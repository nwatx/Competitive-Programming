#include <bits/stdc++.h> // see C++ Tips & Tricks
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") { // name is nonempty for USACO file I/O
	cin.tie(0)->sync_with_stdio(0); // see Fast Input & Output
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

bool abcab(int a, int b, int c, int aplusb) { // n = 4
	return (a + b == aplusb || a + c == aplusb);
}

void solve() {
	int n; cin >> n;
	vi v(n); for(int i = 0; i < n; i++) cin >> v[i];
	sort(all(v));
	if(n == 4) {

	}
	if(n == 5) {

	}
	if(n == 6) {

	}
	if(n == 7) {

	}
}

int main() {
	setIO();
	int t; cin >> t;
	while(t--) solve();
}