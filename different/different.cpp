/*
 * https://open.kattis.com/problems/different
 * Write a program that computes the difference between non-negative integers.
 *
 * Input
 * Each line of the input consists of a pair of integers.
 * Each integer is between 0 and 10^15 (inclusive).
 * The input is terminated by end of file.
 *
 * Output
 * For each pair of integers in the input, output one line, containing the absolute value of their difference.
 */

#include <iostream>
#include <string> // length
using namespace std;

void print_diff(string s) {
	int space_pos = 0;
	while (s[+space_pos] != ' ')
		space_pos++;

	int l1 = space_pos, l2 = s.length() - space_pos - 1;
	int l = (l1 > l2) ? l1 : l2;

	int* a = new int[l];
	int* b = new int[l];
	int* c = new int[l];
	for (int i = 0; i < l; i++) {
		a[i] = b[i] = c[i] = 0;
	}

	for (int i = l1 - 1; i >= 0; i--)
		a[l1 - 1 - i] = static_cast<int>(s[i] - '0');

	for (int i = s.length() - 1; i >= l1 + 1; i--) {
		b[s.length() - 1 - i] = static_cast<int>(s[i] - '0');
	}

	// Need to swap a and b: a will contain the greatest number
	int j = l - 1;
	while (a[j] == b[j])
		j--;
	if ((j >= 0) && (a[j] < b[j])) {
		for (int i = 0; i < l; i++) {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
	}

	// Calculate difference
	for (int i = 0; i < l; i++) {
		int d = a[i] - b[i];
		if (d >= 0) {
			c[i] = d;
		} else {
			c[i] = d + 10;
			a[i + 1]--;
		}
	}

	// Print result
	int k = l - 1;
	while (c[k] == 0)
		k--;
	if (k < 0) {
		// All zeroes (equal numbers)
		cout << '0';
	}
	while (k >= 0) {
		cout << c[k];
		k--;
	}
	cout << endl;
}

int main(void) {
	string s;
	while (getline(cin, s)) {
		print_diff(s);
	}
	return 0;
}
