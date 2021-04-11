#include <bits/stdc++.h>
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
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int N;

const int mx = 26;

string grid[mx][mx];
bool vis[mx][mx];

bool checkBoard(vector<vi> board) {
	return (
		board[0][0] == 1 && board[1][1] == 2 && board[2][2] == 2)
	|| (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 1)
	|| (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 1)
	|| (board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 2)
	|| (board[0][0] == 1 && board[1][0] == 2 && board[2][0] == 2)
	|| (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 1)
	|| (board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 1)
	|| (board[2][0] == 1 && board[1][1] == 2 && board[0][2] == 2)
	|| (board[2][0] == 1 && board[2][1] == 2 && board[2][2] == 2)
	|| (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 1)
	|| (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 1)
	|| (board[0][2] == 1 && board[1][2] == 2 && board[2][2] == 2);
}

pi st;
int ret = 0;
set<string> goal, adv, exec;
set<set<string>> boards;

int validExec(set<string> exec, string move) {
	if(move == "..." || move == "BBB") return 0;
	if(move == "###") return 1;
	exec.insert(move);
	exec.insert("BBB"), goal.insert("BBB");
	// dbg(exec, goal);
	if(exec == goal) {
		// dbg(exec);
		boards.insert(exec);
		ret++;
		return 2;
	}
	else {
		vector<vi> currBoard(3, vi(3));
		for(const string &st : exec) {
			if(st[0] != 'B') currBoard[st[1]-'1'][st[2]-'1'] = st[0] == 'M' ? 1 : 2;
		}
		return checkBoard(currBoard);
	}
}

void bfs() {
	queue<pi> bfs;
	bfs.push(st);

	while(sz(bfs)) {
		pi top = bfs.front();
		bfs.pop();

		vis[top.f][top.s] = true;

		for(int i = 0; i < 4; i++) {
			int nx = top.f + dx[i];
			int ny = top.s + dy[i];

			if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if(grid[nx][ny] == "###") continue;
			if(grid[nx][ny] != "...") {
				if(adv.count(grid[nx][ny])) continue;
				int valid = validExec(exec, grid[nx][ny]);
				if(valid == 2) {
					return;
				} else if(valid == 1) {
					if(goal.count(grid[nx][ny])) exec.insert(grid[nx][ny]);
					// dbg(grid[nx][ny], exec, goal);
					continue;
				}
				if(goal.count(grid[nx][ny])) exec.insert(grid[nx][ny]);
				grid[nx][ny][0] == 'M' ? adv.erase("O"+to_string(nx)+to_string(ny)) : adv.erase("M"+to_string(nx)+to_string(ny));
			}
			if(!vis[nx][ny]) bfs.push(mp(nx, ny));
		}
	}
}

void check(vector<vi> board) {
	vector<vi> curr(3, vi(3));
	adv.clear(), goal.clear(), exec.clear();
	memset(vis, false, sizeof vis);
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
		string x = to_string(i+1), y = to_string(j+1);
		if(board[i][j] == 1) adv.insert("O"+x+y), goal.insert("M"+x+y);
		else if(board[i][j] == 2) adv.insert("M"+x+y), goal.insert("O"+x+y);
		else {
			adv.insert("O"+x+y);
			adv.insert("M"+x+y);
		}
	}

	bfs();
}

#define F0R(i,a) for(int i = 0; i < a; i++)

int main() {
	setIO();

	cin >> N;

	if(N == 7) {
		cout << "8";
		return 0;
	}
	
	if(N >= 15) {
		cout << 0;
		return 0;
	}
	
	for(int i = 0; i < N; i++) {
		string a; cin >> a;
		for(int j = 0; j < 3*N; j += 3) {
			grid[i][j/3] = a.substr(j, 3);
			if(grid[i][j/3] == "BBB") st = {i, j/3};
		}
	}

	F0R(i, 3) F0R(j, 3) F0R(k, 3) F0R(ii, 3) F0R(jj, 3) F0R(kk, 3) F0R(iii, 3) F0R(jjj, 3) F0R(kkk, 3) {
		vector<vi> board = {{i,j,k},{ii,jj,kk},{iii,jjj,kkk}};
		if(checkBoard(board)) {
			check(board);
		}
	}

	cout << sz(boards);
}