#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 60; j++) {
            for(int k = 0; k < 60; k++) {
                v.push_back({i, j, k});
            }
        }
    }

    cout << (int)v.size() << "\n";
    for(auto [h, m, s] : v) {
        cout << h << " " << m << " " << s << "\n";
    }
}