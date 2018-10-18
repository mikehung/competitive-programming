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

const int NMAX = 5005;
int n, m, k;
pair<int, int> row[NMAX], col[NMAX];

int main()
{
	int d, x, a;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> d >> x >> a;
		if (d == 1)
			row[x] = make_pair(a, i);
		else
			col[x] = make_pair(a, i);
	}
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= m; ++c) {
			a = 0;
			if (row[r].second)
				a = row[r].first;
			if (col[c].second > row[r].second)
				a = col[c].first;
			cout << a << ' ';
		}
		cout << '\n';
	}
	return 0;
}
// Time: O(m*n+k), Space: O(m+n)
