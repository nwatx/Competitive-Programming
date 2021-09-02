#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		(void)!freopen((name+".in").c_str(), "r", stdin); // see /general/io
		(void)!freopen((name+".out").c_str(), "w", stdout);
	}
}

//CodeSnip{CPP Short Template}
//BeginCodeSnip{HashTable}

/**
 * Description: Hash map with the same API as unordered\_map, but \tilde 3x faster.
	 * Initial capacity must be a power of 2 if provided.
 * Source: KACTL
 * Usage: ht<int,int> h({},{},{},{},{1<<16});
 */

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
const long double PI = acos((long double)-1);

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
	const uint64_t C = ll(2e18*PI)+71; // large odd number
	const int RANDOM = rng();
	ll operator()(ll x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using um = unordered_map<K,V,chash>;
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
template<class K,class V> V get(ht<K,V>& u, K x) {
	auto it = u.find(x); return it == end(u) ? 0 : it->s; }

//EndCodeSnip{HashTable}


const int mx = 5e5+1;

int n, k;
int v[mx];
pi ret;

int lowest = 0;

bool check(int x) {
	if(x > n) return 0;
	ht<int, int> s({},{},{},{},{1<<19});

	int j = 0;
	s[v[0]]++;

	for(int i = 0; i < n; i++) {
		while(j < n - 1 && j < i + x - 1) {
			j++;
			s[v[j]]++;
		}

		if(sz(s) <= k && j - i == x - 1) {
			if(x > lowest) {
				ret = {i, j};
			}
			return 1;
		}

		s[v[i]]--;
		if(s[v[i]] <= 0) s.erase(v[i]);
	}

	return 0;
}

int main() {
	setIO();

	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> v[i];
	
	int lo = 1, hi = n;
	lo--; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		int mid = lo+(hi-lo+1)/2;
		check(mid) ? lo = mid : hi = mid-1;
	}

	cout << ret.f + 1 << " " << ret.s + 1;
}