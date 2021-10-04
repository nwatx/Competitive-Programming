//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
<<<<<<< HEAD:Problem_2_Modern_Art_3.cpp
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
=======
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

<<<<<<< HEAD:contest/cses/Counting_Towers.cpp
using Mii = map<int, int>;
using Mll = map<ll, ll>;

=======
>>>>>>> 5b50eefd016032659f0b8b8ef3343b3d2e934f8d:Problem_2_Modern_Art_3.cpp
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
>>>>>>> f01bfc519e39eb3680a5c9457dedff31e99e53f6:contest/usaco/Problem_2_Modern_Art_3.cpp

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

<<<<<<< HEAD:Problem_2_Modern_Art_3.cpp
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
=======
// vectors
// size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define sorr(x) sort(rall(x))
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const char nl = '\n';
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

<<<<<<< HEAD:contest/cses/Counting_Towers.cpp
=======
// variadic max
template<tN h0, tN h1, tN...Tl>
cexp auto max(h0 &&hf, h1 &&hs, Tl &&... tl) {
	if cexp (sizeof...(tl) == 0)
		return hf > hs ? hf : hs;
	else return max(max(hf, hs), tl...);
}

// vardiadic min
template<tN h0, tN h1, tN...Tl>
cexp auto min(h0 &&hf, h1 &&hs, Tl &&... tl) {
	if cexp (sizeof...(tl) == 0)
		return hf < hs ? hf : hs;
	else return min(min(hf, hs), tl...);
}

// variadic min / max
>>>>>>> 5b50eefd016032659f0b8b8ef3343b3d2e934f8d:Problem_2_Modern_Art_3.cpp
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

// searching
tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}

tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}

tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
									  decltype(end(declval<T>()))
									 >
						   > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cin >> declval<T&>()), istream&>
			>
		> : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cout << declval<T>()), ostream&>
			>
		> : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
>>>>>>> f01bfc519e39eb3680a5c9457dedff31e99e53f6:contest/usaco/Problem_2_Modern_Art_3.cpp
}
//EndCodeSnip

const int MAX_N = 301;

int A[MAX_N], dp[MAX_N][MAX_N];

int main() {
	setIO();
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = MAX_N + 1;
		}
	}

<<<<<<< HEAD:Problem_2_Modern_Art_3.cpp
	for (int i = 0; i < n; i++) dp[i][i] = 1;
	
	for (int s = 1; s <= n; s++) {
		for (int i = 0; i <= n - s; i++) {
			for (int j = i; j < i + s; j++) {
				int k = i + s - 1;
				// explained in editorial
				if (A[i] == A[k])
					dp[i][k] = min(dp[i][k], dp[i][j] + dp[j + 1][k] - 1);
				dp[i][k] = min(dp[i][k], dp[i][j] + dp[j + 1][k]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}
=======
/* #endregion */

const int mx = 2e5+1;

<<<<<<< HEAD:contest/cses/Counting_Towers.cpp
int dp[mx][5];
// 2 x 1x1
=======
int A[mx];
int dp[301][301]; // min for [i, j];

void solve() {
	int n; re(n);
	F0R(i,n) re(A[i]);

	F0R(i,301)F0R(j,301) dp[i][j] = MOD;

	F0R(i, 301) dp[i][i] = 1;

	FOR(s,1,n+1) {
		F0R(i,n-s+1) {
			FOR(j, i, i+s) {
				// if two intervals share the same endpoint: merge
				{
					int k = i + s - 1;
					if(A[i] == A[k]) ckmin(dp[i][k], dp[i][j] + dp[j+1][k] - 1);
					ckmin(dp[i][k], dp[i][j] + dp[j+1][k]);
				}
			}
		}
	}

	// F0R(i, n) {
	// 	F0R(j, n) {
	// 		pr(dp[i][j] == MOD ? "=" : ts(dp[i][j]), " ");
	// 	}
	// 	ps();
	// }

	ps(dp[0][n-1]);
}
>>>>>>> 5b50eefd016032659f0b8b8ef3343b3d2e934f8d:Problem_2_Modern_Art_3.cpp

signed main() {
	// clock_t start = clock();
	setIO();

<<<<<<< HEAD:contest/cses/Counting_Towers.cpp
=======
	int n = 1;
	// re(n);
	rep(n) solve();

>>>>>>> 5b50eefd016032659f0b8b8ef3343b3d2e934f8d:Problem_2_Modern_Art_3.cpp
	// cerr << "Total Time: " << (double)(clock() - start)/ CLOCKS_PER_SEC;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* geo and benq orz
*/
>>>>>>> f01bfc519e39eb3680a5c9457dedff31e99e53f6:contest/usaco/Problem_2_Modern_Art_3.cpp
