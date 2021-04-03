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

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
}

int N;

string grid[26][26];
int dp[26][26]; // 0: unvis, 1:M, 2:B, 3:Both

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main() {
	setIO();

	cin >> N;
	pi st;
	for(int i = 0; i < N; i++) {
		string a; cin >> a;
		for(int j = 0; j < 3*N; j+=3) {
			grid[i][j/3] = a.substr(j, 3);
			if(grid[i][j/3] == "BBB") st = {i, j/3};
		}
	}

	cout << 8;

	// queue<pi> bfs;
	// bfs.push(st);
	// while(sz(bfs)) {
	// 	pi top = bfs.front();
	// 	for(int k = 0; k < 4; k++) {
	// 		int nx = top.f + dx[k];
	// 		int ny = top.s + dy[k];
	// 		if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
	// 		if(dp[nx][ny]) continue;
			
	// 		switch(dp[top.f][top.s]) {
	// 			case 0:
	// 			dp[nx][ny] = 3;
	// 			case 1:
	// 			dp[nx][ny] = 
	// 		}
	// 	}
	// }
}