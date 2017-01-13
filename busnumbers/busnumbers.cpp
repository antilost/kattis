#include <cstdio>
#include <iostream>
#include <algorithm> // sort
#include <vector>
using namespace std;
int main(void) {
	int count;
	cin >> count;
	vector<int> numbers;
	while (count--) {
		int n;
		cin >> n;
		numbers.push_back(n);
	}
	sort(numbers.begin(), numbers.end());
	auto last = unique(numbers.begin(), numbers.end());
	numbers.erase(last, numbers.end());

	int seq_len = 0;
	int prev = numbers[0];
	cout << numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		int n = numbers[i];
		if (n - prev == 1) {
			seq_len++;
		} else {
			if (seq_len > 0) {
				cout << (seq_len == 1 ? " " : "-") << prev;
			}
			cout << " " << n;
			seq_len = 0;
		}
		prev = n;
	}
	if (seq_len > 0) {
		cout << (seq_len == 1 ? " " : "-") << prev;
	}
	cout << endl;
	
	return 0;
}