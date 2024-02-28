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
    
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0;i <n;i++) cin>>v[i];
    int cnt = 0;

    multiset<int> cont;

    for(int i = n-1;~i;--i) {
        if(!cont.size()) {
            cont.insert(v[i]);
        } else {
            if(cont.count(v[i] - 1)) {
                cont.erase(cont.find(v[i] - 1));
            }

            cont.insert(v[i]);
        }
    }

    cout << cont.size();


    // map<int, vector<int>> idx;
    // multiset<int> hrm;
    // for(int x : v) hrm.insert(x);
    // for(int i = 0;i  < n;i++) {
    //     idx[v[i]].push_back(i);
    // }
    // // int cnt = 0;
    // while(hrm.size()) {
    //     ++cnt;
    //     int back = *hrm.rbegin();
    //     cout << "back: " << back << "\n";
    //     idx[back].pop_back();
    //     hrm.erase(hrm.find(back));
    //     for(int i = back - 1; ~i; --i) {
    //         if(!idx[i].size()) break;
    //         idx[i].pop_back();
    //         hrm.erase(hrm.find(i));
    //     }
    // }

    // cout << cnt;
    // // for(int i=0;i<n;) {
    //     ++cnt;
    //     int j = i;
    //     int h = v[i];
    //     while(j < n && v[j] == h) {
    //         ++j;
    //         --h;
    //     }

    //     i = j;
    // }

    // cout << cnt;
}