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

int main(void) {
	while (true) {
		int A, B;
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}

		vector<int> seq_A;
		seq_A.push_back(A);
		while (seq_A.back() != 1) {
			seq_A.push_back( next(seq_A.back()) );
		}

		vector<int> seq_B;
		seq_B.push_back(B);
		while (seq_B.back() != 1) {
			seq_B.push_back( next(seq_B.back()) );
		}

		vector<int>::iterator ia = seq_A.end(), ib = seq_B.end();
		while (ia > seq_A.begin() && ib > seq_B.begin()) {
			vector<int>::iterator ia_prev = ia - 1, ib_prev = ib - 1;
			if (*ia_prev != *ib_prev) {
				break;
			}
			ia = ia_prev;
			ib = ib_prev;
		}
		
		cout << A << " needs " << (ia - seq_A.begin()) << " steps, " << B << " needs " << (ib - seq_B.begin()) << " steps, they meet at " << *ia << endl;
	}

	return 0;
}