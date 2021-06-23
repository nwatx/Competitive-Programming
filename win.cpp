/**
 * Description: line sweep to find two closest points 
 * Time: O(N\log N)
 * Source: Own
 * Verification: https://open.kattis.com/problems/closestpair2
 */

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 

using T = long double; // or long long
const T EPS = 1e-9; // might want to change
using P = pair<T,T>; using vP = V<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
	return sgn(a.f-b.f) == 0 && sgn(a.s-b.s) == 0; } 
T norm(const P& p) { return sq(p.f)+sq(p.s); }
T abs(const P& p) { return sqrt(norm(p)); }
T arg(const P& p) { return atan2(p.s,p.f); }
P conj(const P& p) { return P(p.f,-p.s); }
P perp(const P& p) { return P(-p.s,p.f); }
P dir(T ang) { return P(cos(ang),sin(ang)); }

P operator-(const P& l) { return P(-l.f,-l.s); }
P operator+(const P& l, const P& r) { 
	return P(l.f+r.f,l.s+r.s); }
P operator-(const P& l, const P& r) { 
	return P(l.f-r.f,l.s-r.s); }
P operator*(const P& l, const T& r) { 
	return P(l.f*r,l.s*r); }
P operator*(const T& l, const P& r) { return r*l; }
P operator/(const P& l, const T& r) { 
	return P(l.f/r,l.s/r); }
P operator*(const P& l, const P& r) { 
	return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
P operator/(const P& l, const P& r) { 
	return l*conj(r)/norm(r); }
P& operator+=(P& l, const P& r) { return l = l+r; }
P& operator-=(P& l, const P& r) { return l = l-r; }
P& operator*=(P& l, const T& r) { return l = l*r; }
P& operator/=(P& l, const T& r) { return l = l/r; }
P& operator*=(P& l, const P& r) { return l = l*r; }
P& operator/=(P& l, const P& r) { return l = l/r; }

P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
	return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) { 
	P a = l.f, d = l.s-l.f;
	return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) { 
	return (p+reflect(p,l))/(T)2; }
bool p_on_seg(const P& p, const Line& l) {
	return sgn(cross(l.f,l.s,p)) == 0 && sgn(dot(p-l.f,p-l.s)) <= 0; }

pair<P,P> solve(vP v) {
	pair<long double,pair<P,P>> bes; bes.f = 1e9+7;
	set<P> S; int ind = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		if (i && v[i] == v[i-1]) return {v[i],v[i]};
		for (; v[i].f-v[ind].f >= bes.f; ++ind) 
			S.erase({v[ind].s,v[ind].f});
		for (auto it = S.upper_bound({v[i].s-bes.f,1e9+7});
			it != end(S) && it->f < v[i].s+bes.f; ++it) {
			P t = {it->s,it->f};
			bes = min(bes, {abs(t-v[i]),{t,v[i]}});
		}
		S.insert({v[i].s,v[i].f});
	}
	return bes.s;
}