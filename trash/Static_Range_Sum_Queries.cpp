#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const int mx = (int)2e5+1;

ll pfx[mx];

void pfx_init(int n) {
	for(int i = 1; i <= n; i++) pfx[i] += pfx[i - 1];
}

ll qry(int l, int r) {
	return pfx[r] - pfx[l - 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> pfx[i];

	pfx_init(n);

	while(q--) {
		int l, r; cin >> l >> r;
		cout << qry(l, r) << '\n';
	}
}