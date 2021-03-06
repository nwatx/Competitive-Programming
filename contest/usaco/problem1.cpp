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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool vis[1001][1001];

int main() {
	setIO();

	int n; cin >> n;
	vector<pi> points(n);
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		points[i] = {a+1000, b+1000};
	}

	for(int i = 0; i < n; i++) {
		vis[points[i].f][points[i].s] = true;

		pi nv;
		int cnt = 0;

		unordered_set<pi> vis2;

		for(int j = 0; j < 4; j++) {
			int nx = points[i].f + dx[j];
			int ny = points[i].s + dy[j];
			if(vis[nx][ny]) cnt++;
			else nv = {nx, ny};
		}

		int ret = 0;
		queue<pi> bfs;
		bool tv = vis;
		if(cnt == 3) bfs.push(nv);
	}
}