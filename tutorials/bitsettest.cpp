#include <bits/stdc++.h>

using namespace std;

#define ps(x) cout << (x).to_string() << "\n"

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// default initialization to zeroes
	bitset<8> bs;
	ps(bs); // 00000000

	// assignment
	bs = bitset<8>(5);
	ps(bs); // 00000101

	// flips bits
	bs.flip();
	ps(bs); // 11111010

	// counts # of significant bits
	cout << bs.count() << "\n"; // 6

	// resets bitset to 000...0
	bs.reset();
	ps(bs);

	// test if all bits are set 
	cout << "\nTesting if bits are set\n";
	cout << bs.all() << '\n'; // false
	cout << bs.none() << '\n'; // true
	bs = bitset<8>("11111111");
	cout << bs.all() << '\n'; // true
	cout << bs.none() << '\n'; // false

	bs.set(2, 0); // sets third bit from the right
	ps(bs); // 11111011

	cout << bs[2] << '\n'; // 0
	cout << bs[3] << '\n'; // 1

	ps(bs ^ bitset<8>(10)); // 11111011 ^ 00001010 = 11110001
}