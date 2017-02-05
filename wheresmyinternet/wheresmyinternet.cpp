// https://open.kattis.com/problems/wheresmyinternet
// See also https://en.wikipedia.org/wiki/Disjoint-set_data_structure

#include <iostream>
#include <vector>

using namespace std;

// Using modification of the union-find (disjoint-set) data structure
struct union_find {
	vector<int> parent; // vector to quickly find representative item of the set

	// Creates new union-find set
	union_find(int n) {
		parent = vector<int>(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i; 	// Creates trivial set of only one element
		}
	}

	// Returns an item from this set that serves as its "representative"
	int find(int x) {
		if (parent[x] == x) {
			return x;
		} else {
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}

	// Unites the set which contains x and the set which contains y in such a way
	// that new set representative will be the smallest one of x representative and y representative
	// E.g., x belongs to set with representative xp, y belongs to set with representative yp; xp < yp, so we assume xp
	// as representative of newly created set
	void unite(int x, int y) {
		int xp = find(x), yp = find(y);
		if (xp < yp) {
			parent[yp] = xp;
		} else {
			parent[xp] = yp;
		}
	}
};

int main(void) {
	int N, M; // number of houses and number of cables already deployed
	cin >> N >> M;

	union_find net(N); // our net :)

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		net.unite(a - 1, b - 1); // create connection between a and b
		
/* debug print		
		cout << a << " " << b << endl;
		for (int i = 0; i < N; i++) {
			cout << i + 1 << " ";
		}
		cout << endl;
		for (int i = 0; i < N; i++) {
			cout << net.parent[i] + 1 << " ";
		}
		cout << endl;
*/
	}

	bool not_connected_found = false;
	for (int i = 0; i < N; i++) {
		if (net.find(i) != 0) {
			not_connected_found = true;
			cout << i + 1 << endl;
		}
	}

	if (!not_connected_found) {
		cout << "Connected" << endl;
	}

	return 0;
}
