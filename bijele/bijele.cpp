// https://open.kattis.com/problems/bijele
#include <iostream>
using namespace std;
int main(void) {
	const int N = 6;
	int model[N] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		cout << model[i] - n;
		if (i < N - 1) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}