#include <bits/stdc++.h>
using namespace std;

const int N = 20;
char mat[21][21];
long long dist[21][21];

const long long MOD = 1e9 + 7;

#define bp(x, y) if(x >= 0 && x < N && y >= 0 && y < N) if(dist[x][y] == MOD) { bfs.push({x, y}); dist[x][y] = dist[p.first][p.second] + 1; }

int main() {
	pair<int, int> start;

	// code here + read in
	
	queue<pair<int, int>> bfs;
    bfs.push(start);
    dist[start.first][start.second] = 0;
    while(bfs.size()) {
        pair<int, int> p = bfs.front(); bfs.pop();
        int x = p.first, y = p.second;
        
        bp(x - 1, y); bp(x + 1, y); bp(x, y - 1); bp(x, y + 1);
    }

	

    return 0;
}
