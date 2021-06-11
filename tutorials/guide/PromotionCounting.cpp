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

int main() {
	setIO("promote");
	
	int bronzeBefore, bronzeAfter;
	cin >> bronzeBefore >> bronzeAfter;

	int silverBefore, silverAfter;
	cin >> silverBefore >> silverAfter;

	int goldBefore, goldAfter;
	cin >> goldBefore >> goldAfter;

	int platBefore, platAfter;
	cin >> platBefore >> platAfter;

	int goldToPlatinum = platAfter - platBefore;
	int silverToGold = platAfter + goldAfter - platBefore - goldBefore;
	int bronzeToSilver = silverAfter + goldAfter + platAfter - silverBefore - goldBefore - platBefore;

	cout << bronzeToSilver << "\n" << silverToGold << "\n" << goldToPlatinum << "\n";
}