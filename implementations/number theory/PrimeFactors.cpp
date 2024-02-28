// PrimeFactors
// Computes the prime factors of a number in O(\log n) with O(N\log\log N) preprocessing
template<int N>
struct PrimeFactors {
    // Computes the prime factors of a number in O(\log n) with O(N\log\log N) preprocessing
    int min_d[N];
	// O(N\log\log N)
    PrimeFactors() : min_d() {
        F0R(i, N) min_d[i] = i;
        FOR(p, 2, N) {
            if(min_d[p] != p) continue;
            for(int d = p * 2; d < N; d += p) {
                min_d[d] = min(min_d[d], p);
            }
        }
    }

    // Time Complexity: O(\log n), returns prime factors of a number
    vi factor(int x) {
        vi ret;
        while (x > 1) {
			if(ret.empty() || ret.back() != min_d[x]) {
				ret.pb(min_d[x]);
			}
			x /= min_d[x];
        }
		return ret;
    }
};