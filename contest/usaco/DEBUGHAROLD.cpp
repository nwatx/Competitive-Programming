#include <bits/stdc++.h>

using namespace std;


#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

typedef long long ll;

int N, K, mx=0, mn=1000000007;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    set<int> s;
    F0R(i, N){
        int y; cin>>y;
        mx = max(mx, y); mn = min(mn, y);
        s.insert(y/12);
    }

    if(K == 1){
        cout << (ceil((double)mx/12)) * 12;
    }
    else if(K == 2){
        cout << (ceil((double)mx/12)*12) - (floor((double)mn/12)*12);
    }
    else{
        int prev = -1;
        vector<int> gap;

        trav(x, s){
            if((prev == -1) || (prev == (x-1))){
            }
            else{
                gap.push_back(x - prev-1);
            }
            prev = x;
        }

        sort(gap.begin(), gap.end());

        // cout << s.size() << endl;
        // trav(x, gap){
        //     cout << x << " ";
        // }

        int res = s.size()*12;

        F0R(i, gap.size()+2-K){
            res += gap[i]*12;
        }

        cout << res;
    }
}