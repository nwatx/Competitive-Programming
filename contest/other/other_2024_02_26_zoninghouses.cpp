// [auto_folder]: 
// ^ type folder name for scripted placement

#include <bits/stdc++.h>
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

const int mx = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;

// for an interval, get max, get min, get best
struct Pt {
    int lox1, lox2, loy1, loy2, hix1, hix2, hiy1, hiy2, best;

    void set(int x, int y) {
        lox1 = x;
        lox2 = MOD;
        loy1 = y;
        loy2 = MOD;
        hix1 = x;
        hix2 = -MOD;
        hiy1 = y;
        hiy2 = -MOD;
        best = 0;
    }
};


struct Seg { // comb(ID,b) = b
    using T = Pt;
    const T ID{MOD, MOD, MOD, MOD, -MOD, -MOD, -MOD, -MOD, 2 * MOD}; T comb(T a, T b) {
        T t = ID;
        vector<int> lowest{a.lox1, a.lox2, b.lox1, b.lox2};
        sort(lowest.begin(), lowest.end());
        t.lox1 = lowest[0], t.lox2 = lowest[1];

        vector<int> highest{a.hix1, a.hix2, b.hix1, b.hix2};
        sort(highest.rbegin(), highest.rend());
        t.hix1 = highest[0], t.hix2 = highest[1];

        vector<int> lowesty{a.loy1, a.loy2, b.loy1, b.loy2};
        sort(lowesty.begin(), lowesty.end());
        t.loy1 = lowesty[0], t.loy2 = lowesty[1];

        vector<int> highesty{a.hiy1, a.hiy2, b.hiy1, b.hiy2};
        sort(highesty.rbegin(), highesty.rend());
        t.hiy1 = highesty[0], t.hiy2 = highesty[1];

        int xl = abs(t.lox2) < MOD ? t.lox2 : t.lox1;
        int yl = abs(t.loy2) < MOD ? t.loy2 : t.loy1;
        int xh = abs(t.hix2) < MOD ? t.hix2 : t.hix1;
        int yh = abs(t.hiy2) < MOD ? t.hiy2 : t.hiy1;

        // cout << xl << " " << yl << " " << xh << " " << yh << "\n";

        // have to build along x or y
        t.best = max(xh - xl, yh - yl);
        return t;
    } 

    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) {
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {
        T ra = ID, rb = ID; 
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    Seg seg; seg.init(n);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        Pt p; p.set(x, y);
        seg.upd(i, p);
    }

    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        Pt best = seg.query(l, r);
        cout << "l: " << l << " r: " << r << " <-> " << best.lox1 << " " << best.lox2 << " " << best.hix1 << " " << best.hix2 << "\n";

        cout << seg.query(l, r).best << "\n";
    }
}