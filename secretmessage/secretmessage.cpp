#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	string dummy_str;
	getline(cin, dummy_str);
	while (n--) {
		string original_message;
		getline(cin, original_message);

		// L is the original message length
		int L = original_message.length();

		// Find M: the smallest square number greater than or equal to L
		int M = L; int K;
		while (true) {
			double root = sqrt(M);
			if ( abs(root - static_cast<int>(root)) <= 1e-7 ) {
				K = root;
				break;
			}
			M++;
		}

		// Make matrix with characters
		char b[K][K];
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++) {
				int pos = i * K + j;
				b[i][j] = (pos < original_message.length())
					? original_message[pos]
					: '*';
			}

		for (int i = 0; i < K; i++)
			for (int j = K - 1; j >= 0; j--)
				if (b[j][i] != '*')
					cout << b[j][i];
		cout << endl;
	}
	return 0;
}