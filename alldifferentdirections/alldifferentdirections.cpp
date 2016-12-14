#include <iostream>
#include <iomanip> // fixed, setprecision
#include <string>
#include <cstdlib> // atof
#include <cmath>   // sin, cos

struct Point {
	double x, y;
};

using namespace std;

int main(void) {
	do {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		string str;
		getline(cin, str); // to skip line with directions count

		Point all_dst[n], avg_dst;
		avg_dst.x = avg_dst.y = 0;
		for (int i = 0; i < n; i++) {
			getline(cin, str);

			int pos = 0, pos_space = str.find(" ", pos);
			all_dst[i].x = atof( str.substr(pos, pos_space - pos).c_str() );

			pos = pos_space + 1; pos_space = str.find(" ", pos);
			all_dst[i].y = atof( str.substr(pos, pos_space - pos).c_str() );
			
			pos = pos_space + 1; pos_space = str.find(" ", pos); // skip start
			pos = pos_space + 1; pos_space = str.find(" ", pos);
			double angle = atof( str.substr(pos, pos_space - pos).c_str() );

			while (pos_space > 0) {
				pos = pos_space + 1; pos_space = str.find(" ", pos);
				string cmd = str.substr(pos, pos_space - pos);

				pos = pos_space + 1; pos_space = str.find(" ", pos);
				double diff = atof( str.substr(pos, pos_space - pos).c_str() );
				
				if (cmd == "turn") {
					angle += diff;
				} else if (cmd == "walk") {
					double dx = diff * cos(angle / 180.0 * M_PI);
					double dy = diff * sin(angle / 180.0 * M_PI);
					all_dst[i].x += dx;
					all_dst[i].y += dy;
				}
			}

			avg_dst.x += all_dst[i].x;
			avg_dst.y += all_dst[i].y;
		}

		avg_dst.x /= n;
		avg_dst.y /= n;

		double worst_diff = 0;
		for (int i = 0; i < n; i++) {
			double dx = all_dst[i].x - avg_dst.x;
			double dy = all_dst[i].y - avg_dst.y;
			double this_diff = sqrt( dx*dx + dy*dy );
//			cout << fixed << setprecision(4) << k++ << " " << it->x << " " << it->y << " " << this_diff << " " << worst_diff << endl;

			if (this_diff > worst_diff) {
				worst_diff = this_diff;
			}
		}

		cout << fixed << setprecision(6) << avg_dst.x << " " << avg_dst.y << " " << worst_diff << endl;
	} while (true);

	return 0;
}
