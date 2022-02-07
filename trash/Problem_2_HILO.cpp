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

const int mx = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;

int A[mx];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i =0;i<n;i++)cin>>A[i];
	for(double i = 0.5; i <= n + 0.5; i = i + 1) {
		int lsthi = 0;
		int ret = 0;
		int l = 0, r = MOD;
		for(int j = 0; j < n; j++) {
			int guess = A[j];
			if(guess < l || guess > r) continue;
			if(guess >= i) lsthi = 1;
			else if(lsthi && guess < i) ret++;
			if(guess < i) lsthi = 0;

			if(guess > i) r = guess;
			if(guess < i) l = guess;
		}
		cout << ret << '\n';
	}
}