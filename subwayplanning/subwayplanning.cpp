// https://open.kattis.com/problems/subwayplanning
#include <iostream>
#include <vector>
#include <cmath> // sqrt

using namespace std;

struct Point {
	double x;
	double y;
};

// Get vectors v1 and v2 dot product
double dot_product(Point v1, Point v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

// Get average point between p1 and p2 points
Point avg_point(Point p1, Point p2) {
	Point result = {
		(p1.x + p2.x) / 2,
		(p1.y + p2.y) / 2
	};
	return result;
}

// Get distance from point (x0; y0) to line passing through O(0; 0) and p1
double euclidean_length_from_point_to_line(Point p1, double x0, double y0) {
	Point p2 = { 0, 0 };
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	
	double result = abs( dy * x0 - dx * y0 + p2.x * p1.y - p2.y * p1.x );
	result /= sqrt( dy * dy + dx * dx );
	return result;
}

int main(void) {
	int datasets_count;
	cin >> datasets_count;

	int u = 0;
	while (datasets_count--) {
		int n, d; // n is number of the most important city places, d is max distance from line to place
		cin >> n >> d;

		// Initially we have per one line for each place
		// The task is to merge multiple line into single one if possible
		vector<Point> lines(n); // array of n the most imporant city places <=> array of lines
		for (int i = 0; i < n; i++) {
			cin >> lines[i].x >> lines[i].y;
		}

		vector<Point>::iterator i = lines.begin();
		while (i != lines.end()) {
			vector<Point>::iterator line_to_merge_with = lines.end();
			Point avg_to_merge;
			double mindist = -1;
			bool do_merge = false;
			for (vector<Point>::iterator j = lines.begin(); j != lines.end(); ++j) {
				// Skip the same point; skip multidirectional points
				if ( (i == j) || (dot_product(*i, *j) < 0) ) {
					continue;
				}

				Point line_ij = avg_point(*i, *j);
				double dist_this = euclidean_length_from_point_to_line(line_ij, j->x, j->y);

				if (dist_this <= d && ( line_to_merge_with == lines.end() || dist_this < mindist )) {
					line_to_merge_with = j;
					mindist = dist_this;
					avg_to_merge = line_ij;
					do_merge = true;
				}
				//cout << "i: (" << i->x << "; " << i->y << "),\t j: (" << j->x << "; " << j->y << "),\t dist:" << dist_this << ", mindist: " << mindist << endl; 
			}

			if (do_merge) {
				// Merging
				*i = avg_to_merge;
				lines.erase(line_to_merge_with);
				//cout << "Now lines count: " << lines.size() << ", merged, new i: (" << i->x << ", " << i->y << ")" << endl;
			} else {
				// Searching for the next line
				i++;
			}
		}

		// Result: minimum lines count
		cout << lines.size() << endl;
	}

	return 0;
}
