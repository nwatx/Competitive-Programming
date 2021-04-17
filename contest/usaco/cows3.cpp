#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

int N, K, L;

const int mx = 1e5+1;
int A[mx];

struct FT {
    vector<int> bit;  // binary indexed tree
    int n;

    FT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

	void update(int idx, int val) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += val;
	}

	void range_add(int l, int r, int val) {
		update(l, val);
		update(r + 1, -val);
	}

	int pQ(int idx) {
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
};

bool valid(int h) {
	int cnt = 0;
	vi v(N);
	for(int i = 0; i < N; i++) v[i] = h-A[i];
	sort(all(v));
	
	int k = K;

	FT ft(N+1);
	for(int i = 0; i < N; i++) ft.update(i+1, v[i]), ft.update(i+2, -v[i]);
	// for(int i = 0; i <= N; i++) cerr << ft.pQ(i) << "|\n";
	int j = 1;
	for(int i = 1; i < N;) {
		while(ft.pQ(i) <= 0 && i < sz(v)) {
			i++; cnt++;
		}
		if(L == 0) break;
		while(j < (i + L - 1) && j < sz(v)) j++;
		// cerr << "i,j: " << i << ":" << j << "\n";
		if(k <= 0) break;
		int upd = min(K, ft.pQ(i));
		ft.update(i, -upd); ft.update(j+1, upd);
		k -= upd;
		// cerr << "---\n";
		// for(int i = 1; i <= N; i++) cerr << ft.pQ(i) << "|\n";
	}

	// cerr << cnt << "\n";

	return cnt >= h;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	cin >> N >> K >> L;
	for(int i = 0; i < N; i++) cin >> A[i];

	// cout << valid(4) << "\n";

	// int ret = 0;
	// while(l < r) {}

	if(K == 0 || L == 0) {
		int minn = 0;
		for(int i = 0; i < N; i++) minn = min(minn, A[i]);
		cout << minn;
	} else {
	int l = 0, r = mx;
	while(l < r) {
		int mid = l + (r - l + 1) / 2;
		valid(mid) ? l = mid : r = mid -1;
	}

	cout << l << "\n";

	}

}
