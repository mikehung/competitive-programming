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

const int NMAX = 100000 + 5, PMAX = 1000000 + 5;
int n, a, b;
pair<int, int> Pair[NMAX];
int fire[NMAX][2], dest[NMAX][2];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &Pair[i].first, &Pair[i].second);
	}
	// 0: pos, 1: cnt
	sort(Pair, Pair+n);
	fire[n-1][0] = Pair[n-1].first - Pair[n-1].second;
	fire[n-1][1] = 0;
	dest[n-1][0] = PMAX;
	dest[n-1][1] = 1;
	for (int i = n-2; i >= 0; --i) {
		fire[i][0] = fire[i][1] = dest[i][0] = dest[i][1] = PMAX;
		if (Pair[i].first < fire[i+1][0] || Pair[i].first < dest[i+1][0]) {
			fire[i][0] = Pair[i].first - Pair[i].second;
			if (Pair[i].first < fire[i+1][0])
				fire[i][1] = fire[i+1][1];
			if (Pair[i].first < dest[i+1][0])
				fire[i][1] = min(fire[i][1], dest[i+1][1]);
		}
		if (Pair[i].first >= fire[i+1][0] && Pair[i].first >= dest[i+1][0]) {
			if (fire[i+1][1] < dest[i+1][1]) {
				dest[i][0] = fire[i+1][0];
				dest[i][1] = fire[i+1][1] + 1;
			} else if (fire[i+1][1] > dest[i+1][1]) {
				dest[i][0] = dest[i+1][0];
				dest[i][1] = dest[i+1][1] + 1;
			} else {
				dest[i][0] = max(fire[i+1][0], dest[i+1][0]);
				dest[i][1] = dest[i+1][1] + 1;
			}
		} else if (Pair[i].first >= fire[i+1][0]) {
			dest[i][0] = fire[i+1][0];
			dest[i][1] = fire[i+1][1] + 1;
		} else if (Pair[i].first >= dest[i+1][0]) {
			dest[i][0] = dest[i+1][0];
			dest[i][1] = dest[i+1][1] + 1;
		} else {
			dest[i][0] = dest[i+1][0];
			dest[i][1] = n-i;
		}
	}
	printf("%d\n", min(fire[0][1], dest[0][1]));

	return 0;
}
// Time: O(), Space: O()
