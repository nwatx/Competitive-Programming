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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

int A[(int)1e5+1];

int main() {
	setIO("sleepy");
	int N; cin >> N;

	Tree<int> r;

	for(int i = 0; i < N; i++) cin >> A[i];

	int steps = N - 1;
	for(int i = N - 1; i >= 0; i--) {
		if(i && A[i] < A[i-1]) {
			steps = i;
			break;
		}
	}

	for(int i = N - 1; i >= steps; i--) r.insert(A[i]);
	
	cout << steps << endl;

	for(int i = 0; i < steps; i++) {
		cout << steps - i - 1 + r.ook(A[i]);
		r.insert(A[i]);
		if(i != steps - 1) cout << " ";
	}
}