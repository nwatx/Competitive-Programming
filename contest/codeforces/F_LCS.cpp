#include <bits/stdc++.h>

using namespace std;

template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; 
}

int dp[3001][3001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	
	for(int i = 0 ; i <= n; i++) {
		for(int j = 0; j <= m; j++)  {
			if(!i || !j) dp[i][j] = 0;
			else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
		}
	}

	string ret = "";

	while(n && m) {
		if(s[n - 1] == t[m - 1]) {
			ret += s[n - 1];
			n--;
			m--;
		}
		else if(dp[n - 1][m] > dp[n][m - 1]) n--;
		else m--;
   }

   reverse(ret.begin(), ret.end());

   cout << ret << endl;
}