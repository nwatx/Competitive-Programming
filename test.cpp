#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> A {5,2,3,1,4};

	int n = 5;

	// assumes the first i elements are sorted
	for(int i = 0; i < n; i++) {
		int x = A[i];

		// go "left" as long as A[j] > x
		int j = i - 1;
		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}

	for(int i = 0; i < 5; i++) {
		cout << A[i] << '\n';
	}
}