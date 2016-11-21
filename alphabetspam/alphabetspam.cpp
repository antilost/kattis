/*
 * https://open.kattis.com/problems/alphabetspam
 * 
 * Alphabet Spam
 *
 * Input
 * The input consists of one line with a string consisting of at least 11 and at most 100000100000 characters.
 * A preprocessing step has already transformed all whitespace characters to underscores (_),
 * and the line will consist solely of characters with ASCII codes between 33 and 126 (inclusive).
 *
 * Output
 * Output four lines, containing the ratios of whitespace characters, lowercase letters, uppercase letters, and symbols (in that order).
 * Your answer should have an absolute or relative error of at most 10e−6.
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	string str;
	getline(cin, str);
	int whitespaces, lowercase_letters, uppercase_letters, symbols;
	whitespaces = lowercase_letters = uppercase_letters = symbols = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '_') {
			whitespaces++;
		} else if (str[i] >= 'a' && str[i] <= 'z') {
			lowercase_letters++;
		} else if (str[i] >= 'A' && str[i] <= 'Z') {
			uppercase_letters++;
		} else {
			symbols++;
		}
	}

	double float_str_length = static_cast<double>(str.length());

	double ratio = static_cast<double>( whitespaces ) / float_str_length;
	cout << setprecision(15) << ratio << endl;

	ratio = static_cast<double>( lowercase_letters ) / float_str_length;
	cout << setprecision(15) << ratio << endl;

	ratio = static_cast<double>( uppercase_letters ) / float_str_length;
	cout << setprecision(15) << ratio << endl;

	ratio = static_cast<double>( symbols ) / float_str_length;
	cout << setprecision(15) << ratio << endl;

	return 0;
}
