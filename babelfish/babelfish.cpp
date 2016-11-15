// https://open.kattis.com/problems/babelfish

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void) {
	map<string, string> dict;
	string str;
	bool reading_dict = true;
	while (getline(cin, str)) {
		if (str == "") {
			reading_dict = false;
			continue;
		}
		
		if (reading_dict) {
			string english_word, foreign_word;
			size_t space_pos = str.find_first_of(" ");
			english_word = str.substr(0, space_pos);
			foreign_word = str.substr(space_pos + 1, str.length() - space_pos);
			dict.insert( make_pair(foreign_word, english_word) );
		} else {
			string translation;
			if (!dict.count(str)) {
				translation = "eh";
			} else {
				translation = dict[str];
			}
			cout << translation << endl;
		}
	}
	return 0;
}
