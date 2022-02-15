#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

#define F0R(i,a) for (int i = 0; i < a; ++i)
 
int main() {
	vector<ll> po3{1};
	for (int i = 1; i < 40; ++i) 
		po3.push_back(3*po3.back());
	array<array<array<ll,2>,2>,3> dp, DP;
	int Q; cin >> Q;
	while (Q--) {
		ll d,x,y; cin >> d >> x >> y;
		dp = {}; dp[1][0][0] = 1;
		F0R(i,39) {
			DP = {};
			int dd = d/po3[i]%3, xd = x/po3[i]%3, yd = y/po3[i]%3;
			F0R(cmp,3) F0R(xc,2) F0R(yc,2) F0R(j,3) {
				int XD = (xd+xc+j)%3, XC = (xd+xc+j)/3;
				int YD = (yd+yc+j)%3, YC = (yd+yc+j)/3;
				int CMP = cmp;
				if (j > dd) CMP = 2;
				if (j < dd) CMP = 0;
				if (XD%2 == YD%2)
					DP[CMP][XC][YC] += dp[cmp][xc][yc];
			}
			swap(dp,DP);
		}
		cout << dp[0][0][0]+dp[1][0][0] << "\n";
	}
}