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
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int n, k;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vi A[10];
bool vis[101][10];

int t = 0;
vector<pi> mark;

void ff(int x, int y, int type) {
	if(vis[x][y]) return;
	vis[x][y] = true;
	if(A[x][y] != type) return;
	if(A[x][y] == type) { ++t; mark.pb({x, y}); }
	for(int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= 10 || ny >= sz(A[nx])) continue;
		if(!vis[nx][ny]) ff(nx, ny, type);
	}
}

bool step() {
	bool ffd = false;
	memset(vis, false, sizeof vis);

	// for(int i = 0; i < 10; i++) {
	// 	for(int j = 0; j < sz(A[i]); j++) cerr << A[i][j];
	// 	cerr << "\n";
	// }

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < sz(A[i]); j++) {
			if(!vis[i][j]) {
				t = 0;
				mark = vector<pi>();
				if(A[i][j]) ff(i, j, A[i][j]);
				if(t < k) continue;
				else {
					ffd = true;
				}
				for(const pi mk : mark) {
					// cerr << "mk: " << mk.f << " " << mk.s << " " << A[mk.f][mk.s] << "\n";
					A[mk.f][mk.s] = 0;
				}
			}
		}
	}

	for(int j = 0; j < 10; j++) {
		for(int i = 0; i < sz(A[j]);) {
			// cerr << "erasing " << i << " " << j << '\n';
			if(A[j][i] == 0) A[j].erase(A[j].begin() + i);
			else i++;
		}
	}

	// for(int i = 0; i < 10; i++) {
	// 	for(int j = 0; j < sz(A[i]); j++) cerr << A[i][j];
	// 	cerr << "\n";
	// }


	return ffd;
}

int main() {
	setIO("mooyomooyo");

	cin >> n >> k;

	for(int i = 0; i < 10; i++) A[i] = vi(n, 0);

	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < 10 ;j++) {
			char a; cin >> a;
			a -= '0';

			A[j][i] = a;
		}
	}

	while(step());

	for(int i = 0; i < 10; i++) {
		while(sz(A[i]) < n) A[i].push_back(0);
	}

	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < 10; j++) cout << A[j][i];
		cout << "\n";
	}
}