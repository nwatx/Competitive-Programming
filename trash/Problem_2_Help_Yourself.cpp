#include <bits/stdc++.h>

using namespace std;

const int mx = (int)1e5+1;
const int MOD = (int)1e9+7;

int tot[2*mx];

void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
	setIn(s+".in"), setOut(s+".out"); // for old USACO
}

int main() {
	setIO("help");
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[a, b] : v) {
		cin >> a >> b;
		tot[a]++; tot[b]--;
	}

	for(int i = 1; i < 2*mx; i++) {
		tot[i] += tot[i-1];
	}

	vector<long long> p2(n + 1);
	p2[0] = 1;
	for(int i = 1; i <= n; i++) {
		p2[i] = (2 * p2[i-1]) % MOD;
	}

	long long ret = 0;

	for(auto [l, _] : v) {
		ret += p2[n - 1 - tot[l - 1]];
		ret %= MOD;
	}

	cout << ret;
}