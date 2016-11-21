// https://open.kattis.com/problems/artichoke

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double p, a, b, c, d;

double func(double k) {
	return p * ( sin(a * k + b) + cos(c * k + d) + 2 );
}

int main(void) {
	int n;
	cin >> p >> a >> b >> c >> d >> n;

	double max_f, max_decline;
	max_f = func(1);
	max_decline = 0;
	for (int i = 2; i <= n; i++) {
		double k = i;
		double f = func(k);

		if (f > max_f) {
			max_f = f;
		} else {
			double decline = max_f - f;
			if (decline > max_decline) {
				max_decline = decline;
			}
		}
	}

	cout << setprecision(15) << max_decline << endl;

	return 0;
}
