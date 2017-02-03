#include <iostream>
//#include <iomanip>
using namespace std;

const int N = 4;

void print_state (int g[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++)
//			cout << setw(5) << g[i][j] << " ";
			cout << g[i][j] << " ";
		cout << g[i][N - 1] << endl;
	}
}

void slide_left (int g[N][N]) {
	for (int i = 0; i < N; i++) {
		int k = 0;
		bool joined = false;
		for (int j = 0; j < N; j++) {
			int value = g[i][j];
			g[i][j] = 0;
			if (value != 0) {
				if (k > 0 && g[i][k - 1] == value && !joined) {
					g[i][k - 1] = 2 * value;
					joined = true;
				} else {
					g[i][k] = value;
					k++;
					joined = false;
				}
			}
		}
	}
}

void slide_right (int g[N][N]) {
	for (int i = 0; i < N; i++) {
		int k = N - 1;
		bool joined = false;
		for (int j = N - 1; j >= 0; j--) {
			int value = g[i][j];
			g[i][j] = 0;
			if (value != 0) {
				if (k < N - 1 && g[i][k + 1] == value && !joined) {
					g[i][k + 1] = 2 * value;
					joined = true;
				} else {
					g[i][k] = value;
					k--	;
					joined = false;
				}
			}
		}
	}
}

void slide_up (int g[N][N]) {
	for (int j = 0; j < N; j++) {
		int k = 0;
		bool joined = false;
		for (int i = 0; i < N; i++) {
			int value = g[i][j];
			g[i][j] = 0;
			if (value != 0) {
				if (k > 0 && g[k - 1][j] == value && !joined) {
					g[k - 1][j] = 2 * value;
					joined = true;
				} else {
					g[k][j] = value;
					k++;
					joined = false;
				}
			}
		}
	}
}

void slide_down (int g[N][N]) {
	for (int j = 0; j < N; j++) {
		int k = N - 1;
		bool joined = false;
		for (int i = N - 1; i >= 0; i--) {
			int value = g[i][j];
			g[i][j] = 0;
			if (value != 0) {
				if (k < N - 1 && g[k + 1][j] == value && !joined) {
					g[k + 1][j] = 2 * value;
					joined = true;
				} else {
					g[k][j] = value;
					k--;
					joined = false;
				}
			}
		}
	}
}

int main(void) {
	int g[N][N];

	// read g
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> g[i][j];

	// read slide direction: 0, 1, 2, or 3 that denotes a left, up, right, or down
	int slide;
	cin >> slide;

	//cout << "Initial state" << endl;
	//print_state(g);

	//cout << endl << "Slide: " << slide << endl << endl;
	
	switch (slide) {
		case 0:
			slide_left(g);
			break;
		case 1:
			slide_up(g);
			break;
		case 2:
			slide_right(g);
			break;
		case 3:
			slide_down(g);
			break;
	}
	
	//cout << "Final state" << endl;
	print_state(g);
	return 0;
}