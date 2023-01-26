// [auto_folder]: 
// ^ type folder name for scripted placement

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

const int mx = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k; cin >> n >> k;
	vi v(n); for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int ret = 0;
	for(int i = 0; i < k; i++) ret += v[i];
	cout << ret;
}