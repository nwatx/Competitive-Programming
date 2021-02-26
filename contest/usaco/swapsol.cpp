#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100000
 
int N,M,K;
int l[100],r[100], c[100];
vector<int> p;
int cc[MAXN];
int pos[MAXN];
vector<int> A[MAXN+1];
int ans[MAXN];

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }

void rot(vector<int> &a, int k) {
	for(int i = 0; i < k; i++) {
		a.push_back(*a.begin());
		a.erase(a.begin());
	}
}
 
int main() {
    unsyncIO();
	cin >> N >> M >> K;
    p.resize(N);
	for(int i=0;i<M;i++) {
		cin >> l[i] >> r[i] >> c[i];
		l[i]--,r[i]--, c[i] %= N;
	}
	for(int i=0;i<N;i++) {
		p[i] = i;
	}
    for(int i = 0; i < M; i++) {
		// for(int j = 0; j < (abs(l[i] - r[i])+1)/2; j++) {
		// 	swap(p[l[i] + j], p[r[i] - j]);
		// }
        reverse(begin(p)+l[i]-1, begin(p)+r[i]);
        rot(p, c[i]);
    }
	int C = 1;
	for(int i=0;i<N;i++) if(!cc[i]) {
		cc[i] = C;
		A[C].push_back(i);
		int j = p[i];
		if(j != i) pos[j] = 1;
		while(j != i) {
			A[C].push_back(j);
			cc[j] = C;
			if(p[j]!=i) pos[p[j]] = 1 + pos[j];
			j = p[j];
		}
		C++;
	}
	for(int i=0;i<N;i++)
		ans[A[cc[i]][(pos[i] + K)%A[cc[i]].size()]] = i;
	for(int i=0;i<N;i++)
		cout << ans[i]+1 << '\n';
	
}