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

int R[101];

int main() {
	setIO("cbarn");
	
	int n; cin >> n;

	// reads in # of cows in each room
	for(int i = 0; i < n; i++) {
		cin >> R[i];
	}

	// initialize to infinity
	int ret = INT_MAX;

	for(int i = 0; i < n; i++) {
		// rotate it by 1
		rotate(R, R + 1, R + n);

		int sum = 0; // total sum

		for(int j = 0; j < n; j++) {
			sum += j * R[j];
		}

		// check if we have a better answer
		ret = min(sum, ret);
	}

	// print out our answer
	cout << ret;
}