// https://open.kattis.com/problems/speedlimit
#include <iostream>
using namespace std;
int main(void) {
	while (1) {
		int n;
		cin >> n;
		if (n == -1) {
			break;
		}
		int hours_prev = 0;
		int sum = 0;
		while (n--) {
			int speed, hours;
			cin >> speed >> hours;
			sum += speed * (hours - hours_prev);
			hours_prev = hours;
		}
		cout << sum << " miles " << endl;
	}
	return 0;
}