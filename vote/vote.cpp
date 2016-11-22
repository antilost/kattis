// https://open.kattis.com/problems/vote

#include <iostream>

using namespace std;

int main(void) {
	int test_cases_count;
	cin >> test_cases_count;

	while (test_cases_count--) {
		// Process input
		int candidates_count;
		cin >> candidates_count;
		int votes[candidates_count];
		for (int i = 0; i < candidates_count; i++) {
			cin >> votes[i];
		}

		// Find global maximum (candidate winner)
		int winner = 0;
		for (int i = 1; i < candidates_count; i++) {
			if (votes[i] > votes[winner]) {
				winner = i;
			}
		}

		// Check if there are not another candidate with the same votes count
		bool winner_defined = true;
		int i = 0;
		while (winner_defined && i < candidates_count) {
			if (i != winner && votes[i] == votes[winner]) {
				winner_defined = false;
			}
			i++;
		}

		// Calculate votes sum
		int sum = 0;
		for (int i = 0; i < candidates_count; i++)
			sum += votes[i];

		// Print results
		if (winner_defined) {
			if (votes[winner] > sum / 2.0) {
				cout << "majority winner " << winner + 1 << endl;
			} else {
				cout << "minority winner " << winner + 1 << endl;
			}
		} else {
			cout << "no winner" << endl;
		}
	}

	return 0;
}