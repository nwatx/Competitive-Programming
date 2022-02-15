#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n; cin >> n;
	string s; getline(cin, s);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		int MOD  = 1e5;
		int a = MOD, b = MOD, c = MOD, d = MOD;
		transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c);});
		for(int j =0 ; j < s.size(); j++) {
			if(s[j] == 'n') a = min(a, j);
			else if(s[j] == 'u' && a != MOD) b = min(j, b);
			else if(s[j] == 't' && b != MOD && c == MOD) c = min(c,j);
			else if(s[j] == 't' && c != MOD) d = min(d, j);
			// cerr << a << " " << b << " " << c << " " << d << '\n';
		}

		bool drone = (a + b + c + d) < MOD;
		if(drone) cout << "Drone\n";
		else cout << "Bird\n";
	}
	
}