#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5+1;

using vpi = vector<pair<int, int>>;

#define f first
#define s second

int main() {
	// clock_t start = clock();
	// setIO();

    int n; cin >> n;
    vpi v(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }

    set<int> s;
    for(int i = 0; i < n; i++) {
        switch(v[i].f) {
            case 1: s.insert(v[i].s); break;
            case 2: s.erase(v[i].s); break;
            case 3: s.count(v[i].s) ? cout << "Yes\n" : cout << "No\n";
        }
    }

	// cerr << "Total Time: " << (double)(clock() - start)/ CLOCKS_PER_SEC;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/