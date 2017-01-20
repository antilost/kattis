// https://open.kattis.com/problems/ants

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int cases_count;
	cin >> cases_count;

	while (cases_count--) {
		int l, n;
		cin >> l >> n;

		int best_time = 0;
		int worst_time = -1;
		for (int i = 0; i < n; i++) {
			int ant;
			cin >> ant;
			best_time = max( best_time, min(l - ant, ant) );
			if (worst_time < 0) {
				worst_time = ant;
			}
			worst_time = max( worst_time, max(l - ant, ant) );
		}

		cout << best_time << " " << worst_time << endl;
	}

	return 0;
}
