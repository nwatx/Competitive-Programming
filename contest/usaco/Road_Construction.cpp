#include <bits/stdc++.h>

using namespace std;

vector<int> e;

int get(int x) {
	return e[x] < 0 ? x : e[x] = get(e[x]);
}

bool unite(int a, int b) {
	a = get(a), b = get(b);
	if(a == b) return false;
	if(e[a] > e[b]) swap(e[a], e[b]);
	e[a] += e[b]; e[b] = a;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	e.resize(n, -1);

	int comps = n;
	int lg = 1;
	while(m--) {
		int a, b; cin >> a >> b;
		a--; b--;

		if(unite(a, b)) {
			comps--;
			lg = max(lg, -e[get(a)]);
		}

		cout << comps << " " << lg << '\n';
	}
}