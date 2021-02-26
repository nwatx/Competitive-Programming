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

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(all(v));

	int min = v[0];
	int ret = 0;
	for(int i = 1; i < sz(v); i++) {
		if(v[i] > min) ret++;
	}

	cout << ret << "\n";
}

int main() {
	setIO();

	int T; cin >> T;
	for(int i = 0; i < T; i++) solve();
}