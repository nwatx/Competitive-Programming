#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> S;

const int INF = (int)1e9+7;

void upd(int i, int x) {
	for(S[i += n] = x, i /= 2; i; i /= 2) {
		S[i] = min(S[2 * i], S[2 * i + 1]);
	}
}

int qry(int l, int r) {
	int la = INF, rb = INF;
	for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
		if(l & 1) la = min(la, S[l++]);
		if(r & 1) rb = min(rb, S[--r]);
	}
	return min(la, rb);
}

int main() {
	cout << (5 & 3 << 1 ^ 2) << '\n';
	// cin.tie(0)->sync_with_stdio(0);
	// cin >> n >> m;

	// S.resize(2 * n, INF);

	// for(int i = 0; i < n; i++) {
	// 	int x; cin >> x;
	// 	upd(i, x);
	// }

	// while(m--) {
	// 	int t, a, b; cin >> t >> a >> b;
	// 	if(t == 1) {
	// 		a--;
	// 		upd(a, b);
	// 	} else {
	// 		a--; b--;
	// 		cout << qry(a, b) << '\n';
	// 	}
	// }
}