#include <bits/stdc++.h>

using namespace std;

struct Seg {
	int n;
	vector<int> S;
	void init(int _n) {
		n = _n;
		S.resize(2 * n, (int)1e9 + 7);
	}

	void upd(int i, int x) {
		S[i += n] = x;
		for(i /= 2; i; i /= 2) S[i] = min(S[2*i], S[2*i + 1]);
	}

	int qry(int l, int r) {
		int la = (int)1e9 + 7, ra = (int)1e9+7;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) la = min(la, S[l++]);
			if(r & 1) ra = min(ra, S[--r]);
		}
		return min(la, ra);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	Seg S; S.init(n + 1);
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		S.upd(i, x);
	}
	while(m--) {
		int a, b; cin >> a >> b;
		cout << S.qry(a, b) << '\n';
	}
}