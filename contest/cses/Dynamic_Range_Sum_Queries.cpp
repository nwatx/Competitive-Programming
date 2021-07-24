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

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

ll blocks[450]; // 450^2 > 2e5
int nums[(int)(2e5 + 1)];
int block_sz;

void upd(int x, int v) { // O(1) update
	blocks[x / block_sz] -= nums[x];
	nums[x] = v;
	blocks[x / block_sz] += nums[x];
}

ll query(int r) {
	ll ret = 0;
	for(int i = 0; i < r / block_sz; i++) ret += blocks[i];
	for(int i = r / block_sz * block_sz; i < r; i++) ret += nums[i];
	return ret;
}

ll query(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
	setIO();

	int n, q; cin >> n >> q;
	block_sz = (int) sqrt(n);

	for(int i = 0; i < n; ++i) cin >> nums[i];
	for(int i = 0; i < n; ++i) blocks[i / block_sz] += nums[i];
	for(int i = 0; i < q; ++i) {
		int t, l, r; cin >> t >> l >> r;
		if (t == 1) upd(l - 1, r);
		else cout << query(l, r) << "\n";
	}
}