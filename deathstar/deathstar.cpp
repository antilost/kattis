#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	int G[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
		}
	}

	int K[n];
	for (int i = 0; i < n; i++) {
		K[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			K[i] |= G[i][j];
			K[j] |= G[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		cout << K[i] << " ";
	}
	cout << K[n - 1] << endl;

	return 0;
}