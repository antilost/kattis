#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cout << a << " is " << ( a % 2 == 0 ? "even" : "odd" ) << endl;
	}
	return 0;
}

