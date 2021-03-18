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
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

struct A {
	string a, b, c, d;
};

map<string, int> conv = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};

map<int, string> conv2;
map<string, int> values;

int main() {
	setIO();

	for(pair<string,int> a : conv) conv2[a.s] = a.f;

	int n; cin >> n;

	vector<A> v;

	for(int i = 0; i < n; i++) {
		string a, b, c, d, e,g, h, j;
		cin >> a >> b >> c >> d >> e >> g >> h >> j;
		v.pb({a, d, e, j});
	}

	values["Bessie"] = 0;

	while(!values.count("Elsie")) {
		for(A a : v) {
			// a = person b = previous/next c = type of year d = relation
			// cerr << "{ " << a.a << " " << a.b << " " << a.c << " " << a.d << "}\n";
			if(!values.count(a.a) && values.count(a.d)) {
				values[a.a] = values[a.d];
				if(a.b == "previous") { 
					while(conv2[(--values[a.a] + 12000) % 12] != a.c);
				} else if(a.b == "next") {
					while(conv2[(++values[a.a] + 12000) % 12] != a.c);
				}
			}
		}
	}

	// for(auto a : values) {
	// 	cerr << a.f << " " << a.s << "somethign\n";
	// }

	cout << abs(values["Bessie"] - values["Elsie"]);
}