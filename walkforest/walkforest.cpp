#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
using namespace std;

const int N = 1000;
const int v_to_find = 1;

int n, m;
vector<int> E[N];
vector<int> W[N];
int D[N];
long long F[N];


long long get_paths_count(int v_cur) {
	if (v_cur == v_to_find) {
		return 1;
	}

	long long &result = F[v_cur];
	if (result == -1) {
		result = 0;
		for (int i = 0; i < E[v_cur].size(); i++) {
			int v_next = E[v_cur][i];
			if (D[v_next] != -1 && D[v_next] < D[v_cur]) {
				F[v_cur] += get_paths_count(v_next);
			}
		}
	}
	
	return result;
}

void dijkstra(void) {
	memset(&D, -1, sizeof(D));

	priority_queue< pair<int, int> > Q;
	Q.push( make_pair(0, 1) );

	while (!Q.empty()) {
		int v_cur = Q.top().second;
		int d_cur = -Q.top().first;
		Q.pop();
		
		if (D[v_cur] != -1) {
			continue;
		}
		
		D[v_cur] = d_cur;
		for (int i = 0; i < E[v_cur].size(); i++) {
			int v_next = E[v_cur][i];
			int w_i = W[v_cur][i];
			if (D[v_next] != -1) {
				continue;
			}
			Q.push( make_pair( -d_cur-w_i, v_next ) );
		}
	}
}

int main(void) {
	while (cin >> n >> m) {
		for (int i = 0; i < N; i++) {
			E[i].clear();
			W[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			x--; y--;
			E[x].push_back(y);
			W[x].push_back(w);
			E[y].push_back(x);
			W[y].push_back(w);
		}

		dijkstra();
		memset(F, -1, sizeof(F));
		cout << get_paths_count(0) << endl;
	}
	return 0;
}