#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mx = (int)2e5+1;
const int MOD  = (int)1e9+7;

ll p2[mx];
int tot[mx];

void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
	setIn(s+".in"), setOut(s+".out"); // for old USACO
}

int main() {
	setIO("help");
	int n; cin >> n;
	p2[0] = 1;
	for(int i = 1; i < n; i++) p2[i] = (2 * p2[i-1]) % MOD;

	vector<pair<int, int>> A(n);
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		A[i] = {a, b};
		tot[a]++; tot[b]--;
	}

	for(int i = 1; i < mx; i++) tot[i] += tot[i-1];

	ll ret = 0;

	for(auto [l, r] : A) {
		ret += p2[n - 1 - tot[l - 1]];
		ret %= MOD;
	}

	cout << ret << endl;
}