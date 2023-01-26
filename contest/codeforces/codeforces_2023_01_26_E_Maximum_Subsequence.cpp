// [auto_folder]: cf
// ^ type folder name for scripted placement

#include <bits/stdc++.h>

using namespace std;

const int mx = 35;

set<long long> lhs, rhs;

int mod;

void gen(vector<int> &v, set<long long> &out) {
	for(int i = 0; i < (1 << (int)v.size()); i++) {
		long long s = 0;
		for(int j = 0; j < v.size(); j++) {
			if(i & (1 << j)) s = (s + v[j]) % mod;
		}
		out.insert(s);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n >> mod;
	vector<int> l, r;
	for(int i = 0; i < n / 2; i++) {
		int x; cin >> x; l.push_back(x);
	}

	for(int i = n / 2; i < n; i++) {
		int x; cin >> x; r.push_back(x);
	}

	gen(l, lhs); gen(r, rhs);
	lhs.insert(0); rhs.insert(0);

	long long ret = 0;

	for(long long a : lhs) {
		// find the "best" b
		// case 1: b doesn't cause an overflow
		auto it = rhs.lower_bound(mod - a); if(it != rhs.begin()) it--;
		ret = max(ret, (a + *it) % mod);

		// case 2: overflow
		ret = max(ret, (a + *rhs.rbegin()) % mod);
	}

	cout << ret;
}