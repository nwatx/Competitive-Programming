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

string to_string(__int128 x) {
    string s;
    if(x == 0) s = "0";
    while(x > 0) {
        // std::cout << "here\n";
        char d = (char)((x % 10) + '0');
        // cerr << d << " ";
        s += d;
        x /= 10;
    }

    reverse(s.begin(), s.end());
    return s;
}

void print(__int128 x) {
    cout << to_string(x) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    long long b, n; cin >> b >> n;
    string s = to_string(n);

    __int128_t l = 0, r = 1;
    r <<= 63;

    // print(l);
    // print(r);

    while (l <= r) {
        __int128_t mid = (l + r) / 2;
        print(mid);

        // convert mid to base 10
        __int128_t midb10 = 0;
        string ms = to_string(mid);
        __int128_t p10 = 1;
        
        for(int i = 0; i < ms.size(); i++) {
            midb10 += (ms[i] - '0') * p10;
            p10 *= 10;
        }

        print(midb10);

        if(midb10 == n) {
            // cout << mid << "\n";
            // print(mid);
            return 0;
        } else if(midb10 > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "impossible\n";
}