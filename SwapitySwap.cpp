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

// goes through one iteration of the swaps
void step(vi &v, int a, int b, int c, int d) {
    reverse(v.begin() + a, v.begin() + b);
    reverse(v.begin() + c, v.begin() + d);
}

int main() {
	// input
	int n, k; cin >> n >> k;
	int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    a1--; b1--;
    vi v(n); iota(all(v), 1);
	// iota does [1, 2, 3, ..., n]
	// "vi" is analgous to ArrayList in Java
	// ret is the final answer
    vi ret = v;

    // find cycle length
    int l = 0;
    do {
        step(v, a1, a2, b1, b2); // swap
        l++; // add one to the cycle length
    } while(ret != v); // while the cycle is not complete

    k %= l; // then we only need to do k steps after modding

	// doing it k steps
	for(int i = 0; i < k; i++) { 
        step(ret, a1, a2, b1, b2);
    }

	// answer
	for(int x : ret) {
		cout << x << '\n';
	}
}