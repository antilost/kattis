// https://open.kattis.com/problems/cold
#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	int count = 0;
	while (n--) {
		int t;
		cin >> t;
		if (t < 0) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
