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

void setIO() {
	cin.tie(0)->sync_with_stdio(0); 
}

const int mx = 70000;

int main() {
	setIO();


	int n, k; cin >> n >> k;

	vector<int> years(n);
	for(int i = 0; i < n; i++) cin >> years[i];

	years.pb(0);

	sort(all(years));	

	map<int, int> costs; // diff -> save

	for(int i = 1; i <= n; i++) {
		costs[years[i] - years[i-1]] = 12 - years[i] % 12;
	}

	int ret = *years.rbegin();
	while(ret % 12) ret++;

	vector<int> cmin;

	for(pi a : costs) {
		cmin.pb(a.f - a.s);
		// cerr << a.f - a.s << "\n";
	}

	sort(all(cmin));

	int c = 0;

	for(int i = sz(cmin)-1; i >= 0 && c < k-1; i--, c++) {
		ret -= cmin[i];
	}

	cout << ret;
}