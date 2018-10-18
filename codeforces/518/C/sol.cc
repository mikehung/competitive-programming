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

int main()
{
	int n, m, k, a, cur;
	cin >> n >> m >> k;

	vector<int> screen(n), apps(n+1);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		screen[i] = a;
		apps[a] = i;
	}
	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		cur = apps[a];
		ans += cur / k + 1;
		if (cur) {
			swap(screen[cur-1], screen[cur]);
			swap(apps[screen[cur-1]], apps[screen[cur]]);
		}
	}
	cout << ans << '\n';
	return 0;
}
// Time: O(n+m), Space: O(n)
