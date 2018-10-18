#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n, m, q, x, y;
	cin >> n >> m >> q;
	vector<vector<int>> board(n, vector<int>(m));
	vector<int> max_eyes(n);
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> board[r][c];
		}
	}
	for (int r = 0; r < n; ++r) {
		int j = -1;
		for (int i = 0; i < m; ++i) {
			if (!board[r][i])
				j = i;
			else
				max_eyes[r] = max(max_eyes[r], i-j);
		}
	}
	for (int i = 0; i < q; ++i) {
		cin >> x >> y;
		--x, --y;
		board[x][y] = 1 - board[x][y];
		int j = -1;
		max_eyes[x] = 0;
		for (int i = 0; i < m; ++i) {
			if (!board[x][i])
				j = i;
			else
				max_eyes[x] = max(max_eyes[x], i-j);
		}
		cout << *max_element(max_eyes.begin(), max_eyes.end()) << '\n';
	}

	return 0;
}
// Time: O(nm+q(n+m)), Space: O(nm)
