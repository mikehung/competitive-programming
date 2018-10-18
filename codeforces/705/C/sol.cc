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
	int n, q, cnt = 0, firstN = 0;
	vector<bool> msg;
	map<int, vector<int>> app;

	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; ++i) {
		int t, x;
		scanf("%d %d", &t, &x);
		if (t == 1) {
			app[x].push_back(msg.size());
			msg.push_back(false);
			++cnt;
		} else if (t == 2) {
			auto it = lower_bound(app[x].begin(), app[x].end(), firstN);
			for (; it != app[x].end(); ++it) {
				msg[*it] = true;
				--cnt;
			}
			app[x].clear();
		} else {
			for (auto aid = firstN; aid < x; ++aid) {
				if (!msg[aid]) {
					msg[aid] = true;
					--cnt;
				}
			}
			if (x > firstN)
				firstN = x;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
// Time: O(), Space: O()
