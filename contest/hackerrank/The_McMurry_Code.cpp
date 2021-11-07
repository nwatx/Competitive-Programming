#include <bits/stdc++.h>

using namespace std;

benq

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<string> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		string s;
		int p; cin >> p;
		string word = "";
		getline(cin, s);
		for(int i = 0; i < p; i++) {
			getline(cin, s);
			// cerr << s << '\n';
			if(i%2 == 0) {
				for(int j = 0; j < s.size(); j++) {
					if(s[j] != ' ') word += (s[j]);
				}
			} else {
				for(int j = s.size() - 1; j >= 0; j--) {
					if(s[j] != ' ') word += (s[j]);
				}
			}
		}

		// cout << word << '\n';

		bool good = true;
		for(string x : v) {
			// cerr << x << '\n';
			if(word.find(x) == string::npos) {
				good = false;
				break;
			}
		}

		if(good) cout << "All words found!\n";
		else cout << "Unsolvable. Not fair!\n";

		// for(int i = 0;i  < word.size(); i++) {
		// 	cerr << word[i];
		// }
		// cerr <<'\n';
	}
}