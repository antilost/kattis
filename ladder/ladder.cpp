// https://open.kattis.com/problems/ladder
#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
	double h, v, l;
	cin >> h >> v;
	l = h / sin( M_PI * v / 180.0);
	cout << round(l + 0.5) << endl;
	return 0;
}
