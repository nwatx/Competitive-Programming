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

int A[101];
int dp[101][101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++) {
		if(A[i] != i) dp[i][0] = 1;
		for(int j=0;j<n;j++) {
			// breakout i + 1;
			// calculate expected contribution
		}
	}

	for(int i=0;i<n;i++){
		for(int j =0;j<n;j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}