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
#include <climits>
using namespace std;

#ifdef DEBUG
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;
int n, m;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, x, y;
	cin >> n >> m >> k;
	vector<pii> points;
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	int max_dis = -1, max_r = 1, max_c = 1, dis;
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= m; ++c) {
			dis = INT_MAX;
			for (auto &point : points) {
				dis = min(dis, abs(point.first-r) + abs(point.second-c));
			}
			if (dis > max_dis) {
				max_r = r;
				max_c = c;
				max_dis = dis;
			}
		}
	}
	cout << max_r << ' ' << max_c << '\n';

	return 0;
}
// Time: O(nmk), Space: O(k)
