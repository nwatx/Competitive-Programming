// [auto_folder]:
// ^ type folder name for scripted placement

#include <bits/stdc++.h>

using namespace std;

vector<int> pi(const string &s) {
	int n = (int)s.size();
	vector<int> pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		cout << "i: " << i << ", j: " << j << "\n";
		while (j > 0 && s[j] != s[i]) {
			j = pi_s[j - 1];
			cout << "j:" << j << "\n";
		}

		if (s[i] == s[j]) {
			j++;
		}

		pi_s[i] = j;
		cout << j << "\n";
	}
	return pi_s;
}

int main() {
	string test = "abbaba";

	// abba

	auto ret = pi(test);
	for(int i = 0; i < ret.size(); i++) {
		cout << ret[i];
		if(i != ret.size() - 1) cout << " ";
	}
}