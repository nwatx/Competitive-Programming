// [auto_folder]: 
// ^ type folder name for scripted placement

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

const int mx = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;

// need frequencies of columns to be the same
// everything past that is sortable

// get to sorted order:
// let's define sorted order to be blues in the front as much as possible
// and then as many blues as possible
int n, m;

vector<vector<bool>> colsort(vector<vector<bool>> v) {
    vector<vector<bool>> cols;
    for(int j = 0; j < m; j++) {
        vector<bool> col;
        for(int i = 0; i < n; i++) {
            col.push_back(v[i][j]);
        }

        cols.push_back(col);
    }

    sort(cols.begin(), cols.end());

    vector<vector<bool>> rows(n, vector<bool>(m));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            rows[j][i] = cols[i][j];
        }
    }

    return rows;

}

vector<vector<bool>> convert(vector<vector<bool>> v) {
    v = colsort(v);

    // sort the columns
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(bool b : v[i]) cnt += b;
        int red = cnt, blue = n - cnt;
        if(blue < red) {
            for(int j = 0; j < m; j++) v[i][j] = !v[i][j];
        }
    }

    return colsort(v);
}

void solve() {
    cin >> n >> m;
    vector<vector<bool>> red(n, vector<bool>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        string s; cin >> s;
        red[i][j] = s == "BLUE";
    }

    vector<vector<bool>> dest(n, vector<bool>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        string s; cin >> s;
        dest[i][j] = s == "BLUE";
    }

    auto a = convert(red), b = convert(dest);

    // for(int i=0;i<m;i++) {
    //     for(int j=0;j<n;j++){
    //         cerr << a[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    // for(int i=0;i<m;i++) {
    //     for(int j=0;j<n;j++){
    //         cerr << b[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }
    // multiset<vector<bool>> dest;
    // for(int i=0;i<n;i++){
    //     vector<bool> row(m);
    //     for(int j=0;j<m;j++){
    //         string s; cin >> s;
    //         row[j] = s == "BLUE";
    //     }
    //     dest.insert(row);
    // }

    // // go through
    // for(int i=0;i<n;i++) {
    //     // find matching row
    //     vector<bool> c1 = red[i];
    //     vector<bool> c2 = red[i];
    //     for(int j=0;j<n; ++j) c2[i] = !c2[i];

    //     if(dest.count(c1)) dest.erase(dest.find(c1));
    //     else if(dest.count(c2)) dest.erase(dest.find(c2));
    // }

    // cout << "dest_size: " << dest.size() << "\n";

    if(a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();
}