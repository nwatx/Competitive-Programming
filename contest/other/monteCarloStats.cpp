#include <bits/stdc++.h>

using namespace std;

const int N = 100; // 100 students to sample
const int MONTE_CARLO_ITERATIONS = (int)1e6;

int PRIZES[N]; // prizes won for person i

int main() {
	freopen("a.out","w",stdout);
	srand(5);
	for(int i = 0; i < MONTE_CARLO_ITERATIONS; i++) {
		int totalPrizes = 25;
		int totalTickets = 100;

		for(int j = 0; j < N; j++) {
			// each person comes up and attempts to take a prize
			if(totalPrizes == 0) break;

			// if takes prize
			if(totalPrizes >= 1 &&
				(1.0 * rand()) / RAND_MAX <= 1.0 / totalPrizes) {
				totalPrizes--;
				totalTickets--;
				PRIZES[j]++;
			} else { // remove the ticket
				// totalTickets--;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		cout << "(" << i << "," << PRIZES[i] << "),";
	}
}