#include <bits/stdc++.h>

using namespace std;

std::vector<int> v{0, 1, 1, 0, 1, 0, 0, 0};

// iterations:
// 01 01 01 00
// 0011 0001
// 00000111

// 01101000
// (2, 3), (4, 5) => 01010100
// (1, 2) => 00110100
// (5, 7) => 00110001
// (2, 6) => 00000111

// [l, r]
void invert(int l, int r) {
    for(int i = 0; i < (r - l + 1) / 2; i++) {
        swap(v[l + i], v[r - i]);
    }
}

/**
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element. Change \texttt{null\_type} for map.
 * Time: O(\log N)
 * Source: KACTL
   * https://codeforces.com/blog/entry/11080
 * Verification: many
 */

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f; assert(it == t.lb(9));
	assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

/**
int atMost(Tree<pi>& T, int r) { 
	return T.ook({r,MOD}); }
int getSum(Tree<pi>& T, int l, int r) { 
	return atMost(T,r)-atMost(T,l-1); }
*/

// sorts [l, r]
int sort(int l = 0, int r = v.size() - 1) {
	printf("[l: %d, r: %d)\n", l, r);
	// store # of ones
	if(l == r) {
		return v[l] == 1;
	}

	int mid = (l + r) / 2;
	int left = sort(l, mid);
	int right = sort(mid + 1, r);

	if(left == 0) return right;

	int l_inv = mid - left + 1, r_inv = r - right;
	// std::cout << l_inv << " " << r_inv << "\n";
	invert(l_inv, r_inv);
	// invert(mid - left, mid + left);

	// 01101110
	// 0101
	return left + right;
}

int main() {

	sort();

	for(int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}