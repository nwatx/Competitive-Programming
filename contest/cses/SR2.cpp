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
		(void)!freopen((name+".in").c_str(), "r", stdin); // see /general/io
		(void)!freopen((name+".out").c_str(), "w", stdout);
	}
}

//CodeSnip{CPP Short Template}

ll INF = 1e18;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<ll>> mat(n, vector<ll>(n, INF));

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w, u--, v--;
		if (w < mat[u][v]) mat[u][v] = mat[v][u] = w;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (mat[i][k] + mat[k][j] < mat[i][j])
				mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];

	while (q--) {
		int u, v;
		cin >> u >> v, u--, v--;
		if (u == v) mat[u][v] = 0;
		if (mat[u][v] == INF) mat[u][v] = -1;
		cout << mat[u][v] << "\n";
	}
}