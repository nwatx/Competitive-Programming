#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using vi = vector<int>;
#define pb push_back

const int mx = 1e5+1;

vi adj[mx], adj_t[mx], S;
bool vis[mx];
int id[mx];
 
void dfs(int x, int pass, int num = 0) {
	vis[x] = true;
	vi &ad = (pass == 1) ? adj[x] : adj_t[x];
	for(const int &e : ad) {
		if(!vis[e]) dfs(e, pass, num);
	}

	S.pb(x);
	if(pass == 2) id[x] = num;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
 
	while(m--) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj_t[b].pb(a);
	}
 
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) dfs(i, 1);
	}
 
	memset(vis, false, sizeof vis);
 
	int components = 0;
 
	for(int i = n - 1; i >= 0; i--) {
		if(!vis[S[i]]) {
			components++;
			dfs(S[i], 2, components);
		}
	}

	cout << components << "\n";
 
	for(int i = 1; i <= n; i++)
		cout << id[i] << " ";
}