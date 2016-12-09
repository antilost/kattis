#include <iostream>
using namespace std;
int main(void) {
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		int calories_per_day;
		cin >> calories_per_day;
		int calories_per_bottle = 400;
		double dbl_bottles_per_day = static_cast<double>(calories_per_day) / static_cast<double>(calories_per_bottle);

		int bottles_per_day = static_cast<int>(dbl_bottles_per_day);
		if (dbl_bottles_per_day - bottles_per_day > 0) {
			bottles_per_day++;
		}

		cout << bottles_per_day << endl;
	}

	return 0;
}
