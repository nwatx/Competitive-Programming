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

int n;

const int mx = 501;

int lf[mx][mx]; // type 0
int of[mx][mx]; // type 1

bool valid(int x1, int y1, int x2, int y2) {
	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);

	ll zeroC = lf[x2][y2] - lf[x1-1][y2] - lf[x2][y1-1] + lf[x1-1][y1-1];
	ll hunC  = of[x2][y2] - of[x1-1][y2] - of[x2][y1-1] + of[x1-1][y1-1];

	return zeroC == 0 && hunC >= 1;
}

int main() {
	setIO();

	int n; cin >> n;

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
		int a; cin >> a;
		if(a < 100) lf[i][j]++;
		if(a == 100) of[i][j]++;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i) {
				lf[i][j] += lf[i-1][j];
				of[i][j] += of[i-1][j];
			} 

			if(j) {
				lf[i][j] += lf[i][j-1];
				of[i][j] += of[i][j-1];
			}

			if(i && j) {
				lf[i][j] -= lf[i-1][j-1];
				of[i][j] -= of[i-1][j-1];
			}
		}
	}

	ll ret = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int ii = i; ii < n; ii++) {
				for(int jj = j; jj < n; jj++) {
					if(valid(i, j, ii, jj)) {
						ret++;
						// cerr << i << " " <<  j << " " << ii << " " << jj << "\n";
					}
				}
			}
		}
	}

	cout << ret << endl;
}