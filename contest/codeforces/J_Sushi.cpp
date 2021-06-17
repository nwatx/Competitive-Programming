#include <bits/stdc++.h>

using namespace std;

int n;

long double dp[301][301][301];
// let dp[i][j][k] be
// i dishes of 1 sushi
// j dishes of 2 sushi
// k dishes of 3 sushi

double memo(int x, int y, int z) {
	if(x < 0 || y < 0 || z < 0) return 0;
	if(x == 0 && y == 0 && z == 0) return 0;
	// if(x + y + z < 1) return 0;
	if(dp[x][y][z] > 0) return dp[x][y][z];

	long double ret = n + x * memo(x - 1, y, z)  // # 1 sushi
					+ y * memo(x + 1, y - 1, z)  // # 2 sushi
					+ z * memo(x, y + 1, z - 1); // # 3 sushi

	return dp[x][y][z] = ret / (x + y + z);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> freq(3);
	for(int x : a) freq[x-1]++; 

	memset(dp, -1, sizeof dp);

	cout << fixed << setprecision(10) << memo(freq[0], freq[1], freq[2]) << endl;
}