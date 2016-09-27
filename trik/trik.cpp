// https://open.kattis.com/problems/trik
/*
 * @.. -> .@. A
 * .@. -> ..@ B
 * @.. -> ..@ C
 */
#include <iostream>
using namespace std;
int main(void) {
	string s;
	getline(cin, s);
	int p = 1;
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		switch(*it) {
			case 'A':
				if (p == 1) { p = 2; } else if (p == 2) { p = 1; }
				break;
			case 'B':
				if (p == 2) { p = 3; } else if (p == 3) { p = 2; }
				break;
			case 'C':
				if (p == 1) { p = 3; } else if (p == 3) { p = 1; }
		}
	}
	cout << p << endl;
	return 0;
}