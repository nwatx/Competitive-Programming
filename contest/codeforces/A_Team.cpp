#include <bits/stdc++.h>

#define d func;
	
using namespace std;
	
int test() {
	int n; cin >> n;
	int ret = 0;
	while(n--) {
		int a, b, c; cin >> a >> b >> c;
		if(a + b + c >= 2) ret++;
	}
	
	cout << ret;
}
	
int main() {
	test();
}