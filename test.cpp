#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<bool> vis(n+1);
	for(int i = 0; i < n-1; i++) {
		int a; cin >> a;
		vis[a] = true;
	}

	for(int i = n; i >= 0; i--) {
		if(!vis[i]) {
			cout << i; break;
		}
	}
}
