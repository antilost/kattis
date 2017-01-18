// https://open.kattis.com/problems/pathtracing

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // setfill, setw
#include <cstring> // memset
#include <cassert> // assert

using namespace std;


int get_offset (const int, const int, const int, const int, const pair<int, int>);

int main(void) {
	// Process input
	vector< pair<int, int> > path;
	string direction;
	path.push_back( make_pair(0, 0) ); // Add start point

	int max_up, max_down, max_right, max_left;
	max_up = max_down = max_right = max_left = 0;
	while (getline(cin, direction)) {
		// Get new point coordinates
		int x = path.back().first;
		int y = path.back().second;
		if (direction == "down") {
			y -= 1;
			if (y < max_down) {
				max_down = y;
			}
		} else if (direction == "up") {
			y += 1;
			if (y > max_up) {
				max_up = y;
			}
		} else if (direction == "right") {
			x += 1;
			if (x > max_right) {
				max_right = x;
			}
		} else if (direction == "left") {
			x -= 1;
			if (x < max_left) {
				max_left = x;
			}
		} else {
			assert(1 != 1);
		}

		path.push_back( make_pair( x, y ) ); // Add new point

		//cout << path.back().first << " " << path.back().second << endl;
	}
	
	// Get final dimensions
	int w, h;
	w = max_right - max_left + 1;
	h = max_up - max_down + 1;

	//cout << "LR: " << max_left << ":" << max_right << ", w: " << w << endl;
	//cout << "UD: " << max_down << ":" << max_up << ", h: " << h << endl;
	
	// Fill matrix to print result map
	char map[w * h];
	memset(map, ' ', w * h);
	for (vector< pair<int, int> >::iterator i = path.begin(); i < path.end(); i++) {
		map[ get_offset(max_left, max_up, w, h, *i) ] = '*';
	}
	map[ get_offset(max_left, max_up, w, h, path.front()) ] = 'S';
	map[ get_offset(max_left, max_up, w, h, path.back()) ] = 'E';

	// Print result map
	cout << setfill('#') << setw(w + 2) << "" << endl;
	for (int i = 0; i < h; i++) {
		cout << "#";
		for (int j = 0; j < w; j++) {
			cout << map[ i * w + j ];
		}
		cout << "#" << endl;
	}
	cout << setfill('#') << setw(w + 2) << "" << endl;

	return 0;
}

int get_offset (const int max_left, const int max_up, const int w, const int h, const pair<int, int> p) {
	int i = p.first - max_left, j = -p.second + max_up;
	
	int res = j * w + i;
//	cout << "(" << p.first << "; " << p.second << ") to (" << i << "; " << j << ") = " << res << endl;

	return res;
}