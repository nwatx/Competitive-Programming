#include <bits/stdc++.h>

using namespace std;

int n, m, x, y; 
vector<int> adj[SZ];
 
pair<int,int> bfs(int src)
{
	int d = 0;
	queue<pair<int,int> > q;
	q.push({src, 0});
	vector<bool> vis(SZ, false);
	pair<int,int>  u;
 
	while(!q.empty()) {
		u = q.front();
		vis[u.first] = true;
		q.pop();
		for(int v: adj[u.first])
			if(!vis[v])
			q.push({v, u.second + 1});
	}
	return u;
}
 
int main() {
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pair<int,int>  end1 = bfs(1);
	pair<int,int>  end2 = bfs(end1.first);
	cout << end2.second << endl;
}