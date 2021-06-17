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

int in_deg[101], out_deg[101];

int main() {
	setIO("factory");
	
	int N; cin >> N;

	for(int i = 0; i < N - 1; i++) {
		// a -> b
		// out[a]++, in[b]++;
		int a, b; cin >> a >> b;
		out_deg[a]++;
		in_deg[b]++;
	}

	bool encountered_sink = false;
	int idx_sink = -1;

	for(int i = 1; i <= N; i++) {
		if(encountered_sink && out_deg[i] == 0 && in_deg[i] > 0) {
			idx_sink = -1; // answer
			break;
		}
		if(out_deg[i] == 0 && in_deg[i] > 0) {
			encountered_sink = true;
			idx_sink = i;
		}
	}

	cout << idx_sink << endl;
}