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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
    string a, b; cin >> a >> b;
    string s = b + "-" + a;

    // fill in with longest non trivial index
    vector<int> pi_s(s.size());

    for (int i = 1, j = 0; i < (int)s.size(); i++) {
        // while the two aren't equivalent, move to last equivalent index
        while(j > 0 && s[j] != s[i]) {
            j = pi_s[j - 1];
        }

        if(s[i] == s[j]) {
            ++j;
        }

        pi_s[i] = j;
    }

    int ret = 0;
    for(int i = (int)b.size(); i < (int)s.size(); i++) {
        ret += pi_s[i] == (int)b.size();
        // cerr << pi_s[i] << " ";
    }

    cout << ret;
}