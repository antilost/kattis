// https://open.kattis.com/problems/server
#include <iostream>
using namespace std;
int main(void) {
	int n, T;
	cin >> n;
	cin >> T;

	int tasks_completed_count = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		T -= t;
		if (T >= 0) {
			tasks_completed_count++;
		} else {
			break;
		}
	}

	cout << tasks_completed_count << endl;

	return 0;
}