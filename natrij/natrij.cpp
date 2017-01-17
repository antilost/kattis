// https://open.kattis.com/problems/natrij

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int get_seconds_from_str_time(string str_time) {
	// str_time HH:MM:SS
	return 60 * ( 60 * stoi( str_time.substr(0, 2) ) + stoi( str_time.substr(3, 2) ) ) + stoi( str_time.substr(6, 2) );
}

int main(void) {
	string str_time_now, str_time_explosion;
	getline(cin, str_time_now);
	getline(cin, str_time_explosion);

	int secs_now = get_seconds_from_str_time(str_time_now);
	int secs_explosion = get_seconds_from_str_time(str_time_explosion);
	
	if (secs_explosion <= secs_now) {
		secs_explosion += 24 * 60 * 60;
	}
	int secs_diff = secs_explosion - secs_now;

	int dh = secs_diff / (60 * 60);
	int dm = (secs_diff - 60 * 60 * dh ) / 60;
	int ds = secs_diff % 60;
	cout << setfill('0') << setw(2) << dh << ":" << setw(2) << dm << ":" << setw(2) << ds << endl;
	
	return 0;
}