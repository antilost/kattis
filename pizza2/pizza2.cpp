#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
	double radius, crust;
	cin >> radius >> crust;
	
	double cheese = radius - crust;
	double result = cheese * cheese / (radius * radius) * 100.0;

	cout << fixed << setprecision(9) << result << endl;

	return 0;
}