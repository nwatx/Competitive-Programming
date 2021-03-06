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

int main() {
	setIO();

	int n, k; cin >> n >> k;

	vector<int> years(n);

	int start = 0;

	for(int i = 0; i < n; i++) {
		cin >> years[i];
		start = max(start, years[i]);
	}

	years.push_back(0);

	if(start % 12) {
		while(start % 12) start++;
		years.push_back(start);
		k--;
	}

	sort(all(years));

	vector<int> cost;

	for(int i = 1; i < sz(years); i++) {
		// gap = portal under years[i-1] - above years[i]
		int tA = years[i], tB = years[i-1];
		while(tA % 12) tA--;
		while(tB % 12) tB++;
		cost.pb(tA - tB);
	}

	sort(all(cost));
	reverse(all(cost));

	// cerr << "costs: \n";
	// for(int i = 0; i < sz(cost); i++) cerr << cost[i]<< "\n";

	int j = 0;

	while(k--) {
		start -= max(0, cost[j++]);
	}

	cout << start;
}