// https://open.kattis.com/problems/permutationencryption

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	while (true) {
		int key_length;
		cin >> key_length;
		if (key_length == 0) {
			break;
		}

		vector<int> key(key_length);
		for (int i = 0; i < key_length; i++) {
			cin >> key[i];
		}

		string orig_message;
		getline(cin, orig_message); // skip end line
		getline(cin, orig_message);

		int initial_length = orig_message.length();
		if (initial_length % key_length > 0) {
			for (int i = 0; i < ( key_length - (initial_length % key_length) ); i++) {
				orig_message += " ";
			}
		}

		cout << "'";
		for (int i = 0; i < orig_message.length(); i++) {
			int m = i % key_length;
			int f = i - m;
			cout << orig_message[ f + key[m] - 1 ];
		}
		cout << "'" << endl;
	}

	return 0;
}