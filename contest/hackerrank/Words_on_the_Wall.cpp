#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		cout << s;
		s.erase(s.begin() + s.size() - 1);
	}
}