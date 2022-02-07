#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lc (node<<1)+1
#define rc (node<<1)+2
#define INF 1e18

const int max_n = 100;
int dp[max_n];
bool choice[max_n];

int t; ll n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i < max_n; i ++){
        if(i % 2 == 0){
            if(dp[i-2] + 1 > (i / 2) + (i / 2 - dp[i / 2])){
                dp[i] = dp[i-2] + 1;
                choice[i] = 0;
            }
            else{
                dp[i] = (i / 2) + (i / 2 - dp[i / 2]);
                choice[i] = 1;
            }
        }
        else{
            dp[i] = 1 + (i-1 - dp[i-1]);
            choice[i] = 0;
        }
    }

    for(int i = 4; i < 50; i ++){
        cout << i << ":  ";
        if(choice[i]) cout << "take half" << endl;
        else cout << "take 1" << endl;
    }

    cin >> t;
    while(t --){
        cin >> n;

        ll ans = 0;
        int turn = 0;

        while(n > 10){

            if(turn == 0){
                if((n - 10) % 4 == 0){
                    n = n/2;
                    ans += n;
                }
                else{
                    n = n - 1;
                    ans += 1;
                }
            }
            else{
                if((n-10) % 4 == 0){
                    n = n/2;
                }
                else{
                    n = n - 1;
                }
            }

            turn = (turn + 1) % 2;
        }

        if(turn == 0){
            ans += dp[n];
        }
        else{
            ans += (n - dp[n]);
        }

        cout << ans << endl;
    }
}