// https://open.kattis.com/problems/flexible

// g++ flexible.cpp --std=c++11

#include <iostream>
#include <vector>
#include <algorithm> // sort, unique

using namespace std;

int main(void) {
	int W, P;
	cin >> W >> P;

	vector<int> partitions;
	vector<int> distinct_widths;
	while (P-- > 0) {
		int L;
		cin >> L;
		partitions.push_back(L);
	}

	for (vector<int>::iterator i = partitions.begin(); i < partitions.end(); i++) {
		distinct_widths.push_back(*i);
		distinct_widths.push_back(W - *i);
	
		for (vector<int>::iterator j = partitions.begin(); j < i; j++) {
			distinct_widths.push_back(*i - *j);
		}
	}
	distinct_widths.push_back(W);

	sort(distinct_widths.begin(), distinct_widths.end());
	auto last = unique(distinct_widths.begin(), distinct_widths.end());
	distinct_widths.erase(last, distinct_widths.end());
	
	for (int i : distinct_widths) {
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
