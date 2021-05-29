#include <bits/stdc++.h> // see /general/running-code-locally
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
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		(void)!freopen((name+".in").c_str(), "r", stdin); // see /general/io
		(void)!freopen((name+".out").c_str(), "w", stdout);
	}
}

map<ll, ll> a;

int main() {
	setIO();
	
	int Q; cin >> Q;

	for(int i = 0; i < Q; i++) { // loop 1...Q
		int t; cin >> t; // type
		if(t == 0) { // type 0
			ll k, v; cin >> k >> v;
			a[k] = v;
		} else { // type 1
			ll k; cin >> k;
			cout << a[k] << "\n";
		}
	}
}