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
	int N, Q;
	cin >> N >> Q;
	union_find net(N);

	int x, y, xp, yp;
	char operation;
	for (int i = 0; i < Q; i++) {
		cin >> operation >> x >> y;
		if (operation == '=') {
			net.unite(x, y); // create connection between a and b
		} else {
			xp = net.find(x);
			yp = net.find(y);
			cout << (xp == yp ? "yes" : "no") << endl;
		}
	}

	return 0;
}
