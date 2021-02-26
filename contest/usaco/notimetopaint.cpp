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
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int MX = 1e5+1;

int N, Q;

string A;

void solve(vi &pfx) {
	stack<char> active;
	for(int i = 0; i < N; i++) {
		pfx[i+1] = pfx[i];
		while(sz(active) && active.top() > A[i]) active.pop();
		if(active.empty() || active.top() < A[i]) {
			active.push(A[i]);
			pfx[i+1]++;
		}
	}
}

int main() {
	setIO();

	cin >> N >> Q;
	cin >> A;

	vi pfxF(N+1);
	vi pfxR(N+1);

	solve(pfxF);
	reverse(all(A));
	solve(pfxR);

	while(Q--) {
		int a, b; cin >> a >> b;
		cout << pfxF[a-1] + pfxR[N-b] << "\n";
	}

}