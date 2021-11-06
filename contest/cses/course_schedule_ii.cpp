#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 1;

vector<int> adj[MAX_N];
int in[MAX_N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		in[a]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if(!in[i]) pq.push(i);
	}

	vector<int> result;

	// topographical sort
	while (pq.size()) {
		int x = pq.top();
		pq.pop();
		result.push_back(x);

		// for all edges
		for(const int &e : adj[x]) {
			if(!(--in[e])) pq.push(e);
		}
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}