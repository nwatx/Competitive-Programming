#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char mat[101][101];

int main() {
    int n; cin >> n;
    pair<int, int> a, b;
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'p') b = {i, j};
            if(mat[i][j] == 'm') a = {i, j};
        }
    }
    
    string ds = "UP";
    if(a.f < b.f) ds = "DOWN";
    for(int i = 0; i < abs(a.f - b.f); i++) cout << ds << "\n";
    ds = "LEFT";
    if(a.s < b.s) ds = "RIGHT";
    for(int i = 0; i < abs(a.s - b.s); i++) cout << ds << '\n';

    return 0;
}
