#include <bits/stdc++.h>

using namespace std;

map<int, int> xf, yf, sf;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		xf[a]++;
		yf[a]++;
		sf[a + b]++;
	}

	int mx = 0;

	for(auto a : xf) {
		mx = max(a.second, mx);
	}

	for(auto a : yf) {
		mx = max(a.second, mx);
	}

	for(auto a : sf) {
		mx = max(a.second, mx);
	}

	cout << mx << endl;
}