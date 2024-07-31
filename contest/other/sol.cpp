#include <bits/stdc++.h>

using namespace std;

const int mx = 25;

int mat[2 * mx][2 * mx];

bool in(int x1, int y1, int x2, int y2, int r) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	return (dx * dx + dy * dy) <= r * r;
}

bool in(int x, int y, int r) {
	return (x * x + y * y) <= r * r;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, R; cin >> n >> R;
	assert(n <= 100);

	for(int i = 0; i < n; i++) {
		int r, x, y; cin >> r >> x >> y;
		assert(abs(x) < mx);
		x += mx; y += mx;

		for(int j = 0; j < 2 * mx; j++) {
			for(int k = 0; k < 2 * mx; k++) {
				if(in(j, k, x, y, r) && in(j, k, mx, mx, R)) {
					mat[j][k]++;
				}
			}
		}
	}

	int cnt = 0;

	for(int i = 0; i < 2 * mx; i++) {
		for(int j = 0; j < 2 * mx; j++) {
			cnt += mat[i][j] > 0;
			cerr << mat[i][j] << " ";
		}
		cerr << "\n";
	}

	cout << cnt << endl;
}