#include <bits/stdc++.h>

using namespace std;

int main() {
	int x = 10, y = 15;
	x = x ^ y ^ (y = x);
	cout << x << " " << y;
}