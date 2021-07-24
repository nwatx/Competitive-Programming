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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, k; cin >> n >> m >> k;
	vector<vi> v(n, vi(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0 ;j  < m; j++) cin >> v[i][j];
	}

	vi rs;

	for(int i = 0 ;i  < n; i ++) {
		for(int j = 0; j < n; j++) {
			int cR = 0;
			while(j < n && v[i][j]) {
				cR++;
				j++;
			}
			if(cR) rs.pb(cR);
		}
	}

	// for(int i = 0; i < sz(rs); i++) {
	// 	cout << rs[i] << "\n";
	// }

	sort(all(rs));
	reverse(all(rs));


	ll ret = 0;
	
	for(int i = 0; i < k && i < sz(rs); i++) {
		ret += rs[i];
	}

	cout << ret << "\n";
}