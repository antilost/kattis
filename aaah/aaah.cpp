// https://open.kattis.com/problems/aaah

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string marius_able_to_say, doctor_wants_to_say;

	getline(cin, marius_able_to_say);
	getline(cin, doctor_wants_to_say);

	string result = ( marius_able_to_say.length() >= doctor_wants_to_say.length() )
		? "go"
		: "no";

	cout <<  result << endl;

	return 0;
}