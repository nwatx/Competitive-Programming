#include <bits/stdc++.h> // see /general/running-code-locally
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
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		(void)!freopen((name+".in").c_str(), "r", stdin); // see /general/io
		(void)!freopen((name+".out").c_str(), "w", stdout);
	}
}

int out_degree[101]; // 1...100

int main() {
	setIO("factory");

    int N; cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        // a -> b
        out_degree[a]++;
    }

    int answer = -1;

    for(int i = 1; i <= N; i++) {
        if(out_degree[i] == 0 && answer != -1) {
            answer = - 1; break;
        } // we have two sinks

        if(out_degree[i] == 0) {
            answer = i;
        }
    }

    cout << answer << "\n";
}