#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double;

using pi = pair<int,int>;
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
using vi = V<int>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const ll MOD = 1e9+7;
const db PI = acos((db)-1);
const char nl = '\n';

bool P[501][501];
bool vis[501][501];

int n, m;
bool bounds(int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= m);
}

#define bT(x, y) if(bounds(x, y) && P[x][y] && !vis[x][y]) bfs.push({x,y});

void solve() {
    F0R(i,501) F0R(j, 501) P[i][j] = 0, vis[i][j] = 0;
    cin >> n >> m;
    cerr << n << " " << m << '\n';
    F0R(i, n) {
        int x; cin >> x;
        rep(x) {
            int a, b; cin >> a >> b;
            assert(a <= 500 && b <= 500);
            a--;
            FOR(j, a, b) P[i][j] = true;
        }
    }

    queue<pi> bfs;
    F0R(i, n) if(P[i][0]) bfs.push({i, 0});

    while(sz(bfs)) {
        pi top = bfs.front(); bfs.pop();
        if(vis[top.f][top.s]) continue;
        vis[top.f][top.s] = true;
        int x = top.f, y = top.s;
        bT(x+1, y);
        bT(x-1, y);
        // bT(x, y-1);
        bT(x, y+1);
    }

    // F0R(i, n) {F0R(j, m) {
    //     cerr << vis[i][j];

    // }cerr<<nl;}

    bool good = false;
    F0R(i, n) if(vis[i][m - 1]) {
        good = true;
        break;}
    if(good) cout << "YES\n";
    else cout << "NO\n";

    F0R(i, n) {F0R(j, n) {
        cout<<(vis[i][j]);
    }cout << nl;}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("test.out", "w", stdout);
    int n = 1;
    cin >> n;
    assert(n <= 500);
    rep(n) solve();
}