#include <bits/stdc++.h>

using namespace std;

int get(vector<int> &D, int x) {
	return D[x] < 0 ? x : D[x] = get(D, D[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;

	vector<int> D(n, -1);
	while(m--) {
		int t, a, b; cin >> t >> a >> b;
		if(t == 0) {
			int x = get(D, a), y = get(D, b);
			if(x == y) continue;
			if(D[x] > D[y]) swap(D[x], D[y]);
			D[x] += D[y]; D[y] = x;
		} else {
			cout << (get(D, a) == get(D, b)) << '\n';
		}
	}
}