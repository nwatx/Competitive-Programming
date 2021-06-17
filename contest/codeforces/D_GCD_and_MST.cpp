#include <bits/stdc++.h>
using namespace std;

#pragma region
 
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
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

/**
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

template<class T, int SZ> struct LazySeg { 
	static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID = 0; T comb(T a, T b) { return a+b; }
	T seg[2*SZ], lazy[2*SZ]; 
	LazySeg() { F0R(i,2*SZ) seg[i] = lazy[i] = ID; }
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; 
		return comb(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
	}
};

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
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

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

tcTU> T ternMax(T l, T r, U f) { // unimodal functions
    for(;r-l>0;) {
        T m1 = l+(r-l)/3;T m2=r-(r-l)/3;T f1=f(m1);T f2=f(m2);
        if(f1<f2)l=m1+1;else r=m2-1; }
    return f(l);
}

tcTU> T ternMin(T l, T r, U f) {
    for(;r-l>0;) {
        T m1 = l+(r-l)/3;T m2=r-(r-l)/3;T f1=f(m1);T f2=f(m2);
        if(f1>f2)l=m1+1;else r=m2-1; }
    return f(l);
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
        return ts_sep(v, " "); }
		// return "{"+ts_sep(v,", ")+"}"; }

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
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// print n elements
	template<class T> void pv(const T &t, const int &n) { F0R(i, n-1) pr(t[i], " "); ps(t[n-1]); }
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

#pragma endregion

const int mx = 2e5+1;
// /**
//  * Description: 1D point update, range query where \texttt{comb} is
//      * any associative operation. If $N=2^p$ then \texttt{seg[1]==query(0,N-1)}.
//  * Time: O(\log N)
//  * Source: 
//     * http://codeforces.com/blog/entry/18051
//     * KACTL
//  * Verification: SPOJ Fenwick
//  */

// template<class T> struct SegMin { // comb(ID,b) = b
//     const T ID = MOD; T comb(T a, T b) { return min(a, b); } 
//     int n; vector<T> seg;
//     void init(int _n) { n = _n; seg.assign(2*n,ID); }
//     void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
//     void upd(int p, T val) { // set val at position p
//         seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
//     T query(int l, int r) {	// sum on interval [l, r]
//         T ra = ID, rb = ID; 
//         for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
//             if (l&1) ra = comb(ra,seg[l++]);
//             if (r&1) rb = comb(seg[--r],rb);
//         }
//         return comb(ra,rb);
//     }
// };

// /**
//  * Description: Disjoint Set Union with path compression
//      * and union by size. Add edges and test connectivity. 
//      * Use for Kruskal's or Boruvka's minimum spanning tree.
//  * Time: O(\alpha(N))
//  * Source: CSAcademy, KACTL
//  * Verification: *
//  */

// struct DSU {
//     vi e; void init(int N) { e = vi(N,-1); }
//     int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
//     bool sameSet(int a, int b) { return get(a) == get(b); }
//     int size(int x) { return -e[get(x)]; }
//     bool unite(int x, int y) { // union by size
//         x = get(x), y = get(y); if (x == y) return 0;
//         if (e[x] > e[y]) swap(x,y);
//         e[x] += e[y]; e[y] = x; return 1;
//     }
// };

// template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
//     sort(all(ed));
//     T ans = 0; DSU D; D.init(N); // edges that unite are in MST
//     each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
//     return ans;
// }

// void solve() {
//     ints(n, p);
//     Seg<int> seg;
//     SegMin<int> mq;
//     seg.init(n);
//     mq.init(n);

//     F0R(i, n) {
//         int a; cin >> a;
//         seg.upd(i, a);
//         mq.upd(i, a);
//     }

//     vector<pair<ll, pi>> ed;

//     F0R(i, n-1) ed.pb({p, {i, i+1}});
//     F0R(i, n) FOR(j, i + 1, n) {
//         // dbg(i, j, seg.query(i, j), rmq.query(i, j));
//         if(seg.query(i, j) == mq.query(i, j)) ed.pb({mq.query(i, j), {i, j}});
//     }

//     // dbg(n, ed);

//     ps(kruskal(n, ed));
// }

/**
 * Description: 1D point update, range query where \texttt{comb} is
     * any associative operation. If $N=2^p$ then \texttt{seg[1]==query(0,N-1)}.
 * Time: O(\log N)
 * Source: 
    * http://codeforces.com/blog/entry/18051
    * KACTL
 * Verification: SPOJ Fenwick
 */

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return gcd(a, b); } 
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {	// sum on interval [l, r]
        T ra = ID, rb = ID; 
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

/**
 * Description: Disjoint Set Union with path compression
     * and union by size. Add edges and test connectivity. 
     * Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

AR<int, mx> A;
Seg<int> grq;

void solve() {
    int n, p; re(n, p);
    F0R(i, n) re(A[i]);
    
    grq.init(n);
    F0R(i, n) grq.upd(i, A[i]);

    V<pair<int, pi>> ed;
    ll ans = 0; DSU D; D.init(n); // edges that unite are in MST

    F0R(i, n - 1) {
        int cmin = A[i];
        int conn = i + 1;
        int connCost = p;
        FOR(j, i + 1, n) {
            ckmin(cmin, A[j]);
            int rangeMin = grq.query(i, j);
            if(cmin == rangeMin && rangeMin < connCost) {
                conn = j;
                ckmin(connCost, rangeMin);
            }
        }

        if(D.unite(i, conn)) ans += connCost;
    }

    ps(ans);
}

int main() {
	// clock_t start = clock();
	setIO();

    int n; re(n); while(n--) solve();

	// cerr << "Total Time: " << (double)(clock() - start)/ CLOCKS_PER_SEC;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/