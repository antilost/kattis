// https://open.kattis.com/problems/collatz

#include <iostream>
#include <vector>

using namespace std;

int next(int current) {
	if (current % 2 == 0) {
		return current / 2;
	} else {
		return 3 * current + 1;
	}
}

vector<int> get_sequence(int start_number) {
	vector<int> seq;
	seq.push_back(start_number);

	int x = start_number;
	while (x != 1) {
		x = next(x);
		seq.push_back(x);
	}

	return seq;
}

int main(void) {
	while (true) {
		int A, B;
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}

		vector<int> seq_A = get_sequence(A), seq_B = get_sequence(B);

		vector<int>::iterator ia, ib, ia_prev, ib_prev;
		for (
			ia = seq_A.end(), ib = seq_B.end(), ia_prev = ia - 1, ib_prev = ib - 1;
			ia > seq_A.begin() && ib > seq_B.begin() && *ia_prev == *ib_prev;
			ia = ia_prev--, ib = ib_prev--
		);

		cout << A << " needs " << (ia - seq_A.begin()) << " steps, " << B << " needs " << (ib - seq_B.begin()) << " steps, they meet at " << *ia << endl;
	}

	return 0;
}