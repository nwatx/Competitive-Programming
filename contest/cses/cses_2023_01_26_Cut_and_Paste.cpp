// [auto_folder]: cses
// ^ type folder name for scripted placement

// Codeforces
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;
/* #region template */
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U

#define tN typename
#define cexp constexpr

tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

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
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcTUU> bool ckmin(T &a, U... b) {
	T mn = min(b...);
	return mn < a ? a = mn, 1 : 0; } // set a = max(a,b)

tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
tcTUU> bool ckmax(T &a, U... b) {
	T mx = max(b...);
	return mx > a ? a = mx, 1 : 0; } // set a = min(a,b)

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
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	tcT> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif
}

inline namespace FileIO {
	void setIn(str s)  { (void)!freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { (void)!freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
};
/* #endregion */

// Changeable constants
const db EPS = 1e-9;
const int mx = 2e5+1;

/* #region snippets */

/* #endregion */

/**
 * Description: Easy BBST. Use split and merge to implement insert and delete.
 * Time: O(\log N)
 * Source: https://cp-algorithms.com/data_structures/treap.html + others. Also consider
	* https://codeforces.com/contest/1340/submission/77861280 (no pointers -> faster)
	* https://codeforces.com/contest/1340/submission/77852254 (shared_ptr -> destroyed when nothing refers to it)
 * Verification: http://www.spoj.com/problems/ORDERSET/
 */

typedef struct tnode* pt;
struct tnode {
	int pri, val; pt c[2]; // essential
	int sz; ll sum; // for range queries
	bool flip = 0; // lazy update
	tnode (int _val) {
		pri = rng(); sum = val = _val; 
		sz = 1; c[0] = c[1] = NULL;
	}
	~tnode() { F0R(i,2) delete c[i]; } // assume no sharing of data
};
int getsz(pt x) { return x?x->sz:0; }
ll getsum(pt x) { return x?x->sum:0; }
pt prop(pt x) { // lazy propagation
	if (!x || !x->flip) return x;	
	swap(x->c[0],x->c[1]);
	x->flip = 0; F0R(i,2) if (x->c[i]) x->c[i]->flip ^= 1;
	return x;
}
pt calc(pt x) {
	pt a = x->c[0], b = x->c[1];
	assert(!x->flip); prop(a), prop(b);
	x->sz = 1+getsz(a)+getsz(b);
	x->sum = x->val+getsum(a)+getsum(b);
	return x;
}
void tour(pt x, vi& v) { // print values of nodes, 
	if (!x) return; // inorder traversal
	prop(x); tour(x->c[0],v); v.pb(x->val); tour(x->c[1],v);
}
pair<pt,pt> split(pt t, int v) { // >= v goes to the right
	if (!t) return {t,t};
	prop(t);
	if (t->val >= v) {
		auto p = split(t->c[0], v); t->c[0] = p.s;
		return {p.f,calc(t)};
	} else {
		auto p = split(t->c[1], v); t->c[1] = p.f;
		return {calc(t),p.s};
	}
}
pair<pt,pt> splitsz(pt t, int sz) { // sz nodes go to left
	if (!t) return {t,t};
	prop(t);
	if (getsz(t->c[0]) >= sz) {
		auto p = splitsz(t->c[0],sz); t->c[0] = p.s;
		return {p.f,calc(t)};
	} else {
		auto p=splitsz(t->c[1],sz-getsz(t->c[0])-1); t->c[1]=p.f;
		return {calc(t),p.s};
	}
}
pt merge(pt l, pt r) { // merge treaps, keys in left < keys in right
	if (!l || !r) return l?:r;
	prop(l), prop(r); pt t;
	if (l->pri > r->pri) l->c[1] = merge(l->c[1],r), t = l;
	else r->c[0] = merge(l,r->c[0]), t = r;
	return calc(t);
}
pt ins(pt x, int v) { // insert v
	auto a = split(x,v), b = split(a.s,v+1);
	return merge(a.f,merge(new tnode(v),b.s)); }
pt del(pt x, int v) { // delete v
	auto a = split(x,v), b = split(a.s,v+1);
	return merge(a.f,b.s); }

int to(char x, int i) {
	return (x - 'A') * mx + i;
}

char from(int i) {
	return (i / mx) + 'A';
}

void solve() {
	int n, q; re(n, q);
	string s; re(s);

	pt root = new tnode(s[0]);

	FOR(i, 1, n) {
		root = merge(root, new tnode(s[i]));
	}

	while(q--) {
		int l, r; re(l, r);
		auto s1 = splitsz(root, l - 1);
		auto s2 = splitsz(s1.s, r - l + 1);
		root = merge(s1.f, s2.s);
		root = merge(root, s2.f);
	}

	vi ret;
	tour(root, ret);
	each(x, ret) {
		cout << (char)x;
	}
}

signed main() {
	// clock_t start = clock();
	setIO();

	int n = 1;
	// re(n);
	rep(n) {
		// pr("Case #", _ + 1, ": "); // Kickstart
		cerr << "[dbg] Case #" << _ + 1 << ":\n";
		solve();
	}

	// cerr << "Total Time: " << (double)(clock() - start)/ CLOCKS_PER_SEC;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/