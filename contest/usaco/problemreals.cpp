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

vector<vi> deg(2001, vi(2001));

int ret = 0;

void ff(int x, int y, vector<vi> deg) {
	int cc = 0;
	pi uvis;

	deg[x][y+1]++;
	deg[x][y-1]++;
	deg[x-1][y]++;
	deg[x+1][y]++;

	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(deg[nx][ny]) {
			cc++;
		} else {
			uvis = {nx, ny};
		}
	}

	if(cc == 3) {
		ff(uvis.f, uvis.s, deg);
	}
}

int main() {
	setIO();

	int n; cin >> n;
	vector<pi> points(n);
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		a += 1000; b+=1000;


		points[i] = {a, b};
	}

	for(int i = 0; i < n; i++) {
		int a = points[i].f, b = points[i].s;
		ret = 0;
		ff(a, b, deg);
		cout << ret << "\n";
	}

}